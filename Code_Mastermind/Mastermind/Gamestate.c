#include "Gamestate.h"

void PrintHistory(GameState* state)
{
    printf("Historique des essaies : \n");
    printf("Tentative actuelle : %d / %d\n", state->CurrentTurn, MAX_TURNS);

    if (state->CurrentTurn == 0) {
        printf("Aucune tentative pour le moment.\n");
    }
    else {
        for (int i = 0; i < state->CurrentTurn; i++) {
            printf("Essai %d : ", i + 1);
            PrintCombo(&(state->ComboHistory[i]));
        }
    }

}

void InitializeGame(GameState* state) {
    state->CurrentTurn = 0;

    initUnckeckCombo(&state->SecretCombo);
    GenerateRandomCode(&state->SecretCombo);

    for (int i = 0; i < MAX_TURNS; i++) {
        initUnckeckCombo(&state->ComboHistory[i]);
    }

    printf("Le code secret a ete genere.\n");
    printf("Vous avez %d tentatives pour le deviner.\n", MAX_TURNS);
}