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