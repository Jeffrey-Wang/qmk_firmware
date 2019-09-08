#include QMK_KEYBOARD_H

#ifdef PROTOCOL_LUFA
#include "lufa.h"
#include "split_util.h"
#endif

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
    _QWERTY = 0,
    _COLEMAK,
    _ARR,
    _FN,
    _ADJ
};

// Keycode defines for layers
#define QWERTY   DF(_QWERTY)
#define COLEMAK  DF(_COLEMAK)
#define FN       MO(_FN)
#define ADJ      MO(_ADJ)


enum custom_keycodes {
  RGBRST = SAFE_RANGE,
  RGB_MENU
};

#define LH_CBR ALL_T(KC_LBRC)
#define RH_CBR ALL_T(KC_RBRC)

#define FN_ESC   LT(_FN, KC_ESC)
#define FN_CAPS  LT(_FN, KC_CAPS)

#define ZOOMIN LCTL(KC_EQUAL)
#define ZOOMOUT LCTL(KC_MINUS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Qwerty
   * ,------------------------------------------------.  ,------------------------------------------------.
   * | GESC |   1  |   2  |   3  |   4  |  5   |   6  |  |   7  |   8  |   9  |  0   |   -  |   =  | BkSp |
   * |------+------+------+------+------+------|------|  |------|------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |   [  |  |   (  |   Y  |   U  |   I  |   O  |   P  |   \  |
   * |------+------+------+------+------+------|------|  |------|------+------+------+------+------+------|
   * |FN(CAPS)| A  |   S  |   D  |   F  |   G  |   ]  |  |   )  |   H  |   J  |   K  |   L  |   ;  |   '  |
   * |------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
   * |Shift |   Z  |   X  |   C  |   V  |   B  |   {  |  |   }  |   N  |   M  |   ,  |   .  |   /  |Shift |
   * |------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
   * | Ctrl |  Win |  Alt |  `   | ADJ  |DEL   | Bksp |  | Ins  | Space|  FN  | Left | Down | Up   |Right |
   * |------+------+------+------+------+------+------|  |------+------+------+------+------+------+------'
   *                                    | Space| Bksp |  | Enter| Space|
   *                                    `-------------'  `-------------'
   */
  [_QWERTY] = LAYOUT( \
    KC_GESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINUS,KC_EQL, KC_BSPC, \
     KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, KC_LBRC, KC_LPRN,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSLS, \
    FN_CAPS,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G, KC_RBRC, KC_RPRN,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT, \
    KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, LH_CBR ,  RH_CBR,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSHIFT, \
    KC_LCTL, KC_LGUI, KC_LALT, KC_GRV ,  ADJ,    KC_DEL , KC_BSPC, KC_INS, KC_SPC, TG(_FN),   KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, \
                                                  KC_SPC, KC_BSPC, KC_ENT,  KC_SPC \
  ),

  /* Colemak
   * ,------------------------------------------------.  ,------------------------------------------------.
   * | GESC |   1  |   2  |   3  |   4  |   5  |   -  |  |   =  |   6  |   7  |   8  |   9  |   0  | BkSp |
   * |------+------+------+------+------+------|------|  |------|------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   F  |   P  |   B  |   [  |  |   ]  |   J  |   L  |   U  |   Y  |   ;  |   \  |
   * |------+------+------+------+------+------|------|  |------|------+------+------+------+------+------|
   * |FN(CAPS)| A  |   R  |   S  |   T  |   G  |   (  |  |   )  |   K  |   N  |   E  |   I  |   O  |   '  |
   * |------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
   * |Shift |   Z  |   X  |   C  |   D  |   V  |   {  |  |   }  |   M  |   H  |   ,  |   .  |   /  |Enter |
   * |------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
   * | Ctrl |  Win |  Alt |  RGB | ADJ  | Space| DEL  |  | Enter| Space|  FN  | Left | Down | Up   |Right |
   * |------+------+------+------+------+------+------|  |------+------+------+------+------+------+------'
   *                                    | Space| DEL  |  | Enter| Space|
   *                                    `-------------'  `-------------'
   */
  [_COLEMAK] = LAYOUT( \
    KC_GESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINUS,KC_EQL, KC_BSPC, \
     KC_TAB,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_G, KC_LBRC, KC_LPRN,    KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN, KC_BSLS, \
    FN_CAPS,    KC_A,    KC_R,    KC_S,    KC_T,    KC_D, KC_RBRC, KC_RPRN,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O, KC_QUOT, \
    KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, LH_CBR ,  RH_CBR,    KC_K,    KC_M, KC_COMM, KC_DOT,  KC_SLSH, KC_RSHIFT, \
    KC_LCTL, KC_LGUI, KC_LALT, KC_GRV ,  ADJ,    KC_DEL , KC_BSPC, KC_INS, KC_SPC, TG(_FN),   KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, \
                                                  KC_SPC, KC_BSPC, KC_ENT,  KC_SPC \
  ),

  [_ARR] = LAYOUT( \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,\
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,\
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_UP,   _______,\
      _______, _______, _______, _______, _______, _______, _______, _______, _______, TG(_ARR),KC_SLSH, KC_LEFT, KC_DOWN, KC_RGHT, \
                                                   _______, _______, _______, _______ \
  ),

  /* FN
   * ,------------------------------------------------.  ,------------------------------------------------.
   * |prntsc|      |      |      |      |      |prntsc|  |  /   |      |      |      |      |      |      |
   * |------+------+------+------+------+------|------|  |------|------+------+------+------+------+------|
   * |      | -ZOOM|  UP  | +ZOOM| PGUP | HOME |      |  |  *   | NUM7 | NUM8 | NUM9 | PGUP |PRNTSC| HOME |
   * |------+------+------+------+------+------|------|  |------|------+------+------+------+------+------|
   * |KCCAPS| LEFT | DOWN | RIGHT| PGDN | END  |      |  |  -   | NUM4 | NUM5 | NUM6 | PGDWN|INSERT| END  |
   * |------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
   * |      |      | PLAY | NEXT | MUTE |      |      |  |  +   | NUM1 | NUM2 | NUM3 |      |  UP  |      |
   * |------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
   * |      | DPAD |      |RGBMOD| ADJ  |      |      |  |  =   | NUM0 |  FN  |      | RIGHT| DOWN | LEFT |
   * `------+------+------+------+------+------+------|  |------+------+------+------+------+------+------'
   *                  vol(  )           |      |      |  |      | NUM0 |
   *                                    `-------------'  `-------------'
   */
  [_FN] = LAYOUT( \
      KC_PSCR, _______, _______, _______, _______, _______, KC_PSCR, KC_PSLS, _______, _______, _______, _______, _______, _______,\
      _______, ZOOMOUT, KC_UP,   ZOOMIN,  KC_PGUP, KC_HOME, _______, KC_PAST, KC_KP_7, KC_KP_8, KC_KP_9, KC_PGUP, KC_PSCR, KC_HOME, \
      KC_CAPS, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_END , _______, KC_PMNS, KC_KP_4, KC_KP_5, KC_KP_6, KC_PGDN, KC_INS,  KC_END, \
      _______, _______, KC_MPLY, KC_MNXT, KC_MUTE, _______, _______, KC_PPLS, KC_KP_1, KC_KP_2, KC_KP_3, _______, KC_UP,   _______, \
      _______, TO(_ARR),_______, RGB_MOD, _______, _______, _______, KC_PEQL, KC_KP_0, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, \
                                                   _______, _______, _______, KC_KP_0 \
      ),

  /* ADJ
   * ,------------------------------------------------.  ,------------------------------------------------.
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |
   * |------+------+------+------+------+------|------|  |------|------+------+------+------+------+------|
   * |      | SAD  | VAI  | SAI  | RESET|      |      |  |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------|------|  |------|------+------+------+------+------+------|
   * |      | HUD  | VAD  | HUI  |RGBRST|      |      |  |      |      |QWERTY|COLEMK|      |      |      |
   * |------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |  |      |      |      |RGBTOG|  HUI |  SAI | VAI  |
   * |------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
   * |      |      |      |RGBMOD(|      |      |      |  |      |      |     |RGBRMOD| HUD |  SAD | VAD  |
   * `------+------+------+------+------+------+------|  |------+------+------+------+------+------+------'
   *                                    |      |      |  |      |      |
   *                                    `-------------'  `-------------'
   */

  [_ADJ] =  LAYOUT( \
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, \
    _______, RGB_SAD, RGB_VAI, RGB_SAI,   RESET, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, RGB_HUD, RGB_VAD, RGB_HUI,  RGBRST, _______, _______, _______, _______,  QWERTY, COLEMAK, _______, _______, _______, \
    _______, RGB_SPD, _______, RGB_SPI, _______, _______, _______, _______, _______, RGB_SPI, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, \
    _______, _______, _______, RGB_MOD, _______, _______, _______, _______, _______, RGB_SPD, RGB_RMOD,RGB_HUD, RGB_SAD, RGB_VAD, \
                                                 _______, _______, _______, _______ \
  )
};

