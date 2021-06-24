#ifndef LAYOUT_H
#define LAYOUT_H
#include <stdint.h>
#include "keys.h"

#define NUM_ROWS 8
#define NUM_COLS 16
#define B_OFFSET 4  // PORTB does not start at 0, 0-3 is used for ICSP
#define NUM_LAYERS 3
/*
 *
 *
 * . -----------------------------------------------------------------------------------------------------------------------------------.
 * | [Esc 15/25] [F1 13/14][F2 13/17][F3 13/18][F4 13/25][F5 16/17][F6 16/18][F7 16/25][F8 16/14][F9 4/17][F10 4/18][F11 4/25][F12 4/14]|
 * |                                                                                    [Scorr 9/25] [Pause 5/14] [Ins 2/25] [Canc 2/14]| 
 * |                                                                                                                                    |
 * | [\ 15/17][1 15/23][2 16/23][3 13/23][4 12/23][5 12/17][6 10/17][7 10/23][8 9/23][9 4/23][0 3/23][' 3/17][ì 3/14]  [< 5/25] [H 2/18]|
 * | [|- 15/18][Q 15/24][W 16/24][E 13/24][R 12/24][T 12/18][Y 10/18][U 10/24][I 9/24][O 4/24][P 3/24][è 3/18][+ 9/18] |  5/21| [U 2/17]|
 * | [CAP 14/15][A 15/21][S 16/21][D 13/21][F 12/21][G 12/25][H 10/25][J 10/21][K 9/21][L 4/21][ò 3/21][à 3/25][ù 5/17]   |_  | [D 2/21]|
 * | [^ 20/22][< 9/17][Z 15/20][X 16/20][C 13/20][V 12/20][B 12/14][N 10/14][M 10/20][, 9/20][. 4/20][- 3/20] [^ 22/24] [^ 5/24][E 2/20]|
 * | [c 18/19][fn 11/17][W 8/25] [a 5/20][________________________][a 6/14] [ 7/17]   [c 19/21]                 [< 2/24][V 5/23][> 2/23]|
 * `------------------------------------------------------------------------------------------------------------------------------------'
 */
