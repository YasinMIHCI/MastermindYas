#pragma once

#include "Combo.h"
#include "config.h"
#include <stdio.h>

typedef struct Gamestate {
	int CurrentTurn;
	COMBO SecretCombo;
	COMBO ComboHistory[MAX_TURNS];
} GameState;	


void PrintHistory(GameState* state); // Affiche l'historique des tentatives
void InitializeGame(GameState* state); // Fonction qui va tout iniatialiser cote memoire du jeux (elle va maintenant s'occuper de generer le code secret ou réinitialise l'historique des tentatives par exmeple)