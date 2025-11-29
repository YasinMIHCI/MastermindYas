#include "Game.h"


void Mastermind()
{
	printf("Bienvenue au jeux du Mastermind\n");
	int choice;
	do {
		printf("Voulez vous jouer(1) ou quitter le jeux(0) : ");
		scanf_s("%d", &choice);
		if (choice == 1) {
			game();
		}
	} while (choice != 0);
	printf("Vous aves quitter le jeux");
	exit;
}

void game()
{
	GameState gameState;
	int HasWin = 0;
	int correctCount;
	InitializeGame(&gameState); 
	
	PrintCombo(&gameState.SecretCombo);
	while (gameState.CurrentTurn < MAX_TURNS && !HasWin) {
		printf("Tentative %d sur %d\n", gameState.CurrentTurn + 1, MAX_TURNS);
		AskPlayerGuess(&gameState.ComboHistory[gameState.CurrentTurn]);
		correctCount = CheckAttempt(&gameState.ComboHistory[gameState.CurrentTurn], &gameState.SecretCombo);
		gameState.CurrentTurn++;
		PrintHistory(&gameState);
		if (correctCount == 4) {
			printf("Code trouve\n");
			HasWin = 1;
		}
		else {
			printf("Continuez a essayer !\n");
		}
		printf("\n");
	}
	if (HasWin == 0) {
		printf("Perdu, vous avez epuise vos %d tentatives\n", MAX_TURNS);
		printf("Le code secret etait : ");
		PrintCombo(&gameState.SecretCombo);
	}
	

}

void GenerateRandomCode(COMBO* combo) {
	srand(time(NULL));
	char* colorList = getColorsList();

	for (int position = 0; position < COMBO_SIZE; position++) {
		int randomIndex = rand() % NB_COLORS;
		int colorValue = randomIndex + 1;  // En premier nous avons la color NONE donc nous nous decalons de un pour obtenir la couleur souhaiter
		combo->attempt[position] = colorValue;
	}
}
