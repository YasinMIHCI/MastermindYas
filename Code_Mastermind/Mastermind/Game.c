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
	COMBO secretCode;
	COMBO playerGuess;
	int currentTurn = 0;
	int HasWin = 0;
	int correctCount;
	initUnckeckCombo(&secretCode);
	GenerateRandomCode(&secretCode);
	PrintCombo(&secretCode);
	while (currentTurn < MAX_TURNS && !HasWin) {
		AskPlayerGuess(&playerGuess);
		correctCount = CheckAttempt(&playerGuess, &secretCode);
		PrintCombo(&playerGuess);
		if (correctCount == 4) {
			printf("Code trouve\n");
			HasWin = 1;
		}
		else {
			printf("Continuez a essayer !\n");
		}
		printf("\n");
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
