#include "planck.h"
#include "action_layer.h"
#include "mousekey.h"

#define CUR_EUR UC(0x20ac)
#define CUR_GPB UC(0x00a3)
#define CUR_YEN UC(0x00a5)
#define CUR_BTC UC(0x20bf)
#define BULLET UC(0x2022)
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

enum custom_keycodes {
                      A_MUL = SAFE_RANGE,
                      A_MUR,
                      A_MDL,
                      A_MDR,
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
 * | Esc  | Alt  | Bksp | Sym  |Shift |Super | Ctrl |Space | Num  | Tab  |AltGr |Enter |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = {
  {KC_Q,    KC_W,    KC_F,    KC_P,  KC_G,    KC_BTN1, KC_BTN2, KC_J,   KC_L, KC_U,    KC_Y,    KC_QUOT},
  {KC_A,    KC_R,    KC_S,    KC_T,  KC_D,    A_MUL, A_MUR, KC_H,   KC_N, KC_E,    KC_I,    KC_O },
  {KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,    A_MDL, A_MDR, KC_K,   KC_M, KC_COMM, KC_DOT,  KC_SLSH},
  {KC_ESC,  KC_LALT, KC_BSPC, SYMBL, KC_LSFT, KC_LGUI, KC_LCTL, KC_SPC, NUM,  KC_TAB,  KC_RALT, KC_ENT}
},

/* Gaming
 * ,----------------------------------.             ,----------------------------------.
 * | Tab  |   q  |   w  |   e  |   r  |  3       6  |   t  |  y   |  u   |  i   |  o   |
 * |------+------+------+------+------|             |------+------+------+------+------|
 * | Alt  |   a  |   s  |   d  |   f  |  2       5  |   g  |  h   |  j   |  k   |  l   |
 * |------+------+------+------+------|             |------+------+------+------+------|
 * | Shift|   z  |   x  |   c  |   v  |  1       4  |   b  |  n   |  m   |  p   |  /   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |Colmak| Bksp | Sym  |           Space           | Num  |Super | Esc  |Enter |
 * `-----------------------------------------------------------------------------------'
 */
[_GAMING] = {
 {KC_TAB,  KC_Q,    KC_W,     KC_E,    KC_R,   KC_3,   KC_6,   KC_T,    KC_Y,    KC_U,    KC_I,   KC_O},
 {KC_LALT, KC_A,    KC_S,     KC_D,    KC_F,   KC_2,   KC_5,   KC_G,    KC_H,    KC_J,    KC_K,   KC_L},
 {KC_LSFT, KC_Z,    KC_X,     KC_C,    KC_V,   KC_1,   KC_4,   KC_B,    KC_N,    KC_M,    KC_P,   _______},
 {KC_LCTL, GCOLEMAK, _______, _______, KC_SPC, KC_SPC, KC_SPC, _______, _______, KC_LGUI, KC_ESC, _______}
},

[_GAMING_COLEMAK] = {
  {KC_Q,    KC_W,    KC_F,     KC_P,    KC_G,   KC_BTN1, KC_BTN2, KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT},
  {KC_A,    KC_R,    KC_S,     KC_T,    KC_D,   KC_MS_L, KC_MS_R, KC_H,    KC_N,    KC_E,    KC_I,    KC_O},
  {KC_Z,    KC_X,    KC_C,     KC_V,    KC_B,   KC_MS_D, KC_MS_U, KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH},
  {KC_LCTL, _______, _______, _______, KC_SPC, KC_SPC,  KC_SPC,  _______, _______, _______, _______, _______}
},

/* Symbols
 * ,----------------------------------.             ,----------------------------------.
 * |   `  |   ^  |   ~  |   $  |   {  |             |   +  |   &  |   %  |   @  |   "  |
 * |-------------+------+------+------|    Mouse    |------+------+------+------+------|
 * |   \  |   !  |   _  |   (  |   }  |    Keys     |   =  |   )  |   -  |   :  |   ;  |
 * |------+------+------+------+------|             |------+------+------+------+------|
 * |   |  |   “  |   ”  |   [  |   #  |             |   *  |   ]  |   <  |   >  |   ?  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   —  |   ‘  |   ’  |######|   ☺  |   ☹  |   …  |      |######|   ±  |   •  |   ‽  |
 * `-----------------------------------------------------------------------------------'
 */
[_SYMBL] = {
 {KC_GRV,  KC_CIRC, KC_TILD,  KC_DLR, KC_LCBR, KC_BTN3, KC_BTN4,  KC_PLUS,  KC_AMPR, KC_PERC, KC_AT,   KC_DQUO},
 {KC_BSLS, KC_EXLM, KC_UNDS, KC_LPRN, KC_RCBR, KC_WH_L, KC_WH_R,  KC_EQL, KC_RPRN, KC_MINS, KC_COLN, KC_SCLN},
 {KC_PIPE, LDQUO,   RDQUO,   KC_LBRC, KC_HASH, KC_WH_D, KC_WH_U,  KC_ASTR, KC_RBRC, KC_LABK, KC_RABK, KC_QUES},
 {EMDASH,  LSQUO,   RSQUO,   _______, SMILE,   FROWN,   ELLIPSIS, _______,  _______, PLUSMN,  BULLET,  INTEROBANG}
},

/* Numbers and navigation
 * ,----------------------------------.             ,----------------------------------.
 * |Insert| Home | Up   | End  | PgUp |             |  +   |  7   |  8   |  9   |  ¥   |
 * |------+------+------+------+------|    Mouse    |------+------+------+------+------|
 * |      | Left | Down | Right|PgDown|    Keys     |  =   |  4   |  5   |  6   |  £   |
 * |------+------+------+------+------|             |------+------+------+------+------|
 * |      |      |      |      |      |             |  *   |  1   |  2   |  3   |  €   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |Delete|######|      |      |      |      |######|  0   |  .   |  ₿   |
 * `-----------------------------------------------------------------------------------'
 */
 
[_NUM] = {
  {KC_INS,  KC_HOME, KC_UP,   KC_END,   KC_PGUP,  KC_BTN4, KC_BTN5, KC_PPLS, KC_7,   KC_8, KC_9,   CUR_YEN},
  {_______, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN,  KC_WH_L, KC_WH_R, KC_PEQL, KC_4,   KC_5, KC_6,   CUR_GPB},
  {_______, _______, _______, _______,  _______,  KC_WH_D, KC_WH_U, KC_PAST, KC_1,   KC_2, KC_3,   CUR_EUR},
  {_______, _______, KC_DEL,  _______,  _______,  _______, _______, _______, _______, KC_0, KC_DOT, CUR_BTC}
},

/* Functions (Lower + Raise)
 * ,----------------------------------.             ,----------------------------------.
 * |      |      | Vol+ |      |PrtSc |             |      |  F7  |  F8  |  F9  | F15  |
 * |------+------+------+------+------|    Mouse    |------+------+------+------+------|
 * |      |      | Vol- |      |ScrLk |    Keys     |      |  F4  |  F5  |  F6  | F14  |
 * |------+------+------+------+------|             |------+------+------+------+------|
 * |      |      | Mute |      |Pause |             |      |  F1  |  F2  |  F3  | F13  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Sleep |      |      |######|Colmak|Gaming| Debug| Reset|######| F10  | F11  | F12  |
 * `-----------------------------------------------------------------------------------'
 */
[_FUNC] = {
  {_______, _______, KC_VOLU, _______, KC_PSCR,  _______,  KC_ACL2, _______,  KC_F7,   KC_F8,  KC_F9,  KC_F15},
  {_______, _______, KC_VOLD, _______, KC_SLCK,  _______,  KC_ACL1, _______,  KC_F4,   KC_F5,  KC_F6,  KC_F14},
  {_______, _______, KC_MUTE, _______, KC_PAUS,  _______,  KC_ACL0, _______,  KC_F1,   KC_F2,  KC_F3,  KC_F13},
  {KC_SLEP, _______, _______, _______, COLEMAK,  GAMING,   DEBUG,   RESET,    _______, KC_F10, KC_F11, KC_F12}
}


};

