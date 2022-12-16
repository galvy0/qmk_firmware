#pragma once

#include "quantum.h"

#define XXX KC_NO

#define LAYOUT( \
           k02, k03, k04, k05,                             k0B, \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1A, k1B, \
    k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2A, k2B, \
       k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3B, \
              k41, k42, k43, k44, k45, k46, k47 \
) { \
    { XXX, XXX, k02, k03, k04, k05, XXX, XXX, XXX, XXX, XXX, k0B }, \
    { k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1A, k1B }, \
    { k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2A, k2B }, \
    { k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, XXX, k3B }, \
    { XXX, k41, k42, k43, k44, k45, k46, k47, XXX, XXX, XXX, XXX } \
}

