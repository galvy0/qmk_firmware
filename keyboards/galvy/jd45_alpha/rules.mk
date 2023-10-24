# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = atmel-dfu

#SHARED_EP_ENABLE = yes
#KEYBOARD_SHARED_EP = yes
# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = no # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes # Mouse keys
EXTRAKEY_ENABLE = yes # Audio control and System control
CONSOLE_ENABLE = yes # Console for debug
COMMAND_ENABLE = no # Commands for debug and configuration
NKRO_ENABLE = yes # Enable N-Key Rollover

LTO_ENABLE = no
KEY_LOCK_ENABLE = yes
WPM_ENABLE = no
COMBO_ENABLE = no

# ENCODER
ENCODER_ENABLE = no

# OLED
OLED_ENABLE = no
OLED_DRIVER = SSD1306

# trackpoint
PS2_MOUSE_ENABLE = yes
PS2_ENABLE = yes
PS2_DRIVER = usart
