/* Copyright 2015-2021 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

#ifdef AUDIO_ENABLE
#    include "muse.h"
#endif
#ifdef SWAP_HANDS_ENABLE
const keypos_t PROGMEM hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
    {{5, 4}, {4, 4}, {3, 4}, {2, 4}, {1, 4}, {0, 4}},
    {{5, 5}, {4, 5}, {3, 5}, {2, 5}, {1, 5}, {0, 5}},
    {{5, 6}, {4, 6}, {3, 6}, {2, 6}, {1, 6}, {0, 6}},
    {{4, 3}, {3, 3}, {2, 7}, {1, 7}, {0, 7}, {5, 3}},
    
    {{5, 0}, {4, 0}, {3, 0}, {2, 0}, {1, 0}, {0, 0}},
    {{5, 1}, {4, 1}, {3, 1}, {2, 1}, {1, 1}, {0, 1}},
    {{5, 2}, {4, 2}, {3, 2}, {2, 2}, {1, 2}, {0, 2}},
    {{0, 3}, {1, 3}, {2, 3}, {3, 7}, {4, 7}, {5, 7}},
};
#endif

/*enum planck_layers {
  _QWERTY,
  _COLEMAK,
  _DVORAK,
  _LOWER,
  _RAISE,
  _PLOVER,
  _ADJUST
};*/
enum planck_layers {
	_BASE,
	_LOWER,
	_RAISE,
	_FN1,
	_FN2,
	_MACRO,
	_SUPER //Always the highest layer
};

/*enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  PLOVER,
  BACKLIT,
  EXT_PLV
};*/
enum planck_keycodes {
	D_LEFT = SAFE_RANGE, //D_ prefix for virtual desktop navigation and app switching
	D_RIGHT,			 //these should change based on OS value (config on _SUPER)
	D_ALL,
	D_APP,
	C_CMNT, //open comment
	C_00,   //double 0
	C_TNMC, //close comment
	C_P00,  //double num pad 0
	C_LCK,
	C_QUIT,
	C_WINX,
	C_CAD, //C(A(KC_DEL)) windows | LGUI(LALT(KC_ESC)) mac
	C_WIN,
	C_MAC,
	C_LINUX,
	C_CLEAR,
	P_CMNT,
	P_PRN,
	P_PRNN,
	P_BRC,
	P_BRCN,
	P_ANGL,
	P_ANGN,
	M_SHRUG,
	M_TABLE,
	M_EML1,
	M_EML2,
	M_EML3,
	M_EML4,
	M_EML5,
	M_SIG1,
	M_SIG2,
	M_SIG3,
	M_SIG4,
	M_SIG5,
};

