#include "../thirdparty/ctest.h"

#include "../src/game15_logic/game15_logic.h"
#include "../src/game15_graph/game15_graph.h"

/*CTEST (ctest, zeroGridCheck) {
	int Gridp[size + 2][size + 2];
	int Gridc[size + 2][size + 2];
	int Gridpf[size + 3][size + 4];
	int Gridcf[size + 4][size + 2];
    bool checkzeroGridTrue = zeroGrid(Gridp, Gridc) ;
    ASSERT_TRUE(checkzeroGridTrue);
    

    bool checkzeroGridFalse = zeroGrid(Gridpf, Gridcf) ;
    ASSERT_FALSE(checkzeroGridFalse);
}

CTEST (ctest, Ship_placementCheck) {
    bool checkShip_placementTrue = Ship_placement(int b[size + 2][size + 2], int size);
    ASSERT_TRUE(checkShip_placementTrue);
    

    bool checkShip_placementFalse = Ship_placement(int b[size + 3][size + 4], int size);
    ASSERT_FALSE(checkShip_placementFalse);
}

CTEST (ctest, aroundHitCheck) {
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
CTEST (ctest, loadFromFile) {
    Texture screenTrue;
    bool checkScreenTrue = screenTrue.loadFromFile("../external/images/sea.jpg") ;
    ASSERT_TRUE(checkScreenTrue);
    

    Texture screenFalse;
    bool checkScreenFalse = screenFalse.loadFromFile("../external/images/shfghea.jpg") ;
    ASSERT_FALSE(checkScreenFalse);
}
