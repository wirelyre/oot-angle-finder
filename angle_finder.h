#pragma once

#include <cstdint>

typedef uint16_t angle;

enum movement {
    NONE,

    ESS_UP,
    ESS_LEFT,
    ESS_RIGHT,
    TURN_LEFT,
    TURN_RIGHT,
    TURN_180,
    SIDEHOP_SIDEROLL_LEFT,
    SIDEHOP_SIDEROLL_RIGHT,
    ESS_DOWN_SIDEROLL,
    BACKFLIP_SIDEROLL,
    KOKIRI_SPIN,
    BIGGORON_SPIN,
    BIGGORON_SPIN_SHIELD,
    HAMMER_SHIELD_CANCEL,
    SHIELD_TOP_RIGHT,
    SHIELD_TOP_LEFT,
    SHIELD_BOTTOM_LEFT,
    SHIELD_BOTTOM_RIGHT,
};
const int MOVEMENT_COUNT = 19;

extern angle (*const MOVEMENTS[])(angle);
