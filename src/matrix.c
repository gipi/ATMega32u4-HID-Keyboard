/*
 * matrix.c
 */
#include "matrix.h"
#include "layout.h"
#include "usb.h"
#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdbool.h>
#include <util/delay.h>

#define pin_output(x,y) DDR##x |= _BV(P##x##y);
#define pin_high(x,y) PORT##x |= _BV(P##x##y)
#define pin_low(x,y) PORT##x &= ~_BV(P##x##y)

#define port_output(port) DDR##port = 0xff
#define port_high(port) PORT##port = 0xff

inline void input_low(uint8_t pin) {
    PORTD &= ~_BV(pin);
}

inline void input_high(uint8_t pin) {
    PORTD |= _BV(pin);
}

#define SS_high() pin_high(B,0)
#define SS_low() pin_low(B,0)

#define DDR_SPI DDRB
#define DD_MOSI PB2
#define DD_MISO PB3
#define DD_SCK  PB1
#define DD_SS   PB0

void SPI_master_init() {
    /* Set MOSI, SS and SCK output, all others input */
    DDR_SPI = (1 << DD_MOSI) | (1 << DD_SCK) | (1 << DD_SS);
    /* Enable SPI, Master, set clock rate fck/16 */
    SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0); // | (1 << DORD);
}


/* while we transmit we also receive */
uint8_t SPI_masterTransmit(char cData)
{
    /* Start transmission */
    SPDR = cData;
    /* Wait for transmission complete */
    while(!(SPSR & (1 << SPIF)))
        ;

    return SPDR;
}

int layout_num = 0;
bool has_unsent_packets = false;

bool state_layer[NUM_ROWS][NUM_COLS] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};  // Key States to do state changes

void matrix_init() {
  SPI_master_init();
  SS_low(); // when low the shift registers are in LOAD mode
  port_output(D);
  port_high(D);

  TCCR0B |= (1 << CS00) | (1 << CS02); // Set up the 1024 prescaler on timer 0
  TCCR0A = (1 << WGM01); // Set the timer to compare mode
  OCR0A = 255; // Set the compare value to max for a lower frequency
  TIMSK0 = (1 << OCIE0A); // Enable timer compare interrupts
}

void do_layer_led() { PORTC = layout_num << 6; }

/*
 * Set the input pin to low.
 */
void enable_input(unsigned int j) {
    input_low(j);
}

void disable_input(unsigned int j) {
    input_high(j);
}
/*
 * Use the state of the button and identify the possible situation.
 */
void do_handle_keypress(bool state, unsigned int i, unsigned int j) {

    if (state != state_layer[i][j]) { // Is the value in the state array different from the value read from the key?
        if (!state) {  // Low to High (Key Down)

            uint16_t key = layout[layout_num][i][j];
            if (key & KEY_MOD_MACRO) { // Is this a macro key, in which case we have to set the appropriate value in the modifier bit
                key &= ~(KEY_MOD_MACRO);
                keyboard_modifier |= key;

            } else if (key & KEY_LS_MACRO) { // Is this a layer shift macro, in which case we have to change the layer number
                key &= ~(KEY_LS_MACRO);
                if ((layout_num | key) <= (NUM_LAYERS - 1)) { // Make sure we're not shifting to a layer that doesn't exist
                    layout_num |= key;
                    do_layer_led(); // Set the layer LEDs
                    for (int k = 0; k < 6; k++) {
                        keyboard_pressed_keys[k] = 0; // We have to clear the report after shifting layers because of conflicts from key-ups and key-downs on different layers
                    }
                }
            } else { // This is just a normal keypress, record it in the first available slot in the HID report 
                for (int k = 0; k < 6; k++) {
                    if (keyboard_pressed_keys[k] == 0) { // '0' is the code for no key press
                        keyboard_pressed_keys[k] = key; 
                        break;
                    }
                }
            }
        } else { // Handle key up events
            uint16_t key = layout[layout_num][i][j];
            if (key & KEY_MOD_MACRO) { // Is this a macro key, we have to remove the macro bit from the modifier byte to signify a key up
                key &= ~(KEY_MOD_MACRO);
                keyboard_modifier &= ~(key);

            } else if (key & KEY_LS_MACRO) { // Is this a layer shift key, we have to remove the bit from layout_num to switch back to the previous layer
                key &= ~(KEY_LS_MACRO);
                for (int k = 0; k < 6; k++) {
                    keyboard_pressed_keys[k] = 0; // Clear the HID report
                }
                layout_num &= ~(key);
                do_layer_led();
            } else {
                for (int k = 0; k < 6; k++) { // Normal key up event, find the key in the HID report and remove it
                    if (keyboard_pressed_keys[k] == key) {
                        keyboard_pressed_keys[k] = 0;
                    }
                }
            }
        }
        state_layer[i][j] = state; // Record the changed state in the array to register future state changes
        has_unsent_packets = true; // Let the timer interrupt know that we've got some packets to be sent
    }

}

/*
 * The matrix scan loops over the PORTB pins for the rows and read via SPI the
 * pins having asserted low signal.
 *
 */
void do_matrix_scan() {
    for (int row = 0; row < NUM_ROWS; row++) {
            enable_input(row);

            SS_high(); // enable shifting

            uint8_t c0 = SPI_masterTransmit(0x5a);
            uint8_t c1 = SPI_masterTransmit(0x5a);

            SS_low(); // re-enable loading
            disable_input(row);

            uint16_t c = c0 << 8 | c1;

            for (unsigned int column = 0; column < NUM_COLS; column++) {
                bool state = (c >> column) & 1;

                do_handle_keypress(state, row, column);
            }
    }
#if 0
            for (int k = 0; k < 6; k++) {
                if (keyboard_pressed_keys[k] == 0) { // '0' is the code for no key press
                    keyboard_pressed_keys[k] = KEY_A; 
                    break;
                }
            }
    has_unsent_packets = true; // Let the timer interrupt know that we've got some packets to be sent
#endif
}

ISR(TIMER0_COMPA_vect) { // The USB packets are sent on a timer interrupt because OSX was showing strange USB keypress rejection errors due to high USB packet frequency
  if (has_unsent_packets) {
    usb_send();
    has_unsent_packets = false;
  }
}
