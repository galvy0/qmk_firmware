Alpha Stagger JD45
===================

Hardware notes
- MCU: atmega32u4
- Bootloader: atmel-dfu
- USB VID/PID in `keyboard.json`

Matrix wiring
- Rows: B7, F6, B6, C6
- Cols: E6, F0, F1, F4, F5, B0, B5, B4, D7, D6, D4, D3

PS/2 TrackPoint
- PS2 enabled, USART driver using clock pin D5 and data pin D2. See `config.h` for USART macros.

Build notes
- This keyboard enables `PS2_MOUSE_ENABLE` in `rules.mk` by default. If you don't use the TrackPoint, disable it in `rules.mk`.
- Tapping/tap-hold/per-key settings are present in `config.h`.

Keymaps
- See `keymaps/` for default, macOS, and oled variants.
