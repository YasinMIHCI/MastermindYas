#pragma once
#include "Color.h"
#include "sol.h"
#include "config.h"

typedef struct combo {
    enum color attempt[COMBO_SIZE];
    enum sol result[COMBO_SIZE];
} COMBO;


void initEmptyCombo(COMBO* combo);