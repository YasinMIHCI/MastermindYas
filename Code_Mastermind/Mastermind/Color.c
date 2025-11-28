#include "Color.h"


char* getColorsList() {
    return "YBRGWP";
}

char Color_to_char(enum color color) {
    char procceded_color;
    switch (color) {
    case Y:
        procceded_color = 'Y';
        break;
    case B:
        procceded_color = 'B';
        break;
    case R:
        procceded_color = 'R';
        break;
    case G:
        procceded_color = 'G';
        break;
    case W:
        procceded_color = 'W';
        break;
    case P:
        procceded_color = 'P';
        break;
    case NONE:
        procceded_color = 'N';
        break;
    }
    return procceded_color;

}

int GetColorIndex(char colorChar)
{
    char* colorList = getColorsList();
    for (int i = 0; colorList[i] != '\0'; i++) {
        if (colorChar == colorList[i]) {
            return i;
        }
    }
    return -1;  // Couleur non trouvée
}

/*enum color char_to_Color(char character) {
    switch (character) {
    case 'Y': return Y;
    case 'B': return B;
    case 'R': return R;
    case 'G': return G;
    case 'W': return W;
    case 'P': return P;
    default: return NONE;
    }
}*/