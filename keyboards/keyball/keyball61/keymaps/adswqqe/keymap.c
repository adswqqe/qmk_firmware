/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)
Modified based on user feedback for Unity/C# development and small hands ergonomics.
*/

#include QMK_KEYBOARD_H
#include "quantum.h"

// Define aliases for complex keycodes for clarity
#define C_Z LCTL(KC_Z) // 실행 취소 (Undo)
#define C_X LCTL(KC_X) // 잘라내기 (Cut)
#define C_C LCTL(KC_C) // 복사 (Copy)
#define C_V LCTL(KC_V) // 붙여넣기 (Paste)
#define C_A LCTL(KC_A) // 전체 선택 (Select All)
#define C_S LCTL(KC_S) // 저장 (Save)
#define C_D LCTL(KC_D) // 복제 (Duplicate - Unity)
#define C_F LCTL(KC_F) // 찾기 (Find)

// Define layer activation keys using LT on thumbs for better ergonomics
// Assuming a 3+3 thumb cluster layout
#define DEV_LAYER LT(1, KC_BSPC) // 개발 레이어 (오른쪽 엄지, 홀드: L1, 탭: Bksp)
#define FN_LAYER LT(2, KC_SPC)   // Fn/탐색 레이어 (왼쪽 엄지, 홀드: L2, 탭: Space)
#define SYS_LAYER LT(3, KC_LNG1) // 시스템 레이어 (오른쪽 엄지, 홀드: L3, 탭: Lang1)

enum custom_keycodes {
    CST = SAFE_RANGE,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // [0] = Base Layer (Standard QWERTY, Thumb cluster layer activation)
  [0] = LAYOUT_universal(
    KC_ESC   , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , KC_6    ,                          KC_7    , KC_8    , KC_9    , KC_0    , KC_DEL  , // Backspace moved to thumb, Del here
    KC_TAB   , KC_Q    , KC_W    , KC_E    , KC_R    , KC_T    ,                          KC_Y    , KC_U    , KC_I    , KC_O    , KC_P    , KC_NUBS ,
    KC_CAPS  , KC_A    , KC_S    , KC_D    , KC_F    , KC_G    ,                          KC_H    , KC_J    , KC_K    , KC_L    , KC_SCLN , KC_QUOT , // MO(1) removed, CapsLock here
    KC_LSFT  , KC_Z    , KC_X    , KC_C    , KC_V    , KC_B    , KC_LBRC ,        KC_RBRC , KC_N    , KC_M    , KC_COMM , KC_DOT  , KC_SLSH , KC_RSFT ,
    KC_LCTL  , KC_LGUI , KC_LALT , FN_LAYER, SCRL_MO , KC_SPC  , DEV_LAYER,       KC_ENT  , SYS_LAYER,_______ , _______ , _______ , KC_RALT , _______ // Layer keys moved to thumbs
    // Left Thumb : FN_LAYER (LT(2,KC_SPC)), SCRL_MO, KC_SPC
    // Right Thumb: DEV_LAYER (LT(1,KC_BSPC)), KC_ENT, SYS_LAYER (LT(3,KC_LNG1))
  ),

  // [1] = Dev Layer (Symbols & Shortcuts for C# / Unity) - Activated by DEV_LAYER (Right Thumb Hold)
  [1] = LAYOUT_universal(
    KC_GRV   , S(KC_1) , S(KC_2) , S(KC_3) , S(KC_4) , S(KC_5) , S(KC_6) ,                        S(KC_7) , S(KC_8) , S(KC_9) , S(KC_0) , _______ , // ` !@#$%^ &*() Del(from L0)
    _______  , KC_MINS , KC_EQL  , KC_LCBR , KC_RCBR , KC_LBRC ,                        KC_RBRC , KC_UNDS , KC_PLUS , _______ , _______ , KC_BSLS , //   - = {}[]  _+     
    _______  , C_A     , C_S     , C_D     , C_F     , _______ ,                        _______ , _______ , _______ , _______ , KC_COLN , KC_SCLN , //   Ctrl+A/S/D/F         : ;
    _______  , C_Z     , C_X     , C_C     , C_V     , CST     , _______ ,      _______ , KC_TILD , _______ , S(KC_COMM), S(KC_DOT), S(KC_SLSH), _______ , //   Undo/Cut/Copy/Paste CST    ~   < > ?
    _______  , _______ , _______ , _______ , _______ , _______ , _______ ,      _______ , _______ , _______ , _______ , _______ , _______ , _______   // Keep modifiers transparent
  ),

  // [2] = Fn/Navigation Layer - Activated by FN_LAYER (Left Thumb Hold)
  [2] = LAYOUT_universal(
    _______  , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   ,                        KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  ,
    _______  , _______ , _______ , _______ , _______ , _______ ,                        KC_PGUP , KC_HOME , KC_UP   , KC_END  , _______ , KC_F12  ,
    _______  , KC_LCTL , KC_LSFT , KC_LGUI , KC_LALT , _______ ,                        KC_PGDN , KC_LEFT , KC_DOWN , KC_RGHT , _______ , _______ ,
    _______  , _______ , _______ , _______ , _______ , _______ , _______ ,      _______ , _______ , KC_BTN1 , KC_BTN3 , KC_BTN2 , _______ , _______ , // Mouse Buttons here
    _______  , _______ , _______ , _______ , _______ , _______ , _______ ,      _______ , _______ , _______ , _______ , _______ , _______ , _______
  ),

  // [3] = System Layer (RGB, Audio, Mouse CPI, System Controls) - Activated by SYS_LAYER (Right Thumb Hold)
  [3] = LAYOUT_universal(
    RGB_TOG  , _______  , _______  , _______  , _______  , _______  ,                          RGB_M_P  , RGB_M_B  , RGB_M_R  , RGB_M_SW , RGB_M_SN , RGB_M_K  ,
    AML_D50  , RGB_HUI  , RGB_SAI  , RGB_VAI  , _______  , _______  ,                          RGB_M_X  , RGB_M_G  , RGB_M_T  , RGB_M_TW , _______  , _______  ,
    AML_I50  , RGB_HUD  , RGB_SAD  , RGB_VAD  , _______  , _______  ,                          CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , KBC_SAVE , KBC_RST  ,
    AML_TO   , _______  , SCRL_DVD , SCRL_DVI , SCRL_MO  , SCRL_TO  , EE_CLR   ,       EE_CLR   , KC_HOME  , KC_PGDN  , KC_PGUP  , KC_END   , _______  , _______  ,
    QK_BOOT  , _______  , KC_LEFT  , KC_DOWN  , KC_UP    , KC_RGHT  , _______  ,       _______  , KC_BSPC  , _______  , _______  , _______  , _______  , QK_BOOT
  )
};
// clang-format on

// 주석 처리된 함수들은 이전과 동일하게 유지 (오토마우스, 자동 스크롤 비활성화)
// layer_state_t layer_state_set_user(layer_state_t state) { ... }
// void pointing_device_init_user(void) { ... }

#ifdef OLED_ENABLE
#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CST:
            if (record->event.pressed) {
                tap_code16(C(S(KC_T))); // Ctrl+Shift+T 매크로로 추정
                // If CST is intended to be activated ONLY when Dev Layer is active,
                // you might need layer checking here: if (layer_state_is(1)) { ... }
                return false; // Processed here
            }
            break; // Added break statement
            // Add other custom keycode processing if needed
    }
    return true; // Process all other keycodes normally
}
