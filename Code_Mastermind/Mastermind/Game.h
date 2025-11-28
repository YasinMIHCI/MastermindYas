#pragma once
#include <stdlib.h>
#include <stdio.h>
#include "Combo.h"
#include "config.h"
#include "Gamestate.h"


void Mastermind();  // la fonction principal qui aura la boucle de jeux
void game();   // La fonction qui lance le jeux 
void GenerateRandomCode(COMBO* combo); 