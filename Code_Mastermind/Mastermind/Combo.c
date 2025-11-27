#include <stdio.h>
#include "Combo.h"

void initEmptyCombo(COMBO* combo) {
    for (int i = 0; i < COMBO_SIZE; i++) {
        combo->attempt[i] = NONE;
        combo->result[i] = UNCHECKED;
    }
}