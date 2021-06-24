/*
main.c
*/


#include <avr/io.h>
#include <string.h>
#include <util/delay.h>
#include "matrix.h"
#include "usb.h"

int main() {
  usb_init();

  while (!get_usb_config_status()) {
  }

  matrix_init();
  while(1)
      do_matrix_scan(); // Scan the matrix
}
