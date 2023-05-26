#include "../thirdparty/ctest.h"

#include "../src/game15_logic/game15_logic.h"

CTEST (ctest, zeroGridCheck) {
	int Gridp[12][12];
	int Gridc[12][12];
    bool checkzeroGridTrue = zeroGrid(Gridp, Gridc) ;
    ASSERT_TRUE(!checkzeroGridTrue);
}

CTEST (ctest, Ship_placementCheck) {
	int b[12][12];
	for (int i = 0; i < 11; i++){
		for (int j = 0; j < 11; j++){
			b[i][j] = 0;
		}
	}
	int attempt = 0;
	for (int i = 1; i < 10; i++){
		if (Ship_placement(b) == 0){
			attempt++;
			for (int i = 0; i < 11; i++){
				for (int j = 0; j < 11; j++){
					b[i][j] = 0;
				}
			}
		}
	}
	bool checkShip_placementTrue = 1;
	if (attempt == 10){
		checkShip_placementTrue = 0;
	}
    ASSERT_TRUE(checkShip_placementTrue);
}

CTEST (ctest, aroundHitCheck) {
	int Grid[12][12];
	int x = 5;
	int y = 6;
    bool aroundHitTrue = aroundHit(Grid, x, y) ;
    ASSERT_TRUE(!aroundHitTrue);
}

CTEST (ctest, isSunkCheck) {
	int Grid[12][12];
	for (int i = 0; i < 11; i++){
		for (int j = 0; j < 11; j++){
			Grid[i][j] = 0;
		}
	}
	int x = 5;
	int y = 6;
    bool isSunkTrue = isSunk(x, y, Grid);
    ASSERT_TRUE(isSunkTrue);
}

CTEST (ctest, AroundCellCheck) {
	int b[12][12];
	for (int i = 0; i < 11; i++){
		for (int j = 0; j < 11; j++){
			b[i][j] = 0;
		}
	}
	int x = 5;
	int y = 6;
    bool AroundCellTrue = AroundCell(x, y, b);
    ASSERT_TRUE(!AroundCellTrue);
}

CTEST (ctest, checkforHitCheck) {
	int b[12][12];
	for (int i = 0; i < 11; i++){
		for (int j = 0; j < 11; j++){
			b[i][j] = 0;
		}
	}
    bool checkforHitTrue = checkforHit(b);
    ASSERT_TRUE(!checkforHitTrue);
}

CTEST (ctest, computerHitCheck) {
	int Grid[12][12];
	for (int i = 0; i < 11; i++){
		for (int j = 0; j < 11; j++){
			Grid[i][j] = 0;
		}
	}
	int tempx = 5;
	int tempy = 6;
    bool computerHitTrue = computerHit(Grid, 0, tempx, tempy);
    ASSERT_TRUE(!computerHitTrue);
}
