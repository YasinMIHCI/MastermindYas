#include "sol.h"

char Sol_to_char(enum sol result) {
	char procceded_result;
	switch (result)
	{
	case CORRECT:
		procceded_result = 'O';
	case WRONG:
		procceded_result = 'X';
		break;
	case PARTIAL:
		procceded_result = 'P';
		break;
	case UNCHECKED:
		procceded_result = 'U';
		break;
	}
	return procceded_result;
}