// For RGBRST Keycode
#if defined(RGB_MATRIX_ENABLE)
void rgb_matrix_increase_flags(void)
{
    switch (rgb_matrix_get_flags()) {
        case LED_FLAG_ALL: {
            rgb_matrix_set_flags(LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER);
            rgb_matrix_set_color_all(0, 0, 0);
            }
            break;
        case LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER: {
            rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
            rgb_matrix_set_color_all(0, 0, 0);
            }
            break;
        case LED_FLAG_UNDERGLOW: {
            rgb_matrix_set_flags(LED_FLAG_NONE);
            rgb_matrix_disable_noeeprom();
            }
            break;
        default: {
            rgb_matrix_set_flags(LED_FLAG_ALL);
            rgb_matrix_enable_noeeprom();
            }
            break;
    }
}

void rgb_matrix_decrease_flags(void)
{
    switch (rgb_matrix_get_flags()) {
        case LED_FLAG_ALL: {
            rgb_matrix_set_flags(LED_FLAG_NONE);
            rgb_matrix_disable_noeeprom();
            }
            break;
        case LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER: {
            rgb_matrix_set_flags(LED_FLAG_ALL);
            rgb_matrix_set_color_all(0, 0, 0);
            }
            break;
        case LED_FLAG_UNDERGLOW: {
            rgb_matrix_set_flags(LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER);
            rgb_matrix_set_color_all(0, 0, 0);
            }
            break;
        default: {
            rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
            rgb_matrix_enable_noeeprom();
            }
            break;
    }
}
#endif

