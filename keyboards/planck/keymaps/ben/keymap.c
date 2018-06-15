#include "planck.h"
#include "action_layer.h"

#define CUR_EUR UC(0x20ac)
#define CUR_GPB UC(0x00a3)
#define CUR_YEN UC(0x00a5)
#define CUR_BTC UC(0x20bf)
#define BULLET UC(0x2022)
#define TSPC UC(0x2009)
#define EMDASH UC(0x2014)
#define INTEROBANG UC(0x203D)
#define ELLIPSIS UC(0x2026)
#define PLUSMN UC(0x00B1)
#define LSQUO UC(0x2018)
#define RSQUO UC(0x2019)
#define LDQUO UC(0x201C)
#define RDQUO UC(0x201D)
#define SMILE UC(0x263A)
#define FROWN UC(0x2639)

extern keymap_config_t keymap_config;

enum planck_layers {
  _COLEMAK,
  _GAMING,
  _GAMING_COLEMAK,
  _SYMBL,
  _NUM,
  _FUNC
};

enum planck_keycodes {
  COLEMAK = TO(_COLEMAK),
  GAMING = TO(_GAMING),
  GCOLEMAK = MO(_GAMING_COLEMAK),
  SYMBL = MO(_SYMBL),
  NUM = MO(_NUM)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Colemak
 * ,----------------------------------.             ,----------------------------------.
 * |   q  |   w  |   f  |   p  |   g  |             |   j  |   l  |   u  |   y  |   '  |
 * |------+------+------+------+------|    Mouse    |------+------+------+------+------|
 * |   a  |   r  |   s  |   t  |   d  |    Keys     |   h  |   n  |   e  |   i  |   o  |
 * |------+------+------+------+------|             |------+------+------+------+------|
 * |   z  |   x  |   c  |   v  |   b  |             |   k  |   m  |   ,  |   .  |   /  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |Super | Bksp | Sym  |Shift | Ctrl | Alt  |Space | Num  | Tab  |AltGr |Enter |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = {
  {KC_Q,    KC_W,    KC_F,    KC_P,  KC_G,    KC_BTN1, KC_BTN2, KC_J,   KC_L, KC_U,    KC_Y,    KC_QUOT},
  {KC_A,    KC_R,    KC_S,    KC_T,  KC_D,    KC_MS_L, KC_MS_R, KC_H,   KC_N, KC_E,    KC_I,    KC_O },
  {KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,    KC_MS_D, KC_MS_U, KC_K,   KC_M, KC_COMM, KC_DOT,  KC_SLSH},
  {KC_ESC,  KC_LGUI, KC_BSPC, SYMBL, KC_LSFT, KC_LCTL, KC_LALT, KC_SPC, NUM,  KC_TAB,  KC_RALT, KC_ENT}
},

/* Gaming
 * ,----------------------------------.             ,----------------------------------.
 * | Bksp |   q  |   w  |   e  |   r  |             |   t  |  7   |  8   |  9   | Esc  |
 * |------+------+------+------+------|    Mouse    |------+------+------+------+------|
 * |  Alt |   a  |   s  |   d  |   f  |    Keys     |   g  |  4   |  5   |  6   |      |
 * |------+------+------+------+------|             |------+------+------+------+------|
 * | Shift|   z  |   x  |   c  |   v  |             |   b  |  1   |  2   |  3   |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |Super |Colmak| Sym  |           Space           | Num  |  Tab |AltGr |Enter |
 * `-----------------------------------------------------------------------------------'
 */
[_GAMING] = {
 {KC_TAB,  KC_Q,    KC_W,     KC_E,    KC_R,   _______, _______, KC_T,    KC_7,    KC_8,    KC_9,    KC_ESC},
 {KC_LALT, KC_A,    KC_S,     KC_D,    KC_F,   _______, _______, KC_G,    KC_4,    KC_5,    KC_6,    _______},
 {KC_LSFT, KC_Z,    KC_X,     KC_C,    KC_V,   _______, _______, KC_B,    KC_1,    KC_2,    KC_3,    _______},
 {KC_LCTL, _______, GCOLEMAK, _______, KC_SPC, KC_SPC,  KC_SPC,  _______, _______, _______, _______, _______}
},

[_GAMING_COLEMAK] = {
  {KC_Q,    KC_W,    KC_F,     KC_P,    KC_G,   KC_BTN1, KC_BTN2, KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT},
  {KC_A,    KC_R,    KC_S,     KC_T,    KC_D,   KC_MS_L, KC_MS_R, KC_H,    KC_N,    KC_E,    KC_I,    KC_O},
  {KC_Z,    KC_X,    KC_C,     KC_V,    KC_B,   KC_MS_D, KC_MS_U, KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH},
  {KC_LCTL, _______, GCOLEMAK, _______, KC_SPC, KC_SPC,  KC_SPC,  _______, _______, _______, _______, _______}
},

/* Symbols
 * ,----------------------------------.             ,----------------------------------.
 * |   `  |   ^  |   ~  |   $  |   {  |             |   =  |   &  |   %  |   @  |   "  |
 * |-------------+------+------+------|    Mouse    |------+------+------+------+------|
 * |   \  |   !  |   _  |   (  |   }  |    Keys     |   +  |   )  |   -  |   :  |   ;  |
 * |------+------+------+------+------|             |------+------+------+------+------|
 * |   |  |   “  |   ”  |   [  |   #  |             |   *  |   ]  |   <  |   >  |   ?  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   —  |   ‘  |   ’  |######|   ☺  |   ☹  |   …  |TSpace|######|   ±  |   •  |   ‽  |
 * `-----------------------------------------------------------------------------------'
 */
[_SYMBL] = {
 {KC_GRV,  KC_CIRC, KC_TILD,  KC_DLR, KC_LCBR, KC_BTN3, KC_BTN4,  KC_EQL,  KC_AMPR, KC_PERC, KC_AT,   KC_DQUO},
 {KC_BSLS, KC_EXLM, KC_UNDS, KC_LPRN, KC_RCBR, KC_WH_L, KC_WH_R,  KC_PLUS, KC_RPRN, KC_MINS, KC_COLN, KC_SCLN},
 {KC_PIPE, LDQUO,   RDQUO,   KC_LBRC, KC_HASH, KC_WH_D, KC_WH_U,  KC_ASTR, KC_RBRC, KC_LABK, KC_RABK, KC_QUES},
 {EMDASH,  LSQUO,   RSQUO,   _______, SMILE,   FROWN,   ELLIPSIS, TSPC,    _______, PLUSMN,  BULLET,  INTEROBANG}
},

/* Numbers and navigation
 * ,----------------------------------.             ,----------------------------------.
 * |Insert| Home | Up   | End  | PgUp |             |  =   |  7   |  8   |  9   |  ¥   |
 * |------+------+------+------+------|    Mouse    |------+------+------+------+------|
 * |      | Left | Down | Right|PgDown|    Keys     |  +   |  4   |  5   |  6   |  £   |
 * |------+------+------+------+------|             |------+------+------+------+------|
 * |      |      |      |      |      |             |  *   |  1   |  2   |  3   |  €   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |Delete|######|      |      |      |TSpace|######|  0   |  .   |  ₿   |
 * `-----------------------------------------------------------------------------------'
 */
 
[_NUM] = {
  {KC_INS,  KC_HOME, KC_UP,   KC_END,   KC_PGUP,  KC_BTN4, KC_BTN5, KC_PEQL, KC_7,   KC_8, KC_9,   CUR_YEN},
  {_______, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN,  KC_WH_L, KC_WH_R, KC_PPLS, KC_4,   KC_5, KC_6,   CUR_GPB},
  {_______, _______, _______, _______,  _______,  KC_WH_D, KC_WH_U, KC_PAST, KC_1,   KC_2, KC_3,   CUR_EUR},
  {_______, _______, KC_DEL,  _______,  _______,  _______, _______, TSPC,   _______, KC_0, KC_DOT, CUR_BTC}
},

/* Functions (Lower + Raise)
 * ,----------------------------------.             ,----------------------------------.
 * |      | Vol+ |      |      |PrtSc |             |      |  F7  |  F8  |  F9  | F15  |
 * |------+------+------+------+------|    Mouse    |------+------+------+------+------|
 * |      | Vol- |      |      |ScrLk |    Keys     |      |  F4  |  F5  |  F6  | F14  |
 * |------+------+------+------+------|             |------+------+------+------+------|
 * |      | Mute |      |      |Pause |             |      |  F1  |  F2  |  F3  | F13  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Sleep |      |      |######|Colmak|Gaming| Debug| Reset|######| F10  | F11  | F12  |
 * `-----------------------------------------------------------------------------------'
 */
[_FUNC] = {
  {_______, KC_VOLU, _______, _______, KC_PSCR,  _______,  KC_ACL2, _______,  KC_F7,   KC_F8,  KC_F9,  KC_F15},
  {_______, KC_VOLD, _______, _______, KC_SLCK,  _______,  KC_ACL1, _______,  KC_F4,   KC_F5,  KC_F6,  KC_F14},
  {_______, KC_MUTE, _______, _______, KC_PAUS,  _______,  KC_ACL0, _______,  KC_F1,   KC_F2,  KC_F3,  KC_F13},
  {KC_SLEP, _______, _______, _______, COLEMAK,  GAMING,   DEBUG,   RESET,    _______, KC_F10, KC_F11, KC_F12}
}


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case SYMBL:
      if (record->event.pressed) {
        layer_on(_SYMBL);
      } else {
        layer_off(_SYMBL);
      }
      update_tri_layer(_SYMBL, _NUM, _FUNC);
      break;
    case NUM:
      if (record->event.pressed) {
        layer_on(_NUM);
      } else {
        layer_off(_NUM);
      }
      update_tri_layer(_SYMBL, _NUM, _FUNC);
      break;
  }
  return true;
}
