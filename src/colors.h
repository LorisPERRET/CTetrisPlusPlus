#include "raylib.h"
#include <vector>

#ifndef __COLORS_H__
#define __COLORS_H__

extern const Color darkGrey;
extern const Color green;
extern const Color red;
extern const Color orange;
extern const Color yellow;
extern const Color purple;
extern const Color cyan;
extern const Color blue;
extern const Color lightBlue;
extern const Color darkBlue;

std::vector<Color> GetCellColors();

#endif // __COLORS_H__