#define SPACE SH_T(KC_SPC)
#define LOWER LT(_LOWER,KC_TAB)
#define RAISE LT(_RAISE,KC_ENTER)
#define MACRO MO(_MACRO)
#define FN2 MO(_FN2)
#define FN_ESC LT(_FN1,KC_ESCAPE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |  `   |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | FN2  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | App  | Alt  | GUI  |Lower |    Space    |Raise | Alt  | Macro| App  | Ctrl |
 * `-----------------------------------------------------------------------------------'
 */
[_BASE] = LAYOUT_planck_grid(
    KC_GRAVE,KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
    FN_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_BSPC,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, FN2    ,
    KC_LCTL, KC_MENU, KC_LALT, KC_LGUI, LOWER,   SPACE,   SPACE,   RAISE,   KC_RALT, MACRO,   KC_RGUI, KC_RCTL
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |   =  |   7  |   8  |   9  |   /  | CMNT |   (  |  )   |   [  |   ]  | Caps |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  .   |   -  |   4  |   5  |   6  |   *  |  Left| Down |  Up  | Right|   '  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   0  |   1  |   2  |   3  |   =  |  Home| PGDN |  PGUP|  END |DskLft|DskRgt|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  00  |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    _______, KC_EQL,  KC_7,    KC_8,    KC_9,    KC_SLSH, C_CMNT,  KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC, KC_CAPS,
    KC_DOT,  KC_MINS, KC_4,    KC_5,    KC_6,    KC_ASTR, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_QUOT, KC_DEL , 
    _______, KC_0,    KC_1,    KC_2,    KC_3,    KC_EQL,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  D_LEFT,  D_RIGHT,
	_______, C_00,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |   =  |   7  |   8  |   9  |   /  |CCMNT |ScrlDn|ScrlUp|      |      |CapWrd|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  .   |   -  |   4  |   5  |   6  |   *  |  MSL | MSD  | MSU  | MSR  |DskApp|DskAll|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   0  |   1  |   2  |   3  |   =  |  MS2 | MS1  |  MS3 |  MS4 |DskLft|DskRgt|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  00  |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    _______, KC_PPLS, KC_P7,   KC_P8,   KC_P9,   KC_PSLS, C_TNMC,  KC_WH_D, KC_WH_U, _______, _______, CW_TOGG,
    KC_DOT,  KC_PMNS, KC_P4,   KC_P5,   KC_P6,   KC_PAST, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, D_APP,   D_ALL  , 
    _______, KC_P0,   KC_P1,   KC_P2,   KC_P3,   KC_PENT, KC_BTN2, KC_BTN1, KC_BTN3, KC_BTN4, D_LEFT,  D_RIGHT,
	_______, C_P00,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* FN1
 * ,-----------------------------------------------------------------------------------.
 * |      |      | FN7  | FN8  | FN9  |      |      | FN19 | FN18 | FN17 |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | FN4  | FN5  | FN6  | FN23 | FN24 | FN16 | FN15 | FN14 |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | FN10 | FN1  | FN2  | FN3  | FN21 | FN22 | FN13 | FN12 | FN11 | FN20 |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FN1] = LAYOUT_planck_grid(
	_______, _______, KC_F7,   KC_F8,   KC_F9,   _______, _______, KC_F19,  KC_F18,  KC_F17, _______, _______, 
	_______, _______, KC_F4,   KC_F5,   KC_F6,   KC_F23,  KC_F24, KC_F16,  KC_F15,  KC_F14, _______, _______, 
	_______, KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_F21,  KC_F22,  KC_F13,  KC_F12,  KC_F11,  KC_F20, _______, 
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______

),

/* FN2
 * ,-----------------------------------------------------------------------------------.
 * | LCK  | Quit | Win_X|      |      |      |CMNTPR|  ()  | (\n) | []   | [\n] | CAD  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |    9 |   0  |   -  |   =  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | <\n> | <>   |   -  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FN2] = LAYOUT_planck_grid(
	C_LCK,   C_QUIT,  C_WINX,  _______, _______, _______, P_CMNT,  P_PRN,   P_PRNN,  P_BRC,   P_BRCN,  C_CAD  ,
	KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,   KC_9,    KC_0,    KC_MINS, KC_ENTER,
	_______, _______, _______, _______, _______, _______, _______, _______, P_ANGN,  P_ANGL,  KC_MINS, _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______

),

/* Macro
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |Tablef|Email1|Email2|Email3|Email4|Email5|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |Sig 1 |Sig 2 |Sig 3 |Sig 4 |Sig 5 |Shrug |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MACRO] = LAYOUT_planck_grid(
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
	_______, _______, _______, _______, M_TABLE, M_EML1,  M_EML2,  M_EML3,  M_EML4,  M_EML5,  _______, _______, 
	_______, _______, _______, _______, _______, M_SIG1,  M_SIG2,  M_SIG3,  M_SIG4,  M_SIG5,  M_SHRUG, _______, 
    _______, _______, _______, DM_REC1, DM_PLY1, _______, _______, DM_PLY2, DM_REC2, _______, _______, _______
),

/* SUPER
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |Tablef|Email1|Email2|Email3|Email4|Email5|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |Sig 1 |Sig 2 |Sig 3 |Sig 4 |Sig 5 |Shrug |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SUPER] = LAYOUT_planck_grid(
	QK_RBT,  _______, _______, _______, _______, _______, _______, KC_SCRL, KC_PAUS, KC_INS,  KC_PSCR, C_CLEAR, 
	_______, _______, _______, _______, _______, _______, _______, BL_DOWN, BL_UP,   BL_TOGG, _______, _______, 
	_______, _______, _______, _______, _______, _______, _______, C_WIN,   C_MAC,   C_LINUX, _______, _______, 
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _SUPER);
}

typedef enum {
	ST_WINDOWS,
	ST_MAC,
	ST_LINUX,
} os_states;

os_states os_state = ST_WINDOWS;
bool is_d_app_active = false;
uint16_t d_app_timer = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    /*case KC_ESC:
      if (record->event.pressed) {
        if (is_d_app_active) {
          is_d_app_active = false;
          if (os_state == ST_WINDOWS){
          	unregister_code(KC_LALT);
          } else if (os_state == ST_MAC) {
          	unregister_code(KC_LGUI);
          }
        }
      }
      return true;
      break;*/
    case D_LEFT:
      if (record->event.pressed) {
      	if (os_state == ST_WINDOWS) {
      		tap_code16(LCTL(LGUI(KC_LEFT)));
      	} else if (os_state == ST_MAC) {
      		tap_code16(LCTL(KC_LEFT));
      	}
      }
      return false;
      break;
    case D_RIGHT:
      if (record->event.pressed) {
      	if (os_state == ST_WINDOWS) {
      		tap_code16(LCTL(LGUI(KC_LEFT)));
      	} else if (os_state == ST_MAC) {
      		tap_code16(LCTL(KC_RGHT));
      	}
      }
      return false;
      break;
    case D_ALL:
      if (record->event.pressed) {
      	if (os_state == ST_WINDOWS) {
      		tap_code16(LGUI(KC_TAB));
      	} else if (os_state == ST_MAC) {
      		tap_code16(LCTL(KC_UP));
      	}
      }
      return false;
      break;
    case D_APP:
      if (record->event.pressed) {
      	if (!is_d_app_active) {
      		is_d_app_active = true;
			if (os_state == ST_WINDOWS) {
				register_code(KC_LALT);
			} else if (os_state == ST_MAC) {
				register_code(KC_LGUI);
			}
         }
         tap_code(KC_TAB);
         d_app_timer = 0;
       } else {
         //if (is_d_app_active) {
			d_app_timer = timer_read();
		 /*} else {
			if (os_state == ST_WINDOWS) {
			unregister_code(KC_LALT);
			} else if (os_state == ST_MAC) {
			unregister_code(KC_LGUI);
			}
		 }*/
       }
      return false;
      break;
    case C_CMNT:
      if (record->event.pressed) {
      	SEND_STRING("/*");
      }
      return false;
      break;
    case C_00:
      if (record->event.pressed) {
      	SEND_STRING("00");
      }
      return false;
      break;
  	case C_TNMC:
  	  if (record->event.pressed) {
  	  	SEND_STRING("*/");
  	  }
  	  return false;
  	  break;
  	case C_P00:
  	  if (record->event.pressed) {
  	  	tap_code(KC_P0);
  	  	tap_code(KC_P0);
  	  }
  	  return false;
  	  break;
  	case C_LCK:
  	  if (record->event.pressed) {
  	  	/* TODO:clear dynamic macros
  	  	tap_code(DM_REC1); tap_code(DM_RSTP);
  	  	tap_code(DM_REC2); tap_code(DM_RSTP);*/
  	    if (os_state == ST_WINDOWS) {
  	    	SEND_STRING(SS_LGUI("l"));
  	    } else if (os_state == ST_MAC) {
  	    	SEND_STRING(SS_LCTL(SS_LGUI("q")));
  	    }
  	  }
  	  return false;
  	  break;
  	case C_QUIT:
  	  if (record->event.pressed) {
  	    if (os_state == ST_WINDOWS) {
  	    	tap_code16(LALT(KC_F4));
  	    } else if (os_state == ST_MAC) {
  	    	SEND_STRING(SS_LGUI("q"));
  	    }
  	  }
  	  return false;
  	  break;
	case C_WINX:
  	  if (record->event.pressed) {
  	    if (os_state == ST_WINDOWS) {
  	    	tap_code16(LCTL(KC_F4));
  	    } else if (os_state == ST_MAC) {
  	    	SEND_STRING(SS_LGUI("w"));
  	    }
  	  }
  	  return false;
  	  break;
	case C_CAD:
  	  if (record->event.pressed) {
  	    if (os_state == ST_WINDOWS) {
  	      tap_code16(LCTL(LALT(KC_DEL)));
  	    } else if (os_state == ST_MAC) {
  	      tap_code16(LALT(LGUI(KC_ESC)));
  	    }
  	  }
  	  return false;
  	  break;
	case C_WIN:
	  if (record->event.pressed) {
	    os_state = ST_WINDOWS;
	    //TODO UNICODE
	    //tap_code(UC_WINC);
	  }
  	  return false;
  	  break;
	case C_MAC:
	  if (record->event.pressed) {
	    os_state = ST_MAC;
	    //TODO UNICODE
	    //tap_code(UC_MAC);
	  }
  	  return false;
  	  break;
	case C_LINUX:
	  if (record->event.pressed) {
	    os_state = ST_LINUX;
	    //TODO UNICODE
	    //tap_code(UC_LINX);
	  }
  	  return false;
  	  break;
	case C_CLEAR:
	  if (record->event.pressed){
	    clear_keyboard();
	  }
	  return false;
	  break;
	case P_CMNT:
	  if (record->event.pressed) {
	    SEND_STRING("/**/");
	    tap_code(KC_LEFT);
	    tap_code(KC_LEFT);
	  }
  	  return false;
  	  break;
	case P_PRN:
	  if (record->event.pressed) {
	  	bool is_shifted = get_mods() && MOD_MASK_SHIFT;
	  	if (is_shifted)
	  		del_mods(MOD_MASK_SHIFT);
	    SEND_STRING("()"SS_TAP(X_LEFT));
	    if (is_shifted)
	    	register_code(KC_LSFT);//works because RSFT isnt present in keymap
	  }
  	  return false;
  	  break;
	case P_PRNN:
	  if (record->event.pressed) {
	  	bool is_shifted = get_mods() && MOD_MASK_SHIFT;
	  	if (is_shifted)
	  		del_mods(MOD_MASK_SHIFT);
	  	SEND_STRING("(\n)"SS_TAP(X_LEFT));
	    if (is_shifted)
	    	register_code(KC_LSFT);//works because RSFT isnt present in keymap
	  }
  	  return false;
  	  break;
	case P_BRC:
	  if (record->event.pressed) {
	  	bool is_shifted = get_mods() && MOD_MASK_SHIFT;
	    SEND_STRING("[]");
	  	if (is_shifted)
	  		del_mods(MOD_MASK_SHIFT);
	  	tap_code(KC_LEFT);
	  	if (is_shifted)
	  		register_code(KC_LSFT);
	  }
  	  return false;
  	  break;
	case P_BRCN:
	  if (record->event.pressed) {
	  	bool is_shifted = get_mods() && MOD_MASK_SHIFT;
	    SEND_STRING("[\n]");
	  	if (is_shifted)
	  		del_mods(MOD_MASK_SHIFT);
	  	tap_code(KC_LEFT);
	  	if (is_shifted)
	  		register_code(KC_LSFT);
	  }
  	  return false;
  	  break;
	case P_ANGL:
	  if (record->event.pressed) {
	  	bool is_shifted = get_mods() && MOD_MASK_SHIFT;
	  	if (is_shifted)
	  		del_mods(MOD_MASK_SHIFT);
	    SEND_STRING("<>"SS_TAP(X_LEFT));
	    if (is_shifted)
	    	register_code(KC_LSFT);//works because RSFT isnt present in keymap
	  }
  	  return false;
  	  break;
	case P_ANGN:
	  if (record->event.pressed) {
	  	bool is_shifted = get_mods() && MOD_MASK_SHIFT;
	  	if (is_shifted)
	  		del_mods(MOD_MASK_SHIFT);
	  	SEND_STRING("<\n>"SS_TAP(X_LEFT));
	    if (is_shifted)
	    	register_code(KC_LSFT);//works because RSFT isnt present in keymap
	  }
  	  return false;
  	  break;
  	/* TODO UNICODE
	case M_SHRUG:
	  //SEND_STRING(MACRO_SHRUG); //unicode not supported by SEND_STRING
	  if (record->event.pressed) {
	    tap_code(UC(0x00AF));
	    SEND_STRING("\_");
	    tap_code(UC(0x30C4));
	    SEND_STRING("_/");
	    tap_code(UC(0x00AF));
	  }
  	  return false;
  	  break;
	case M_TABLE:
	  //SEND_STRING(MACRO_TABLE); //unicode not supported by SEND_STRING
	  if (record->event.pressed) {
	    SEND_STRING("(");    
	    tap_code(UC(0x256F));
	    tap_code(UC(0x00B0));
	    tap_code(UC(0x25A1));
	    SEND_STRING(")");
	    tap_code(UC(0xFF09));
	    tap_code(UC(0x256F));
	    tap_code(UC(0xFE35));
	    SEND_STRING(" ");
	    tap_code(UC(0x253B));
	    tap_code(UC(0x2501));
	    tap_code(UC(0x253));
	  }
  	  return false;
  	  break;
  	  */
	case M_EML1:
	  if (record->event.pressed){
	    SEND_STRING(MACRO_EML1);
	  }
  	  return false;
  	  break;
	case M_EML2:
	  if (record->event.pressed){
	    SEND_STRING(MACRO_EML2);
	  }
  	  return false;
  	  break;
	case M_EML3:
	  if (record->event.pressed){
	    SEND_STRING(MACRO_EML3);
	  }
  	  return false;
  	  break;
	case M_EML4:
	  if (record->event.pressed){
	    SEND_STRING(MACRO_EML4);
	  }
  	  return false;
  	  break;
	case M_EML5:
	  if (record->event.pressed){
	    SEND_STRING(MACRO_EML5);
	  }
  	  return false;
  	  break;
	case M_SIG1:
	  if (record->event.pressed){
	    SEND_STRING(MACRO_SIG1);
	  }
  	  return false;
  	  break;
	case M_SIG2:
	  if (record->event.pressed){
	    SEND_STRING(MACRO_SIG2);
	  }
  	  return false;
  	  break;
	case M_SIG3:
	  if (record->event.pressed){
	    SEND_STRING(MACRO_SIG3);
	  }
  	  return false;
  	  break;
	case M_SIG4:
	  if (record->event.pressed){
	    SEND_STRING(MACRO_SIG4);
	  }
  	  return false;
  	  break;
	case M_SIG5:
	  if (record->event.pressed){
	    SEND_STRING(MACRO_SIG5);
	  }
  	  return false;
  	  break;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

/*bool encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_DOWN);
      #else
        tap_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_UP);
      #else
        tap_code(KC_PGUP);
      #endif
    }
  }
    return true;
}*/

/* bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
#ifdef AUDIO_ENABLE
            static bool play_sound = false;
#endif
            if (active) {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_song); }
#endif
                layer_on(_ADJUST);
            } else {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_gb_song); }
#endif
                layer_off(_ADJUST);
            }
#ifdef AUDIO_ENABLE
            play_sound = true;
#endif
            break;
        }
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
    return true;
}*/

void matrix_scan_user(void) {
	if (is_d_app_active) {
		if (timer_elapsed(d_app_timer) > 1500) {
			if (os_state == ST_WINDOWS) {
				unregister_code(KC_LALT);
			} else if (os_state == ST_MAC) {
				unregister_code(KC_LGUI);
			}
			is_d_app_active = false;
		}
	}
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
