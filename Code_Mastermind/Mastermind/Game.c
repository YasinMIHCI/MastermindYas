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

	initUnckeckCombo(&secretCode);

	PrintCombo(&secretCode);
	printf("\n");

	GenerateRandomCode(&secretCode);

	PrintCombo(&secretCode);
	printf("\n");

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
