#pragma once
#include <cmath>
#include <ctime>

int AroundCell(int i, int j, int b[10 + 2][10 + 2]);

int Ship_placement(int b[10 + 2][10 + 2], int 10);

bool isSunk(int x, int y, int Grid[10 + 2][10 + 2], int 10);

int timer();

int zeroGrid(int Gridp[10 + 2][10 + 2], int Gridc[10 + 2][10 + 2]);

int aroundHit(int Grid[10 + 2][10 + 2], int x, int y);

int checkforHit(int Grid[10 + 2][10 + 2]);

int computerHit(int Grid[10 + 2][10 + 2], int hits, int& x, int& y);

