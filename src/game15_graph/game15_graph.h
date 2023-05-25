#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

int drawGrid(RenderWindow& window, int Gridp[gridsize + 2][gridsize + 2], int Gridc[gridsize + 2][gridsize + 2], bool isPlayerGrid);

int initGraphic();
