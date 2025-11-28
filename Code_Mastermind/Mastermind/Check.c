#include "Check.h"



void CheckCorrectPositions(COMBO* playerAttempt, COMBO* secretCode, int* secretUsed, int* attemptUsed, int* correctCount) {
    for (int i = 0; i < COMBO_SIZE; i++) {
        if (playerAttempt->attempt[i] == secretCode->attempt[i]) {
            (*correctCount)++;  // parenthese importante 
            secretUsed[i] = 1;
            attemptUsed[i] = 1;
            playerAttempt->result[i] = CORRECT;
        }
        else {
            playerAttempt->result[i] = UNCHECKED;
        }
    }
}


void CheckPartialMatches(COMBO* playerAttempt, COMBO* secretCode, int* secretUsed, int* attemptUsed) {
    for (int i = 0; i < COMBO_SIZE; i++) {
        if (attemptUsed[i] == 0) {
            for (int j = 0; j < COMBO_SIZE; j++) {
                if (secretUsed[j] == 0 && playerAttempt->attempt[i] == secretCode->attempt[j]) {
                    secretUsed[j] = 1;
                    playerAttempt->result[i] = PARTIAL;
                    break;
                }
            }
        }
    }
}


void InitializeUsedTable(int* secretUsed, int* attemptUsed) {
    for (int i = 0; i < COMBO_SIZE; i++) {
        secretUsed[i] = 0;
        attemptUsed[i] = 0;
    }
}

void MarkWrongPositions(COMBO* playerAttempt) {
    for (int i = 0; i < COMBO_SIZE; i++) {
        if (playerAttempt->result[i] == UNCHECKED) {
            playerAttempt->result[i] = WRONG;
        }
    }
}


int CheckAttempt(COMBO* playerAttempt, COMBO* secretCode) {
    int correctCount = 0;
    int secretUsed[COMBO_SIZE];
    int attemptUsed[COMBO_SIZE];

    InitializeUsedTable(secretUsed, attemptUsed);
    CheckCorrectPositions(playerAttempt, secretCode, secretUsed, attemptUsed, &correctCount);
    CheckPartialMatches(playerAttempt, secretCode, secretUsed, attemptUsed);
    MarkWrongPositions(playerAttempt);

    return correctCount;
}