/*                3,                6,                9,               10,               12,               13,               14,               15,               16,               17,               18,               19,               20,               21,               22,               23 */
const uint16_t layout[NUM_LAYERS][NUM_ROWS][NUM_COLS] = {
{
/*  0 */ {               0,                0,           KEY_F7,          KEY_ESC,           KEY_F4,            KEY_G,                0,            KEY_H,   KEY_SCROLLLOCK,  KEY_MOD_WINDOWS | KEY_MOD_MACRO,                0,                0,    KEY_BACKSPACE,          KEY_F11,    KEY_IT_AGRAVE,       KEY_INSERT},
/*  1 */ {  KEY_MOD_RSHIFT | KEY_MOD_MACRO,                0,            KEY_W,            KEY_Q,            KEY_E,            KEY_R,                0,            KEY_U,            KEY_I,                0,                0,                0,           KEY_UP,            KEY_O,            KEY_P,         KEY_LEFT},
/*  2 */ {               0,                0,            KEY_2,            KEY_1,            KEY_3,            KEY_4,                0,            KEY_7,            KEY_8,                0,                0,     KEY_MOD_LALT | KEY_MOD_MACRO,         KEY_DOWN,            KEY_9,            KEY_0,        KEY_RIGHT},
/*  4 */ {               0,    KEY_MOD_RCTRL | KEY_MOD_MACRO,            KEY_S,            KEY_A,            KEY_D,            KEY_F,                0,            KEY_J,            KEY_K,                0,                0,                0,       KEY_ENTER,            KEY_L,    KEY_IT_OGRAVE,     KEY_PAGEDOWN},
/*  5 */ {  KEY_MOD_LSHIFT | KEY_MOD_MACRO,                0,            KEY_X,            KEY_Z,            KEY_C,            KEY_V,                0,            KEY_M,        KEY_COMMA,                0,                0,                0,     KEY_SPACEBAR,          KEY_DOT,        KEY_MINUS,          KEY_END},
/*  7 */ {               0,    KEY_MOD_LCTRL | KEY_MOD_MACRO,           KEY_F6,          KEY_TAB,           KEY_F3,            KEY_T,                0,            KEY_Y,      KEY_IT_PLUS,                0,                0,                0,                0,          KEY_F10,    KEY_IT_EGRAVE,         KEY_HOME},
/*  8 */ {               0,                0,           KEY_F5,    KEY_BACKSLASH,           KEY_F2,            KEY_5,    KEY_MOD_LMETA,            KEY_6,  KEY_IT_TRIANGLE,                0,          KEY_BOH,                0,    KEY_IT_UGRAVE,           KEY_F9,   KEY_APOSTROPHE,       KEY_PAGEUP},
/* 11 */ {               0,                0,           KEY_F8,     KEY_CAPSLOCK,           KEY_F1,            KEY_B,                0,            KEY_N,                0,                0,                0,     KEY_MOD_RALT | KEY_MOD_MACRO,        KEY_PAUSE,          KEY_F12,    KEY_IT_IGRAVE,       KEY_DELETE},
},
{
/*  0 */ {               0,                0,           KEY_F7,          KEY_ESC,           KEY_F4,            KEY_G,                0,            KEY_H,   KEY_SCROLLLOCK,  KEY_MOD_WINDOWS,                0,                0,    KEY_BACKSPACE,          KEY_F11,    KEY_IT_AGRAVE,       KEY_INSERT},
/*  1 */ {  KEY_MOD_RSHIFT,                0,            KEY_W,            KEY_Q,            KEY_E,            KEY_R,                0,            KEY_U,            KEY_I,                0,                0,                0,           KEY_UP,            KEY_O,            KEY_P,         KEY_LEFT},
/*  2 */ {               0,                0,            KEY_2,            KEY_1,            KEY_3,            KEY_4,                0,            KEY_7,            KEY_8,                0,                0,     KEY_MOD_LALT,         KEY_DOWN,            KEY_9,            KEY_0,        KEY_RIGHT},
/*  4 */ {               0,    KEY_MOD_RCTRL,            KEY_S,            KEY_A,            KEY_D,            KEY_F,                0,            KEY_J,            KEY_K,                0,                0,                0,       KEY_ENTER,            KEY_L,    KEY_IT_OGRAVE,     KEY_PAGEDOWN},
/*  5 */ {  KEY_MOD_LSHIFT,                0,            KEY_X,            KEY_Z,            KEY_C,            KEY_V,                0,            KEY_M,        KEY_COMMA,                0,                0,                0,     KEY_SPACEBAR,          KEY_DOT,        KEY_MINUS,          KEY_END},
/*  7 */ {               0,    KEY_MOD_LCTRL,           KEY_F6,          KEY_TAB,           KEY_F3,            KEY_T,                0,            KEY_Y,      KEY_IT_PLUS,                0,                0,                0,                0,          KEY_F10,    KEY_IT_EGRAVE,         KEY_HOME},
/*  8 */ {               0,                0,           KEY_F5,    KEY_BACKSLASH,           KEY_F2,            KEY_5,    KEY_MOD_LMETA,            KEY_6,  KEY_IT_TRIANGLE,                0,          KEY_BOH,                0,    KEY_IT_UGRAVE,           KEY_F9,   KEY_APOSTROPHE,       KEY_PAGEUP},
/* 11 */ {               0,                0,           KEY_F8,     KEY_CAPSLOCK,           KEY_F1,            KEY_B,                0,            KEY_N,                0,                0,                0,     KEY_MOD_RALT,        KEY_PAUSE,          KEY_F12,    KEY_IT_IGRAVE,       KEY_DELETE},
},
{
/*  0 */ {               0,                0,           KEY_F7,          KEY_ESC,           KEY_F4,            KEY_G,                0,            KEY_H,   KEY_SCROLLLOCK,  KEY_MOD_WINDOWS,                0,                0,    KEY_BACKSPACE,          KEY_F11,    KEY_IT_AGRAVE,       KEY_INSERT},
/*  1 */ {  KEY_MOD_RSHIFT,                0,            KEY_W,            KEY_Q,            KEY_E,            KEY_R,                0,            KEY_U,            KEY_I,                0,                0,                0,           KEY_UP,            KEY_O,            KEY_P,         KEY_LEFT},
/*  2 */ {               0,                0,            KEY_2,            KEY_1,            KEY_3,            KEY_4,                0,            KEY_7,            KEY_8,                0,                0,     KEY_MOD_LALT,         KEY_DOWN,            KEY_9,            KEY_0,        KEY_RIGHT},
/*  4 */ {               0,    KEY_MOD_RCTRL,            KEY_S,            KEY_A,            KEY_D,            KEY_F,                0,            KEY_J,            KEY_K,                0,                0,                0,       KEY_ENTER,            KEY_L,    KEY_IT_OGRAVE,     KEY_PAGEDOWN},
/*  5 */ {  KEY_MOD_LSHIFT,                0,            KEY_X,            KEY_Z,            KEY_C,            KEY_V,                0,            KEY_M,        KEY_COMMA,                0,                0,                0,     KEY_SPACEBAR,          KEY_DOT,        KEY_MINUS,          KEY_END},
/*  7 */ {               0,    KEY_MOD_LCTRL,           KEY_F6,          KEY_TAB,           KEY_F3,            KEY_T,                0,            KEY_Y,      KEY_IT_PLUS,                0,                0,                0,                0,          KEY_F10,    KEY_IT_EGRAVE,         KEY_HOME},
/*  8 */ {               0,                0,           KEY_F5,    KEY_BACKSLASH,           KEY_F2,            KEY_5,    KEY_MOD_LMETA,            KEY_6,  KEY_IT_TRIANGLE,                0,          KEY_BOH,                0,    KEY_IT_UGRAVE,           KEY_F9,   KEY_APOSTROPHE,       KEY_PAGEUP},
/* 11 */ {               0,                0,           KEY_F8,     KEY_CAPSLOCK,           KEY_F1,            KEY_B,                0,            KEY_N,                0,                0,                0,     KEY_MOD_RALT,        KEY_PAUSE,          KEY_F12,    KEY_IT_IGRAVE,       KEY_DELETE},
}};
#if 0
const uint16_t layout[NUM_LAYERS][NUM_ROWS][NUM_COLS] = {
    {
                 /*               2               3        4             5             6              7      8               9     10             11     12      13             15      16             19              22 */  
        /* PD0 14 */ {   KEY_DELETE,  KEY_IT_IGRAVE, KEY_F12,    KEY_PAUSE, KEY_MOD_RALT,             0,     0,              0, KEY_N,             0, KEY_B, KEY_F1,  KEY_CAPSLOCK,      0,             0,              0},
        /* PD1 17 */ {   KEY_PAGEUP, KEY_APOSTROPHE,  KEY_F9,        KEY_U,            0, KEY_MOD_MACRO,     0,      KEY_COMMA, KEY_6, KEY_MOD_LMETA, KEY_5, KEY_F2, KEY_BACKSLASH, KEY_F5,             0,              0},
        /* PD2 18 */ {     KEY_HOME,      KEY_102ND, KEY_F10,            0,            0,             0,     0,    KEY_IT_PLUS, KEY_Y,             0, KEY_T, KEY_F3,       KEY_TAB, KEY_F6, KEY_MOD_LCTRL,              0},
        /* PD3 20 */ {      KEY_END,      KEY_MINUS, KEY_DOT, KEY_MOD_LALT,            0,             0,     0,      KEY_COMMA, KEY_M,             0, KEY_V,  KEY_C,         KEY_Z,  KEY_X,             0, KEY_MOD_LSHIFT},
        /* PD4 21 */ { KEY_PAGEDOWN,  KEY_IT_OGRAVE,   KEY_L,    KEY_ENTER,            0,             0,     0,          KEY_K, KEY_J,             0, KEY_F,  KEY_D,         KEY_A,  KEY_S, KEY_MOD_RCTRL,              0},
        /* PD5 23 */ {    KEY_RIGHT,          KEY_0,   KEY_9,     KEY_DOWN,            0,             0,     0,          KEY_8, KEY_7,             0, KEY_4,  KEY_3,         KEY_1,  KEY_2,             0,              0},
        /* PD6 24 */ {     KEY_LEFT,          KEY_P,   KEY_O,       KEY_UP,            0,             0,     0,          KEY_I, KEY_U,             0, KEY_R,  KEY_E,         KEY_Q,  KEY_W,             0, KEY_MOD_RSHIFT},
        /* PD7 25 */ {   KEY_INSERT,  KEY_IT_AGRAVE, KEY_F11,KEY_BACKSPACE,            0,             0, KEY_W, KEY_SCROLLLOCK, KEY_H,             0, KEY_G, KEY_F4,       KEY_ESC, KEY_F7,             0,              0},
    },
    {
                 /*         2               3        4             5             6              7      8               9     10             11     12      13             15      16             19              22 */  
        /* 14 */ { KEY_DELETE,  KEY_IT_IGRAVE, KEY_F12,    KEY_PAUSE, KEY_MOD_RALT,             0,     0,              0, KEY_N,             0, KEY_B, KEY_F1,  KEY_CAPSLOCK,      0,             0,              0},
        /* 17 */ { KEY_PAGEUP, KEY_APOSTROPHE,  KEY_F9,        KEY_U,            0, KEY_MOD_MACRO,     0,      KEY_COMMA, KEY_6, KEY_MOD_LMETA, KEY_5, KEY_F2, KEY_BACKSLASH, KEY_F5,             0,              0},
        /* 18 */ {   KEY_HOME,      KEY_102ND, KEY_F10,            0,            0,             0,     0,    KEY_IT_PLUS, KEY_Y,             0, KEY_T, KEY_F3,       KEY_TAB, KEY_F6, KEY_MOD_LCTRL,              0},
        /* 20 */ {    KEY_END,      KEY_MINUS, KEY_DOT, KEY_MOD_LALT,            0,             0,     0,      KEY_COMMA, KEY_M,             0, KEY_V,  KEY_C,         KEY_Z,  KEY_X,             0, KEY_MOD_LSHIFT},
        /* 21 */ {   KEY_DOWN,  KEY_IT_OGRAVE,   KEY_L,    KEY_ENTER,            0,             0,     0,          KEY_K, KEY_J,             0, KEY_F,  KEY_D,         KEY_A,  KEY_S, KEY_MOD_RCTRL,              0},
        /* 23 */ {  KEY_RIGHT,          KEY_0,   KEY_9,     KEY_DOWN,            0,             0,     0,          KEY_8, KEY_7,             0, KEY_4,  KEY_3,         KEY_1,  KEY_2,             0,              0},
        /* 24 */ {   KEY_LEFT,          KEY_P,   KEY_O,       KEY_UP,            0,             0,     0,          KEY_I, KEY_U,             0, KEY_R,  KEY_E,         KEY_Q,  KEY_W,             0, KEY_MOD_RSHIFT},
        /* 25 */ { KEY_INSERT,  KEY_IT_AGRAVE, KEY_F11,KEY_BACKSPACE,            0,             0, KEY_W, KEY_SCROLLLOCK, KEY_H,             0, KEY_G, KEY_F4,       KEY_ESC, KEY_F7,             0,              0},
    },
    {
                 /*         2               3        4             5             6              7      8               9     10             11     12      13             15      16             19              22 */  
        /* 14 */ { KEY_DELETE,  KEY_IT_IGRAVE, KEY_F12,    KEY_PAUSE, KEY_MOD_RALT,             0,     0,              0, KEY_N,             0, KEY_B, KEY_F1,  KEY_CAPSLOCK,      0,             0,              0},
        /* 17 */ { KEY_PAGEUP, KEY_APOSTROPHE,  KEY_F9,        KEY_U,            0, KEY_MOD_MACRO,     0,      KEY_COMMA, KEY_6, KEY_MOD_LMETA, KEY_5, KEY_F2, KEY_BACKSLASH, KEY_F5,             0,              0},
        /* 18 */ {   KEY_HOME,      KEY_102ND, KEY_F10,            0,            0,             0,     0,    KEY_IT_PLUS, KEY_Y,             0, KEY_T, KEY_F3,       KEY_TAB, KEY_F6, KEY_MOD_LCTRL,              0},
        /* 20 */ {    KEY_END,      KEY_MINUS, KEY_DOT, KEY_MOD_LALT,            0,             0,     0,      KEY_COMMA, KEY_M,             0, KEY_V,  KEY_C,         KEY_Z,  KEY_X,             0, KEY_MOD_LSHIFT},
        /* 21 */ {   KEY_DOWN,  KEY_IT_OGRAVE,   KEY_L,    KEY_ENTER,            0,             0,     0,          KEY_K, KEY_J,             0, KEY_F,  KEY_D,         KEY_A,  KEY_S, KEY_MOD_RCTRL,              0},
        /* 23 */ {  KEY_RIGHT,          KEY_0,   KEY_9,     KEY_DOWN,            0,             0,     0,          KEY_8, KEY_7,             0, KEY_4,  KEY_3,         KEY_1,  KEY_2,             0,              0},
        /* 24 */ {   KEY_LEFT,          KEY_P,   KEY_O,       KEY_UP,            0,             0,     0,          KEY_I, KEY_U,             0, KEY_R,  KEY_E,         KEY_Q,  KEY_W,             0, KEY_MOD_RSHIFT},
        /* 25 */ { KEY_INSERT,  KEY_IT_AGRAVE, KEY_F11,KEY_BACKSPACE,            0,             0, KEY_W, KEY_SCROLLLOCK, KEY_H,             0, KEY_G, KEY_F4,       KEY_ESC, KEY_F7,             0,              0},
    },
};
#endif

