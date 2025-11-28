#pragma once

#include <stdlib.h>
#include <stdio.h>
#include "Combo.h"
typedef struct Gamestate {
	int CurrentTurn;
	COMBO SecretCombo;
	COMBO ComboHistory;
};