#pragma once
#include <SFML/Graphics.hpp>
#include "public_variables.h"

using namespace sf;

int drawGrid(RenderWindow& window, int Gridp[size + 2][size + 2], int Gridc[size + 2][size + 2], bool isPlayerGrid);

int initGraphic();