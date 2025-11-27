#pragma once
#include "Color.h"
#include "sol.h"
#include "config.h"

typedef struct combo {
    enum color attempt[COMBO_SIZE];
    enum sol result[COMBO_SIZE];
} COMBO;


void initUnckeckCombo(COMBO* combo);   // cree un pointeur sur une combinaison qu'on pourra utiliser (initialiser a UNCHECKED)
void PrintCombo(COMBO* combo);  // affiche la combinaison actuel ( essai + resultat )