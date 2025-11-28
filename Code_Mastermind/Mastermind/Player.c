#include "Player.h"
#include <stdio.h>
#include <ctype.h>

void AskPlayerGuess(COMBO* guess)
{
    char input[COMBO_SIZE+1]; // +1 pour le caractère de fin '\0'
    int validInput = 0;

    printf("Entrez votre combinaison de 4 couleurs parmis ces couleurs disponible (Y, B, R, G, W, P) : \n");

    while (!validInput) {
        printf("Votre tentative : ");
        scanf_s("%s", input, COMBO_SIZE+1);

        for (int i = 0; input[i] != '\0'; i++) {
            input[i] = toupper(input[i]);  // Convertion en majuscule
        }

        // Vérifier qu'on a exactement 4 caractères 
        if (strlen(input) != COMBO_SIZE) {
            printf("Erreur : Vous devez entrer exactement %d couleurs.\n", COMBO_SIZE);
            continue;
        }

        // Vérifier que toutes les couleurs sont valides
        int allValid = 1;
        for (int i = 0; i < COMBO_SIZE; i++) {
            if (!IsValidColor(input[i])) {
                allValid = 0;
                continue;
            }
        }

        if (allValid) {
            validInput = 1;
            // Remplir le combo avec les couleurs
            for (int i = 0; i < COMBO_SIZE; i++) {
                int colorIndex = GetColorIndex(input[i]);
                int colorValue = colorIndex + 1;  // Décalage de 1 car NONE est en premier
                guess->attempt[i] = colorValue;
                guess->result[i] = UNCHECKED;
            }
        }
        else {
            printf("Erreur : Couleurs invalides.\n");
            printf("Couleurs disponibles : Y (Yellow), B (Blue), R (Red), G (Green), W (White), P (Purple)\n");
        }
    }

    PrintCombo(guess);
}

int IsValidColor(char colorChar)
{
    char* validColors = getColorsList();
    for (int i = 0; validColors[i] != '\0'; i++) {
        if (colorChar == validColors[i]) {
            return 1;
        }
    }
    return 0;
}



