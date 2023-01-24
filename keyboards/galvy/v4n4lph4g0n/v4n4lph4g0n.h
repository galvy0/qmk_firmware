#pragma once

#include "quantum.h"

#define XXX KC_NO

#define LAYOUT( \
    k00, k01, k02, k03, k04, k05,      \
    k10, k11, k12, k13, k14, k15,      k16, k17, k18, k19, k1A, k1B, \
    k20, k21, k22, k23, k24, k25,      k26, k27, k28, k29, k2A, k2B, \
    k30, k31, k32, k33, k34, k35,           k37, k38, k39, k3A, k3B, \
    k40, k41, k42, k43, k44,                k47, k48, k49, k4A, k4B \
) { \
    { k00, k01, k02, k03, k04, k05, XXX, XXX, XXX, XXX, XXX, XXX }, \
    { k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1A, k1B }, \
    { k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2A, k2B }, \
    { k30, k31, k32, k33, k34, k35, XXX, k37, k38, k39, k3A, k3B }, \
    { k40, k41, k42, k43, k44, XXX, XXX, k47, k48, k49, k4A, k4B } \
}

