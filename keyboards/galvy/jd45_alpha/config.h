#pragma once

#define MATRIX_ROWS 4
#define MATRIX_COLS 12

#define MATRIX_ROW_PINS { B7, F6, B6, C6 }
#define MATRIX_COL_PINS { E6, F0, F1, F4, F5, B0, B5, B4, D7, D6, D4, D3 }

#define DIODE_DIRECTION COL2ROW

#define DEBOUNCE 5

#define LOCKING_SUPPORT_ENABLE
#define LOCKING_RESYNC_ENABLE

// OLED
//#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"
//#define OLED_TIMEOUT 300000

// ENCODER
//#define ENCODERS_PAD_A { C6 }
//#define ENCODERS_PAD_B { C7 }
//#define ENCODER_RESOLUTION 4

// trackpoint
#ifdef PS2_DRIVER_USART
#define PS2_CLOCK_PIN   D5
#define PS2_DATA_PIN    D2

    /* synchronous, odd parity, 1-bit stop, 8-bit data, sample at falling edge */
    /* set DDR of CLOCK as input to be slave */
    #define PS2_USART_INIT() do {   \
        PS2_CLOCK_DDR &= ~(1<<PS2_CLOCK_BIT);   \
        PS2_DATA_DDR &= ~(1<<PS2_DATA_BIT);     \
        UCSR1C = ((1 << UMSEL10) |  \
                  (3 << UPM10)   |  \
                  (0 << USBS1)   |  \
                  (3 << UCSZ10)  |  \
                  (0 << UCPOL1));   \
        UCSR1A = 0;                 \
        UBRR1H = 0;                 \
        UBRR1L = 0;                 \
    } while (0)
    #define PS2_USART_RX_INT_ON() do {  \
        UCSR1B = ((1 << RXCIE1) |       \
                  (1 << RXEN1));        \
    } while (0)
    #define PS2_USART_RX_POLL_ON() do { \
        UCSR1B = (1 << RXEN1);          \
    } while (0)
    #define PS2_USART_OFF() do {    \
        UCSR1C = 0;                 \
        UCSR1B &= ~((1 << RXEN1) |  \
                    (1 << TXEN1));  \
    } while (0)
    #define PS2_USART_RX_READY      (UCSR1A & (1<<RXC1))
    #define PS2_USART_RX_DATA       UDR1
    #define PS2_USART_ERROR         (UCSR1A & ((1<<FE1) | (1<<DOR1) | (1<<UPE1)))
    #define PS2_USART_RX_VECT       USART1_RX_vect
#endif

#define MH_AUTO_BUTTONS_TIMEOUT 500
//#define PS2_MOUSE_ENABLE_SCROLLING

// mod tap setting

// per key
#define PERMISSIVE_HOLD_PER_KEY
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
#define TAPPING_TERM_PER_KEY
#define RETRO_TAPPING_PER_KEY

// combo
#define COMBO_TERM 50

// auto shift
#define AUTO_SHIFT_TIMEOUT_PER_KEY
