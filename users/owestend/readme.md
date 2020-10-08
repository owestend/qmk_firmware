# Table of Contents
* [Overview](#overview)[[documentation](https://docs.qmk.fm/#/feature_userspace)]
* [Secret Macros](#secret-macros) [[documentation](https://github.com/qmk/qmk_firmware/blob/master/users/drashna/readme_secrets.md)]

## [Overview](#overview)
Thanks to [drashna](https://github.com/drashna) and the people in the qmk_firmware/users/ directory :)

In moment I use following different keyboards:  

* [YD60](https://github.com/qmk/qmk_firmware/tree/master/keyboards/yd60mq) a 60% keyboard with variants of possible layouts form [YDMK](https://de.aliexpress.com/item/32799437588.html)
* [XD60](https://github.com/qmk/qmk_firmware/tree/master/keyboards/xd60) a 60% keyboard from [KPRepublic on AliExpress](https://de.aliexpress.com/item/32919981329.html)
* [XD68](https://github.com/qmk/qmk_firmware/tree/master/keyboards/xd68) a 65% keyboard from [KPRepublic on AliExpress](http://kprepublic.com/products/xiudi-xd68-pcb-65-custom-mechanical-keyboard-support-tkg-tools-underglow-rgb-pcb-programmed-kle-lots-of-layouts)

My layouts define under *qmk_firmware/layouts/community*.

* `LAYOUT_60_ansi`
* `LAYOUT_60_ansi_split_bs_rshift`
* `LAYOUT_65_ansi`

## [Secret Macros](#secret-macros)
this implimentation of secret macros is taken from [drashna](https://github.com/drashna).In different to his implementation I put the strings and also the array to program memory.

### `.gitignore`
First, you need to exclude to file witch contain the secret macros from git. To exclude the file you need to create a file *.gitignore* to your QMK user space directory with following content:  

```console
secrets.h
```

### `<name>.h`
The additional key codes `KC_SEC_1` up to `KC_SEC_10` needs to define in your *<name>.h* file or where ever you define your additional key codes.  
 
### `secrets.c`
The key codes will handle by aa function called `process_record_secrets`. This function is define in secrets.c file.
 
```c
#include "<name>.h"    // replace <name> with your keymap's "h"file, or whatever file store the keycodes

#if (__has_include("secrets.h") && !defined(NO_SECRETS))
#include "secrets.h"
#else
const char sec01[] PROGMEM = "test1";
const char sec02[] PROGMEM = "test2";
const char sec03[] PROGMEM = "test3";
const char sec04[] PROGMEM = "test4";
const char sec05[] PROGMEM = "test5";
const char sec06[] PROGMEM = "test6";
const char sec07[] PROGMEM = "test7";
const char sec08[] PROGMEM = "test8";
const char sec09[] PROGMEM = "test9";
const char sec10[] PROGMEM = "test10";

const char * const secrets[] =
{
    sec01,
    sec02,
    sec03,
    sec04,
    sec05,
    sec06,
    sec07,
    sec08,
    sec09,
    sec10
};
#endif

bool process_record_secrets(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_SEC ... KC_SEC_MAX: // Secrets!  Externally defined strings, not stored in repo
        if (!record->event.pressed) {
            clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
            send_string_with_delay_P(secrets[keycode - KC_SEC], MACRO_DELAY);
        }
        return false;
        break;
    }
    return true;
}
```

### `secrets.h`

The *secrets.h* file contained the secret macros itself. It is very important to exclude this file ever from your git repro (Please see [*.gitignore*](##gitignore)). Otherwise other Git/Github useres able to see your passwords, or what ever you stroe in your secret macros.  

```c
const char sec01[] PROGMEM = "test1";
const char sec02[] PROGMEM = "test2";
const char sec03[] PROGMEM = "test3";
const char sec04[] PROGMEM = "test4";
const char sec05[] PROGMEM = "test5";
const char sec06[] PROGMEM = "test6";
const char sec07[] PROGMEM = "test7";
const char sec08[] PROGMEM = "test8";
const char sec09[] PROGMEM = "test9";
const char sec10[] PROGMEM = "test10";

const char * const secrets[] =
{
    sec01,
    sec02,
    sec03,
    sec04,
    sec05,
    sec06,
    sec07,
    sec08,
    sec09,
    sec10
};
```

Replacing the strings with codes that you need.  

### `process_record.c`

The defined function `process_record_secret` needs to call somewhere. I add it in the file where I define and implement my `process_recoprd_user` function. 

You need a dummy definition of `process_record_secret`.  This will use if no other definion is present.
```c
__attribute__((weak)) bool process_record_secrets(uint16_t keycode, keyrecord_t *record) { return true; }
```

The call itself should look like the following:
```c
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_XXXX:
                :
                :
                :
            break;
    }
    return (
        process_record_keymap(keycode, record)
            &&
        process_record_secrets(keycode, record)
    );
```

### `rules.mk`

```make
# enable secrets
ifneq ($(strip $(NO_SECRETS)), yes)
    ifneq ("$(wildcard $(USER_PATH)/secrets.c)","")
        SRC += secrets.c
    endif
    ifeq ($(strip $(NO_SECRETS)), lite)
        OPT_DEFS += -DNO_SECRETS
    endif
endif
```

