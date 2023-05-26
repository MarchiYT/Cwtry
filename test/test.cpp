#include "../thirdparty/ctest.h"

#include "../src/game15_logic/game15_logic.h"

CTEST (ctest, zeroGridCheck) {
	int Gridp[12][12];
	int Gridc[12][12];
    bool checkzeroGridTrue = zeroGrid(Gridp, Gridc) ;
    ASSERT_TRUE(!checkzeroGridTrue);
	

    //bool checkzeroGridFalse = zeroGrid(int Gridp[size + 2][size + 4], int Gridc[size + 3][size + 2]) ;
    //ASSERT_FALSE(checkzeroGridFalse);
}

CTEST (ctest, Ship_placementCheck) {
	int b[12][12];
    bool checkShip_placementTrue = Ship_placement(b, 12);
    ASSERT_TRUE(!checkShip_placementTrue);
    

    //bool checkShip_placementFalse = Ship_placement(int b[size + 3][size + 4], int size);
    //ASSERT_FALSE(checkShip_placementFalse);
}

CTEST (ctest, aroundHitCheck) {
	int Grid[12][12];
	int x = 5;
	int y = 6;
    bool aroundHitTrue = aroundHit(Grid, x, y) ;
    ASSERT_TRUE(!aroundHitTrue);
    

    //bool aroundHitFalse = aroundHit(int Grid[size + 3][size + 2], int x) ;
    //ASSERT_FALSE(aroundHitFalse);
}

CTEST (ctest, timerCheck) {
    bool timerTrue = timer() ;
    ASSERT_TRUE(!timerTrue);
}
