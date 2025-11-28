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
    int partialMatches = 0;
    int perfectMatches = 0;

    for (int i = 0; i < COMBO_SIZE; i++) {
        if (combo->result[i] == PARTIAL) {
            partialMatches++;
        }
        else if (combo->result[i] == CORRECT) {
            perfectMatches++;
        }
    }

    printf("%c %c %c %c | Partiel : %d | Correct : %d\n",
        Color_to_char(combo->attempt[0]),
        Color_to_char(combo->attempt[1]),
        Color_to_char(combo->attempt[2]),
        Color_to_char(combo->attempt[3]),
        partialMatches,
        perfectMatches
    );
}
