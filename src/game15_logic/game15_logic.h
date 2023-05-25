#pragma once
#pragma warning(disable:6385)
#pragma warning(disable:6386)
#pragma warning(disable:4244)
#include <cmath>
#include <ctime>

int AroundCell(int i, int j, int b[gridsize + 2][gridsize + 2]);

int Ship_placement(int b[gridsize + 2][gridsize + 2], int gridsize);

bool isSunk(int x, int y, int Grid[gridsize + 2][gridsize + 2], int gridsize);

int timer();

int zeroGrid(int Gridp[gridsize + 2][gridsize + 2], int Gridc[gridsize + 2][gridsize + 2]);

int aroundHit(int Grid[gridsize + 2][gridsize + 2], int x, int y);

int checkforHit(int Grid[gridsize + 2][gridsize + 2]);

int computerHit(int Grid[gridsize + 2][gridsize + 2], int hits, int& x, int& y);

