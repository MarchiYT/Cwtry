#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

int drawGrid(RenderWindow& window, int Gridp[10 + 2][10 + 2], int Gridc[10 + 2][10 + 2], bool isPlayerGrid);

int initGraphic();
