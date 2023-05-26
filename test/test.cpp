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

/*CTEST (ctest, aroundHitCheck) {
    bool aroundHitTrue = aroundHit(int Grid[size + 2][size + 2], int x, int y) ;
    ASSERT_TRUE(aroundHitTrue);
    

    bool aroundHitFalse = aroundHit(int Grid[size + 3][size + 2], int x) ;
    ASSERT_FALSE(aroundHitFalse);
}

CTEST (ctest, computerHitCheck) {
    bool computerHitTrue = computerHit(int Grid[size + 2][size + 2], int hits, int& x, int& y) ;
    ASSERT_TRUE(computerHitTrue);
    

    bool computerHit = computerHit(int Grid[size + 3][size + 2], int& x, int& y) ;
    ASSERT_FALSE(computerHitFalse);
}*/
