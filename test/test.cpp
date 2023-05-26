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
    bool checkShip_placementTrue = Ship_placement(b, 12);
    ASSERT_TRUE(!checkShip_placementTrue);
}

CTEST (ctest, aroundHitCheck) {
	int Grid[12][12];
	int x = 5;
	int y = 6;
    bool aroundHitTrue = aroundHit(Grid, x, y) ;
    ASSERT_TRUE(!aroundHitTrue);
}

CTEST (ctest, timerCheck) {
    bool timerTrue = timer() ;
    ASSERT_TRUE(!timerTrue);
}
