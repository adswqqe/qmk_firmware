/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "quantum.h"

// Tap Dance declarations
enum {
    TD_ESC_CAPS,
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_ESC_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_universal(
    KC_ESC   , LT(0, KC_1)    , LT(0, KC_2)     , LT(0, KC_3), LT(0, KC_4)  , LT(0, KC_5), LT(0, KC_6) ,                                  LT(0, KC_7)     , LT(0, KC_8)     , LT(0, KC_9)     , LT(0, KC_0)     , LT(0, KC_BSPC)  ,
    KC_TAB   , LT(0, KC_Q)     , LT(0, KC_W)     , LT(0, KC_E)     , LT(0, KC_R)     , LT(0, KC_T)     ,                                  LT(0, KC_Y)     , LT(0, KC_U)     , LT(0, KC_I)     , LT(0, KC_O)     , LT(0, KC_P)     , LT(0, KC_NUBS)  ,
    LT(0, KC_GRV)   , LT(0, KC_A)     , LT(0, KC_S)     , LT(0, KC_D)     , LT(0, KC_F)     , LT(0, KC_G)     ,                                  LT(0, KC_H)     , LT(0, KC_J)     , LT(0, KC_K)     , LT(0, KC_L)     , LT(0, KC_SCLN)  , LT(0, KC_QUOT)  ,
    KC_LSFT    , LT(0, KC_Z)     , LT(0, KC_X)     , LT(0, KC_C)     , LT(0, KC_V)     , LT(0, KC_B)     , LT(0, KC_RBRC)  ,  KC_NUHS     , LT(0, KC_N)     , LT(0, KC_M)     , LT(0, KC_COMM)  , LT(0, KC_DOT)   , LT(0, KC_SLSH)  , KC_RSFT  ,
    KC_LCTL  , KC_LGUI  , KC_LALT  , MO(1)     , SCRL_MO   , KC_SPC    ,LT(0,KC_BTN1),                                      KC_ENT          , KC_LNG1         , _______         , _______         , _______         , KC_RALT  , MO(2)
  ),

  [1] = LAYOUT_universal(
    TG(1), S(KC_1)  , KC_LBRC  , S(KC_3)  , S(KC_4)  , S(KC_5)  ,                                  KC_EQL   , S(KC_6)  ,S(KC_QUOT), S(KC_8)  , S(KC_9)  ,S(KC_INT1),
    S(KC_DEL) , S(KC_Q)  , S(KC_W)  , S(KC_E)  , S(KC_R)  , S(KC_T)  ,                                  S(KC_Y)  , S(KC_U)  , S(KC_I)  , S(KC_O)  , S(KC_P)  ,S(KC_INT3),
    AML_D50  , S(KC_A)  , S(KC_S)  , S(KC_D)  , S(KC_F)  , S(KC_G)  ,                                  S(KC_H)  , S(KC_J)  , S(KC_K)  , S(KC_L)  , KC_QUOT  , S(KC_2)  ,
    AML_I50  , S(KC_Z)  , S(KC_X)  , S(KC_C)  , S(KC_V)  , S(KC_B)  ,S(KC_RBRC),           S(KC_NUHS), S(KC_N)  , S(KC_M)  ,S(KC_COMM), S(KC_DOT),S(KC_SLSH),S(KC_RSFT),
    AML_TO  ,S(KC_LCTL),S(KC_LALT),S(KC_LGUI), _______  , _______  , _______  ,            _______  , _______  , _______  ,S(KC_RGUI), _______  , S(KC_RALT), _______
  ),

