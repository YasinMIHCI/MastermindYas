#pragma once
#include "Combo.h"


int CheckAttempt(COMBO* playerAttempt, COMBO* secretCode);   // Traite le guess et renvoie le nombre de lettre coorrect
void InitializeUsedTable(int* secretUsed, int* attemptUsed);  // Initialiser les deux tableaux de suivi à 0 (non utilisé), met toutes les positions à 0 pour indiquer qu'aucune couleur n'a encore été traitée
void CheckCorrectPositions(COMBO* playerAttempt, COMBO* secretCode, int* secretUsed, int* attemptUsed, int* correctCount); //Vérifier les couleurs à la bonne position 
void CheckPartialMatches(COMBO* playerAttempt, COMBO* secretCode, int* secretUsed, int* attemptUsed);  //Vérifier les couleurs à la mauvaise position 
void MarkWrongPositions(COMBO* playerAttempt);  //Marquer les couleurs incorrectes, Tout ce qui est encore UNCHECKED devient WRONG