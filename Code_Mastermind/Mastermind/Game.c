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
	printf("Jeux");
}