#ifdef RGB_OLED_MENU
uint8_t rgb_encoder_state = 4;

typedef void (*rgb_matrix_f)(void);

const rgb_matrix_f rgb_matrix_functions[6][2] = {
    { rgb_matrix_increase_hue, rgb_matrix_decrease_hue },
    { rgb_matrix_increase_sat, rgb_matrix_decrease_sat },
    { rgb_matrix_increase_val, rgb_matrix_decrease_val },
    { rgb_matrix_increase_speed, rgb_matrix_decrease_speed },
    { rgb_matrix_step, rgb_matrix_step_reverse },
    { rgb_matrix_increase_flags, rgb_matrix_decrease_flags }
};
#endif

#ifdef ENCODER_ENABLE
/**
static pin_t encoders_pad_a[] = ENCODERS_PAD_A;
#define NUMBER_OF_ENCODERS (sizeof(encoders_pad_a)/sizeof(pin_t))

const uint16_t PROGMEM encoders[][NUMBER_OF_ENCODERS * 2][2]  = {
    [_QWERTY] = ENCODER_LAYOUT( \
        KC_LBRC, KC_RBRC,
        KC_LEFT, KC_RIGHT 
    ),
    [_COLEMAK] = ENCODER_LAYOUT( \
        _______, _______,
        _______, _______
    ),
    [_ARR] = ENCODER_LAYOUT( \
        _______, _______,
        _______, _______
    ),
    [_FN] = ENCODER_LAYOUT( \
        KC_VOLD, KC_VOLU,
        KC_VOLD, KC_VOLU
    ),
    [_ADJ] = ENCODER_LAYOUT( \
        KC_VOLD, KC_VOLU,
        KC_VOLD, KC_VOLU
    )
};**/
void encoder_update_user(uint8_t index, bool clockwise) {
  if (!is_keyboard_master())
    return;
  uint8_t layer = biton32(layer_state);
  if (layer == 0) {
    if (index == 0) {
      if (clockwise) {
        tap_code(KC_RBRC);
      } else {
        tap_code(KC_LBRC);
      }
    } else {
      if (clockwise) {
        tap_code(KC_RIGHT);
      } else {
        tap_code(KC_LEFT);
      }
    }
  
  } else {
      if (clockwise) {
        tap_code(KC_VOLD);
      } else {
        tap_code(KC_VOLU);
      }
  }
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static uint16_t reset_timer;
  switch (keycode) {
    case RGBRST:
#if defined(RGBLIGHT_ENABLE)
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
        }
#elif defined(RGB_MATRIX_ENABLE)
        if (record->event.pressed) {
          eeconfig_update_rgb_matrix_default();
        }
#endif
      return false;
    case RESET:
      if (record->event.pressed) {
          reset_timer = timer_read();
      } else {
          if (timer_elapsed(reset_timer) >= 500) {
              reset_keyboard();
          }
      }
      return false;
#if defined(RGB_MATRIX_ENABLE) && defined(KEYBOARD_rgbkb_sol_rev2)
    case RGB_TOG:
      if (record->event.pressed) {
        rgb_matrix_increase_flags();
      }
      return false;
#endif
    case RGB_MENU:
#ifdef RGB_OLED_MENU
      if (record->event.pressed) {
        if (get_mods() & MOD_MASK_SHIFT) {
          rgb_encoder_state = (rgb_encoder_state - 1);
          if (rgb_encoder_state > 5) {
            rgb_encoder_state = 5;
          }
        } else {
          rgb_encoder_state = (rgb_encoder_state + 1) % 6;
        }
      }
#endif
      return false;
  }
  return true;
}

