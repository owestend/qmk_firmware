# Enable Bootmagic Lite to consistently reset to bootloader and clear EEPROM.
BOOTMAGIC_ENABLE = lite

# Enable media keys on all keyboards.
EXTRAKEY_ENABLE = yes

# Enable N-key rollover on all keyboards. In addition to its intended
# functionality, as of July 2020, this is required for Chrome OS to process
# media keys. (It appears that Chrome OS filters out key events from the second
# USB endpoint's consumer and system control devices unless that endpoint also
# reports a keyboard or mouse device.)
NKRO_ENABLE = yes

# Disable unused build options on all keyboards.
COMMAND_ENABLE = no
CONSOLE_ENABLE = no
MOUSEKEY_ENABLE = no
TERMINAL_ENABLE = no

# Disable all LED functions, cause i don't like it.
BACKLIGHT_ENABLE = no      # Dissable keyboard backlight functionality
RGBLIGHT_ENABLE = no       # Dissable keyboard RGB underglow

ifeq ($(strip $(KEYBOARD)), xd68)
#	LINK_TIME_OPTIMIZATION_ENABLE
endif

SRC += 	owestend.c \
		process_records.c

# enable secrets
ifneq ($(strip $(NO_SECRETS)), yes)
    ifneq ("$(wildcard $(USER_PATH)/secrets.c)","")
        SRC += secrets.c
    endif
    ifeq ($(strip $(NO_SECRETS)), lite)
        OPT_DEFS += -DNO_SECRETS
    endif
endif