/* Standard QWERTY Layout
const uint16_t layout[3][4][12] = {
    {// Layer 0 - Standard layout
     {KEY_ESC, KEY_Q, KEY_W, KEY_E, KEY_R, KEY_T, KEY_Y, KEY_U, KEY_I, KEY_O,
      KEY_P, KEY_BACKSPACE},
     {KEY_TAB, KEY_A, KEY_S, KEY_D, KEY_F, KEY_G, KEY_H, KEY_J, KEY_K, KEY_L,
      KEY_SEMICOLON, KEY_APOSTROPHE},
     {KEY_MOD_LSHIFT | KEY_MOD_MACRO, KEY_Z, KEY_X, KEY_C, KEY_V, KEY_B, KEY_N,
      KEY_M, KEY_COMMA, KEY_DOT, KEY_SLASH, KEY_ENTER},
     {KEY_QUICK_FN | KEY_LS_MACRO, KEY_MOD_LCTRL | KEY_MOD_MACRO,
      KEY_MOD_LALT | KEY_MOD_MACRO, 0, 
      KEY_MOD_LMETA | KEY_MOD_MACRO, KEY_SPACE, KEY_SPACE, KEY_LAYER_UP | KEY_LS_MACRO, KEY_LEFT, KEY_UP,
      KEY_DOWN, KEY_RIGHT}},
    {// Layer 1 - Numbers and symbols
     {KEY_ESC, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9,
      KEY_0, KEY_BACKSPACE},
     {KEY_TAB, KEY_MINUS, KEY_EQUAL, KEY_BACKSLASH, KEY_LEFTBRACE,
      KEY_RIGHTBRACE, KEY_GRAVE, 0, 0, 0, 0, 0},
     {KEY_MOD_LSHIFT | KEY_MOD_MACRO, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, KEY_ENTER},
    
     {KEY_QUICK_FN | KEY_LS_MACRO, KEY_MOD_LCTRL | KEY_MOD_MACRO,
      KEY_MOD_LALT | KEY_MOD_MACRO, 0, 
      KEY_MOD_LMETA | KEY_MOD_MACRO, KEY_SPACE, KEY_SPACE, KEY_LAYER_UP | KEY_LS_MACRO, KEY_LEFT, KEY_UP,
      KEY_DOWN, KEY_RIGHT}},
		 {// Layer FN - Media, Volume, Brightness
     {KEY_ESC, KEY_F7, KEY_F8, KEY_F9, KEY_F11, KEY_F12, KEY_F10, KEY_F1,
      KEY_F2, 0, 0, KEY_BACKSPACE},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {KEY_QUICK_FN | KEY_LS_MACRO, KEY_MOD_LCTRL | KEY_MOD_MACRO,
      KEY_MOD_LALT | KEY_MOD_MACRO, 0, 
      KEY_MOD_LMETA | KEY_MOD_MACRO, KEY_SPACE, KEY_SPACE, KEY_LAYER_UP | KEY_LS_MACRO, KEY_LEFT, KEY_UP,
      KEY_DOWN, KEY_RIGHT}},
};*/
#endif