#define DEFAULT_COLOR 207, 230, 120
#define FN_COLOR 155, 200, 120
#define ADJ_COLOR 235, 200, 120

uint32_t layer_state_set_user(uint32_t state) {
  switch (biton32(state)) {
    case _ARR:
      layer_off(_FN);
      rgblight_sethsv_noeeprom(207, 230, 120); // #D65CE6
      //rgblight_sethsv_at(155, 200, 120, 47);
      break;
    case _FN:
      rgblight_sethsv_noeeprom(155, 200, 120);// #47E6A4
      break;
    case _ADJ:
      rgblight_sethsv_noeeprom(235, 200, 120); // #
      break;
    default:
      rgblight_sethsv_noeeprom(207, 230, 120); // #D65CE6
      break;
  }
  return state;
}
void suspend_power_down_kb(void)
{
    rgb_matrix_set_suspend_state(true);
}

void suspend_wakeup_init_kb(void)
{
    rgb_matrix_set_suspend_state(false);
}

// OLED Driver Logic
#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (is_keyboard_master())
    return OLED_ROTATION_270;
  return rotation;
}

static void render_logo(void) {
  static const char PROGMEM sol_logo[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
  };
  oled_write_P(sol_logo, false);
}

static void render_status(void) {
  // Render to mode icon
  static const char PROGMEM sol_icon[] = {
    0x9b,0x9c,0x9d,0x9e,0x9f,
    0xbb,0xbc,0xbd,0xbe,0xbf,
    0xdb,0xdc,0xdd,0xde,0xdf,0
  };
  oled_write_P(sol_icon, false);

  // Define layers here
  oled_write_P(PSTR("Layer"), false);
  uint8_t layer = layer_state ? biton(layer_state) : biton32(default_layer_state);
  switch (layer) {
    case _QWERTY:
      oled_write_P(PSTR("BASE "), false);
      break;
    case _COLEMAK:
      oled_write_P(PSTR("CLMK "), false);
      break;
    case _FN:
      oled_write_P(PSTR("FN   "), false);
      break;
    case _ADJ:
      oled_write_P(PSTR("ADJ  "), false);
      break;
    default:
      oled_write_P(PSTR("UNDEF"), false);
  }

  // Host Keyboard LED Status
    uint8_t led_state = host_keyboard_leds();
    oled_write_P(PSTR("-----"), false);
    oled_write_P(IS_LED_ON(led_state, USB_LED_NUM_LOCK) ? PSTR("NUMLK") : PSTR("     "), false);
    oled_write_P(IS_LED_ON(led_state, USB_LED_CAPS_LOCK) ? PSTR("CAPLK") : PSTR("     "), false);
    oled_write_P(IS_LED_ON(led_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLK") : PSTR("     "), false);

#ifdef RGB_OLED_MENU
    static char buffer[31] = { 0 };
    snprintf(buffer, sizeof(buffer), "h%3d s%3d v%3d s%3d m%3d e%3d ", rgb_matrix_config.hsv.h, rgb_matrix_config.hsv.s, rgb_matrix_config.hsv.v, rgb_matrix_config.speed, rgb_matrix_config.mode, rgb_matrix_get_flags());
    buffer[4 + rgb_encoder_state * 5] = '<';

    oled_write_P(PSTR("-----"), false);
    oled_write(buffer, false);
#endif
}

void oled_task_user(void) {
  if (is_keyboard_master()) {
    render_status();
  } else {
    render_logo();
    oled_scroll_left();
  }
}

#endif
