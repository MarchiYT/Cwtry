#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

const int sizeg = 10;
const int cellsizeg = 50;

int drawGrid(RenderWindow& window, int Gridp[sizeg + 2][sizeg + 2], int Gridc[sizeg + 2][sizeg + 2], bool isPlayerGrid);

int initGraphic();