  [2] = LAYOUT_universal(
    KBC_SAVE  , KC_F1    , KC_F2    , KC_F3    , KC_F4    , KC_F5    ,                                  KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10   , KC_F11   ,
    SCRL_MO  , _______  , KC_7     , KC_8     , KC_9     , _______  ,                                  _______  , KC_LEFT  , KC_UP    , KC_RGHT  , _______  , KC_F12   ,
    A(KC_LEFT)  , A(KC_RGHT)  , KC_4     , KC_5     , KC_6     ,S(KC_SCLN),                                  KC_PGUP  , KC_BTN1  , KC_BTN3  , KC_BTN2  , KC_BTN3  , _______  ,
    _______  , _______  , KC_1     , KC_2     , KC_3     ,S(KC_MINS), S(KC_8)  ,            S(KC_9)  , KC_PGDN  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , KC_0     , KC_DOT   , _______  , _______  , _______  ,             KC_DEL  , _______  , _______  , _______  , _______  , _______  , _______
  ),

  [3] = LAYOUT_universal(
    RGB_TOG  , _______  , _______  , _______  , _______  , _______  ,                                  RGB_M_P  , RGB_M_B  , RGB_M_R  , RGB_M_SW , RGB_M_SN , RGB_M_K  ,
    RGB_MOD  , RGB_HUI  , RGB_SAI  , RGB_VAI  , _______  , _______  ,                                  RGB_M_X  , RGB_M_G  , RGB_M_T  , RGB_M_TW , _______  , _______  ,
    RGB_RMOD , RGB_HUD  , RGB_SAD  , RGB_VAD  , _______  , _______  ,                                  CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , KBC_SAVE , KBC_RST  ,
    _______  , _______  , SCRL_DVD , SCRL_DVI , SCRL_MO  , SCRL_TO  , EE_CLR  ,            EE_CLR  , KC_HOME  , KC_PGDN  , KC_PGUP  , KC_END   , _______  , _______  ,
    QK_BOOT    , _______  , KC_LEFT  , KC_DOWN  , KC_UP    , KC_RGHT  , _______  ,            _______  , KC_BSPC  , _______  , _______  , _______  , _______  , QK_BOOT
  ),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 3
    keyball_set_scroll_mode(get_highest_layer(state) == 3);
    return state;
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif

void pointing_device_init_user(void) {
    set_auto_mouse_enable(true); // always required before the auto mouse feature will work
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(0, KC_1):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_1);
            } else if (record->event.pressed) {
                tap_code16(S(KC_1)); // Intercept hold function
            }
            return false;
        case LT(0, KC_2):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_2); // Intercept tap function to send Ctrl-C
            } else if (record->event.pressed) {
                tap_code16(S(KC_2)); // Intercept hold function to send Ctrl-V
            }
            return false;
        case LT(0, KC_3):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_3); // Intercept tap function to send Ctrl-C
            } else if (record->event.pressed) {
                tap_code16(S(KC_3)); // Intercept hold function to send Ctrl-V
            }
            return false;
        case LT(0, KC_4):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_4); // Intercept tap function to send Ctrl-C
            } else if (record->event.pressed) {
                tap_code16(S(KC_4)); // Intercept hold function to send Ctrl-V
            }
            return false;
        case LT(0, KC_5):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_5); // Intercept tap function to send Ctrl-C
            } else if (record->event.pressed) {
                tap_code16(S(KC_5)); // Intercept hold function to send Ctrl-V
            }
            return false;
        case LT(0, KC_6):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_6); // Intercept tap function to send Ctrl-C
            } else if (record->event.pressed) {
                tap_code16(S(KC_6)); // Intercept hold function to send Ctrl-V
            }
            return false;
        case LT(0, KC_7):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_7); // Intercept tap function to send Ctrl-C
            } else if (record->event.pressed) {
                tap_code16(S(KC_7)); // Intercept hold function to send Ctrl-V
            }
            return false;
        case LT(0, KC_8):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_8); // Intercept tap function to send Ctrl-C
            } else if (record->event.pressed) {
                tap_code16(S(KC_8)); // Intercept hold function to send Ctrl-V
            }
            return false;
        case LT(0, KC_9):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_9); // Intercept tap function to send Ctrl-C
            } else if (record->event.pressed) {
                tap_code16(S(KC_9)); // Intercept hold function to send Ctrl-V
            }
            return false;
        case LT(0, KC_0):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_0); // Intercept tap function to send Ctrl-C
            } else if (record->event.pressed) {
                tap_code16(S(KC_0)); // Intercept hold function to send Ctrl-V
            }
            return false;
        case LT(0, KC_Q):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_Q); // Intercept tap function to send Ctrl-C
            } else if (record->event.pressed) {
                tap_code16(S(KC_Q)); // Intercept hold function to send Ctrl-V
            }
            return false;
        case LT(0, KC_W):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_W); // Intercept tap function to send Ctrl-C
            } else if (record->event.pressed) {
                tap_code16(S(KC_W)); // Intercept hold function to send Ctrl-V
            }
            return false;
        case LT(0, KC_E):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_E); // Intercept tap function to send Ctrl-C
            } else if (record->event.pressed) {
                tap_code16(S(KC_E)); // Intercept hold function to send Ctrl-V
            }
            return false;
        case LT(0, KC_R):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_R); // Intercept tap function to send Ctrl-C
            } else if (record->event.pressed) {
                tap_code16(S(KC_R)); // Intercept hold function to send Ctrl-V
            }
            return false;
        case LT(0, KC_T):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_T); // Intercept tap function to send Ctrl-C
            } else if (record->event.pressed) {
                tap_code16(S(KC_T)); // Intercept hold function to send Ctrl-V
            }
            return false;
        case LT(0, KC_A):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_A); // Intercept tap function to send Ctrl-C
            } else if (record->event.pressed) {
                tap_code16(S(KC_A)); // Intercept hold function to send Ctrl-V
            }
            return false;
        case LT(0, KC_S):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_S); // Intercept tap function to send Ctrl-C
            } else if (record->event.pressed) {
                tap_code16(S(KC_S)); // Intercept hold function to send Ctrl-V
            }
            return false;
        case LT(0, KC_D):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_D); // Intercept tap function to send Ctrl-C
            } else if (record->event.pressed) {
                tap_code16(S(KC_D)); // Intercept hold function to send Ctrl-V
            }
            return false;
        case LT(0, KC_F):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_F); // Intercept tap function to send Ctrl-C
            } else if (record->event.pressed) {
                tap_code16(S(KC_F)); // Intercept hold function to send Ctrl-V
            }
            return false;
        case LT(0, KC_G):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_G); // Intercept tap function to send Ctrl-C
            } else if (record->event.pressed) {
                tap_code16(S(KC_G)); // Intercept hold function to send Ctrl-V
            }
            return false;
        case LT(0, KC_Z):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_Z); // Intercept tap function to send Ctrl-C
            } else if (record->event.pressed) {
                tap_code16(S(KC_Z)); // Intercept hold function to send Ctrl-V
            }
            return false;
        case LT(0, KC_X):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_X); // Intercept tap function to send Ctrl-C
            } else if (record->event.pressed) {
                tap_code16(S(KC_X)); // Intercept hold function to send Ctrl-V
            }
            return false;
        case LT(0, KC_C):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_C); // Intercept tap function to send Ctrl-C
            } else if (record->event.pressed) {
                tap_code16(S(KC_C)); // Intercept hold function to send Ctrl-V
            }
            return false;
        case LT(0, KC_V):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_V); // Intercept tap function to send Ctrl-C
            } else if (record->event.pressed) {
                tap_code16(S(KC_V)); // Intercept hold function to send Ctrl-V
            }
            return false;
        case LT(0, KC_B):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_B); // Intercept tap function to send Ctrl-C
            } else if (record->event.pressed) {
                tap_code16(S(KC_B)); // Intercept hold function to send Ctrl-V
            }
            return false;
        case LT(0, KC_Y):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_Y); // Intercept tap function to send Ctrl-C
            } else if (record->event.pressed) {
                tap_code16(S(KC_Y)); // Intercept hold function to send Ctrl-V
            }
            return false;
        case LT(0, KC_U):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_U); // Intercept tap function to send Ctrl-C
            } else if (record->event.pressed) {
                tap_code16(S(KC_U)); // Intercept hold function to send Ctrl-V
            }
            return false;
        case LT(0, KC_I):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_I); // Intercept tap function to send Ctrl-C
            } else if (record->event.pressed) {
                tap_code16(S(KC_I)); // Intercept hold function to send Ctrl-V
            }
            return false;
        case LT(0, KC_O):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_O); // Intercept tap function to send Ctrl-C
            } else if (record->event.pressed) {
                tap_code16(S(KC_O)); // Intercept hold function to send Ctrl-V
            }
            return false;
        case LT(0, KC_P):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_P); // Intercept tap function to send Ctrl-C
            } else if (record->event.pressed) {
                tap_code16(S(KC_P)); // Intercept hold function to send Ctrl-V
            }
            return false;
        case LT(0, KC_H):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_H); // Intercept tap function to send Ctrl-C
            } else if (record->event.pressed) {
                tap_code16(S(KC_H)); // Intercept hold function to send Ctrl-V
            }
            return false;
        case LT(0, KC_J):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_J); // Intercept tap function to send Ctrl-C
            } else if (record->event.pressed) {
                tap_code16(S(KC_J)); // Intercept hold function to send Ctrl-V
            }
            return false;
        case LT(0, KC_K):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_K); // Intercept tap function to send Ctrl-C
            } else if (record->event.pressed) {
                tap_code16(S(KC_K)); // Intercept hold function to send Ctrl-V
            }
            return false;
        case LT(0, KC_L):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_L); // Intercept tap function to send Ctrl-C
            } else if (record->event.pressed) {
                tap_code16(S(KC_L)); // Intercept hold function to send Ctrl-V
            }
            return false;
        case LT(0, KC_N):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_N); // Intercept tap function to send Ctrl-C
            } else if (record->event.pressed) {
                tap_code16(S(KC_N)); // Intercept hold function to send Ctrl-V
            }
            return false;
        case LT(0, KC_M):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_M); // Intercept tap function to send Ctrl-C
            } else if (record->event.pressed) {
                tap_code16(S(KC_M)); // Intercept hold function to send Ctrl-V
            }
            return false;
        case LT(0, KC_COMM):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_COMM); // Intercept tap function to send Ctrl-C
            } else if (record->event.pressed) {
                tap_code16(S(KC_COMM)); // Intercept hold function to send Ctrl-V
            }
            return false;
        case LT(0, KC_DOT):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_DOT); // Intercept tap function to send Ctrl-C
            } else if (record->event.pressed) {
                tap_code16(S(KC_DOT)); // Intercept hold function to send Ctrl-V
            }
            return false;
        case LT(0, KC_SLSH):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_SLSH); // Intercept tap function to send Ctrl-C
            } else if (record->event.pressed) {
                tap_code16(S(KC_SLSH)); // Intercept hold function to send Ctrl-V
            }
            return false;
        case LT(0, KC_SCLN):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_SCLN); // Intercept tap function to send Ctrl-C
            } else if (record->event.pressed) {
                tap_code16(S(KC_SCLN)); // Intercept hold function to send Ctrl-V
            }
            return false;
        case LT(0, KC_QUOT):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_QUOT); // Intercept tap function to send Ctrl-C
            } else if (record->event.pressed) {
                tap_code16(S(KC_QUOT)); // Intercept hold function to send Ctrl-V
            }
            return false;
        case LT(0, KC_NUBS):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_NUBS); // Intercept tap function to send Ctrl-C
            } else if (record->event.pressed) {
                tap_code16(S(KC_NUBS)); // Intercept hold function to send Ctrl-V
            }
            return false;
        case LT(0, KC_GRV):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_GRV); // Intercept tap function to send Ctrl-C
            } else if (record->event.pressed) {
                tap_code16(S(KC_GRV)); // Intercept hold function to send Ctrl-V
            }
            return false;
        case LT(0, KC_BTN1):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_BTN1); // Intercept tap function to send Ctrl-C
            } else if (record->event.pressed) {
                tap_code16(KC_BTN2); // Intercept hold function to send Ctrl-V
            }
            return false;
    }
    return true;
}