int direction[4];
bool process_mouse(uint16_t keycode, keyrecord_t *record) {
  enum udlr { up, down, left, right };

  if (keycode == A_MUR) {
    if (record->event.pressed) {
      direction[up] += 1;
      direction[right] += 1;
    } else {
      direction[up] -= 1;
      direction[right] -= 1;
    }
  }

  if (keycode == A_MDR) {
    if (record->event.pressed) {
      direction[down] += 1;
      direction[right] += 1;
    } else {
      direction[down] -= 1;
      direction[right] -= 1;
    }
  }

  if (keycode == A_MUL) {
    if (record->event.pressed) {
      direction[up] += 1;
      direction[left] += 1;
    } else {
      direction[up] -= 1;
      direction[left] -= 1;
    }
  }

  if (keycode == A_MDL) {
    if (record->event.pressed) {
      direction[down] += 1;
      direction[left] += 1;
    } else {
      direction[down] -= 1;
      direction[left] -= 1;
    }
  }

  int enabled = 1;
  for (int i=0; i<4; i++) {
    if (direction[i] == 2) {
      enabled = 2;
      break;
    }
  }

  if (direction[up] == enabled) mousekey_on(KC_MS_UP);
  else mousekey_off(KC_MS_UP);

  if (direction[down] == enabled) mousekey_on(KC_MS_DOWN);
  else mousekey_off(KC_MS_DOWN);

  if (direction[left] == enabled) mousekey_on(KC_MS_LEFT);
  else mousekey_off(KC_MS_LEFT);

  if (direction[right] == enabled) mousekey_on(KC_MS_RIGHT);
  else mousekey_off(KC_MS_RIGHT);

  mousekey_send();
  return true;
}

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

  process_mouse(keycode, record);

  return true;
}
