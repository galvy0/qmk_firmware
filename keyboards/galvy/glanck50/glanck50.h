#pragma once

#include "quantum.h"

#define XXX KC_NO

#define LAYOUT( \
      k00, k01, k02, k03, k04,                             k0B, \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1A, k1B, \
    k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2A, k2B, \
       k31, k32, k33, k34, k35, k36, k37, k38, k39, k3A, k3B, \
           k42,      k44,   k46,    k47,    k49,        k4B \
) { \
    { k00, k01, k02, k03, k04, XXX, XXX, XXX, XXX, XXX, XXX, k0B }, \
    { k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1A, k1B }, \
    { k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2A, k2B }, \
    { XXX, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3A, k3B }, \
    { XXX, XXX, k42, XXX, k44, XXX, k46, k47, XXX, k49, XXX, k4B } \
}

