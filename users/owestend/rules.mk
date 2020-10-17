# Global configurations
#
####

# Enable Bootmagic Lite to consistently reset to bootloader and clear EEPROM.
BOOTMAGIC_ENABLE = lite

# Enable media keys on all keyboards.
EXTRAKEY_ENABLE = yes

# Enable N-key rollover on all keyboards. In addition to its intended
# functionality, as of July 2020, this is required for Chrome OS to process
# media keys. (It appears that Chrome OS filters out key events from the second
# USB endpoint's consumer and system control devices unless that endpoint also
# reports a keyboard or mouse device.)
NKRO_ENABLE = no

# Disable unused build options on all keyboards.
COMMAND_ENABLE = no
CONSOLE_ENABLE = no
MOUSEKEY_ENABLE = no
TERMINAL_ENABLE = no
SPACE_CADET_ENABLE = no

# Enable / Disable my personal features
VIM_MODE_ENABLE = yes
GAME_LAYER_ENABLE = yes

# Keyboard specific configurations
#
####

# Enable link time optimization for AVR
ifneq ($(PLATFORM), CHIBIOS)
	LTO_ENABLE = yes
endif

# XD68
ifeq ($(strip $(KEYBOARD)), xd68)
	BACKLIGHT_ENABLE = no		# Dissable keyboard bachlight
	RGBLIGHT_ENABLE = no		# Dissable keyboard RGB underglow
endif

# YD60MQ
ifeq ($(findstring yd60mq, $(KEYBOARD)), yd60mq)
	BACKLIGHT_ENABLE = no		# Dissable keyboard bachlight
	RGBLIGHT_ENABLE = no		# Dissable keyboard RGB underglow
endif

# Include user space source files
#
#####
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

#GAME_LAYER_ENABLE = yes
VIMMODE_ENABLE = yes
# enable vim mode
ifeq ($(strip $(VIM_MODE_ENABLE)), yes)
    ifneq ("$(wildcard $(USER_PATH)/vim_mode.c)","")
        SRC += vim_mode.c
        OPT_DEFS += -DVIM_MODE_ENABLE
    endif
endif
