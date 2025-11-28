#pragma once
#include <string.h>

enum color { NONE, Y, B, R, G, W, P };

char* getColorsList();   //renvoie la chaine de caractere des couleurs dispo
char Color_to_char(enum color color);  // transforme une couleur en char pour etre traite ( dans printCombo )
int GetColorIndex(char colorChar);// Fonction pour obtenir l'index d'une couleur dans la liste
