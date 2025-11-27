#include <stdio.h>
#include "Combo.h"

void initUnckeckCombo(COMBO* combo)
{
    for (int i = 0; i < COMBO_SIZE; i++) {
        combo->attempt[i] = NONE;
        combo->result[i] = UNCHECKED;
    }
}

void PrintCombo(COMBO* combo)
{
    printf("%1c, %1c, %1c, %1c : %1c %1c %1c %1c", Color_to_char(combo->attempt[0]), Color_to_char(combo->attempt[1]), Color_to_char(combo->attempt[2]), Color_to_char(combo->attempt[3]), Sol_to_char(combo->result[0]), Sol_to_char(combo->result[1]), Sol_to_char(combo->result[2]), Sol_to_char(combo->result[3]));
}
