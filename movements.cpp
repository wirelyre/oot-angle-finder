#include "angle_finder.h"

angle ess_up_adjust          (angle in) { return in + 1; } // TODO

angle ess_left               (angle in) { return in + 0x0708; }
angle ess_right              (angle in) { return in - 0x0708; }
angle turn_left              (angle in) { return ess_up_adjust(in) + 0x4000; }
angle turn_right             (angle in) { return ess_up_adjust(in) - 0x4000; }
angle turn_180               (angle in) { return ess_up_adjust(in) + 0x8000; }
angle sidehop_sideroll_left  (angle in) { return in + 0x1CD8; }
angle sidehop_sideroll_right (angle in) { return in - 0x1CD8; }
angle backflip_sideroll      (angle in) { return in - 0x3A98; }
angle kokiri_spin            (angle in) { return in - 0x0CCD; }
angle biggoron_spin          (angle in) { return in + 0x1219; }
angle hammer_shield_cancel   (angle in) { return in - 0x0F90; }
angle biggoron_spin_shield   (angle in) { return in + 0x04F5; }

angle shield_top_right    (angle in) { in = ess_up_adjust(in); return in ? in - 0x2000 : 0; }
angle shield_top_left     (angle in) { in = ess_up_adjust(in); return in ? in + 0x2000 : 0; }
angle shield_bottom_left  (angle in) { in = ess_up_adjust(in); return in ? in + 0x6000 : 0; }
angle shield_bottom_right (angle in) { in = ess_up_adjust(in); return in ? in - 0x6000 : 0; }

angle ess_down_sideroll(angle in) {
    bool left = true;
    angle camera = ess_up_adjust(in);
    if (camera == 0)  left = false;
    if (camera >= in) left = false;
    return left ? (in + 0x3A98) : (in - 0x3A98);
}

angle (*const MOVEMENTS[])(angle) = {
    [NONE]                   = 0,
    [ESS_UP]                 = ess_up_adjust,
    [ESS_LEFT]               = ess_left,
    [ESS_RIGHT]              = ess_right,
    [TURN_LEFT]              = turn_left,
    [TURN_RIGHT]             = turn_right,
    [TURN_180]               = turn_180,
    [SIDEHOP_SIDEROLL_LEFT]  = sidehop_sideroll_left,
    [SIDEHOP_SIDEROLL_RIGHT] = sidehop_sideroll_right,
    [ESS_DOWN_SIDEROLL]      = ess_down_sideroll,
    [BACKFLIP_SIDEROLL]      = backflip_sideroll,
    [KOKIRI_SPIN]            = kokiri_spin,
    [BIGGORON_SPIN]          = biggoron_spin,
    [BIGGORON_SPIN_SHIELD]   = biggoron_spin_shield,
    [HAMMER_SHIELD_CANCEL]   = hammer_shield_cancel,
    [SHIELD_TOP_RIGHT]       = shield_top_right,
    [SHIELD_TOP_LEFT]        = shield_top_left,
    [SHIELD_BOTTOM_LEFT]     = shield_bottom_left,
    [SHIELD_BOTTOM_RIGHT]    = shield_bottom_right,
};
