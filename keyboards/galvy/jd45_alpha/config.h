#pragma once

#pragma once

/* Hardware mapping moved to keyboard.json where possible. Keep low-level
    macros and register-level PS/2 USART code here. */

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
    /* PS/2 USART low-level register macros retained here. Pin numbers are
       provided in keyboard.json (ps2.clock_pin / ps2.data_pin) and will be
       used by the build tooling. If you need to override pins at the C-level
       keep defines here, but avoid duplicating simple pin defs to prevent
       validator warnings. */

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

// per-key tapping/combo settings moved to keyboard.json
// (retained here only if you need C-level overrides)
