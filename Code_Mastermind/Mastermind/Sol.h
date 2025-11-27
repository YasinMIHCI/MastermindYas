#pragma once

enum sol { UNCHECKED, WRONG, PARTIAL, CORRECT };

char Sol_to_char(enum sol result); // transforme une solution en char pour etre traite ( dans printCombo )
