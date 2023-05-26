#include "../game15_graph/game15_graph.h"

Texture sand;
Texture sea;
Texture miss;
Texture explosion;
Texture ship1;
Texture ship1exp;
Texture shipedger;
Texture shipedgerexp;
Texture shipedgel;
Texture shipedgelexp;
Texture shipedget;
Texture shipedgetexp;
Texture shipedged;
Texture shipedgedexp;
Texture shipmidlr;
Texture shipmidlrexp;
Texture shipmidtd;
Texture shipmidtdexp;

int drawGrid(RenderWindow& window, int Gridp[sizeg + 2][sizeg + 2], int Gridc[sizeg + 2][sizeg + 2], bool isPlayerGrid) {
    Sprite cell;
    cell.setPosition(sf::Vector2f(cellsizeg, cellsizeg));

    float x_offset = 0.f;
    if (!isPlayerGrid) {
        x_offset = (sizeg + 2) * cellsizeg;
        for (int x = 0; x < sizeg + 2; x++) {
            for (int y = 0; y < sizeg + 2; y++) {
                cell.setPosition(x * cellsizeg + x_offset, y * cellsizeg);
                if (Gridc[x][y] == 0 || Gridc[x][y] == 1) { // ���������� ������ ��� ������� ����������
                    cell.setTexture(sea);
                    if (Gridc[x][y] != 0 && Gridc[x][y] != 1) {
                        return 1;
                    }
                }
                else if (Gridc[x][y] == 2) { // ������
                    cell.setTexture(miss);
                    if (Gridc[x][y] != 2) {
                        return 1;
                    }
                }
                else if (Gridc[x][y] == 3) { // ���������
                    cell.setTexture(explosion);
                    if (Gridc[x][y] != 3) {
                        return 1;
                    }
                }
                else if (Gridc[x][y] == 4
                    && Gridc[x + 1][y] != 1
                    && Gridc[x - 1][y] != 1
                    && Gridc[x][y + 1] != 1
                    && Gridc[x][y - 1] != 1
                    && Gridc[x + 1][y] != 3
                    && Gridc[x - 1][y] != 3
                    && Gridc[x][y + 1] != 3
                    && Gridc[x][y - 1] != 3
                    && Gridc[x + 1][y] != 4
                    && Gridc[x - 1][y] != 4
                    && Gridc[x][y + 1] != 4
                    && Gridc[x][y - 1] != 4) { // ������ �������
                    cell.setTexture(ship1exp);
                }
                else if (Gridc[x][y] == 4
                    && (Gridc[x + 1][y] == 1
                        || Gridc[x + 1][y] == 3
                        || Gridc[x + 1][y] == 4)
                    && Gridc[x - 1][y] != 1
                    && Gridc[x][y + 1] != 1
                    && Gridc[x][y - 1] != 1
                    && Gridc[x - 1][y] != 3
                    && Gridc[x][y + 1] != 3
                    && Gridc[x][y - 1] != 3
                    && Gridc[x - 1][y] != 4
                    && Gridc[x][y + 1] != 4
                    && Gridc[x][y - 1] != 4) { // ������ �������
                    cell.setTexture(shipedgerexp);
                }
                else if (Gridc[x][y] == 4
                    && (Gridc[x - 1][y] == 1
                        || Gridc[x - 1][y] == 3
                        || Gridc[x - 1][y] == 4)
                    && Gridc[x + 1][y] != 1
                    && Gridc[x][y + 1] != 1
                    && Gridc[x][y - 1] != 1
                    && Gridc[x + 1][y] != 3
                    && Gridc[x][y + 1] != 3
                    && Gridc[x][y - 1] != 3
                    && Gridc[x + 1][y] != 4
                    && Gridc[x][y + 1] != 4
                    && Gridc[x][y - 1] != 4) { // ������ �������
                    cell.setTexture(shipedgelexp);
                }
                else if (Gridc[x][y] == 4
                    && (Gridc[x][y - 1] == 1
                        || Gridc[x][y - 1] == 3
                        || Gridc[x][y - 1] == 4)
                    && Gridc[x - 1][y] != 1
                    && Gridc[x][y + 1] != 1
                    && Gridc[x + 1][y] != 1
                    && Gridc[x - 1][y] != 3
                    && Gridc[x][y + 1] != 3
                    && Gridc[x + 1][y] != 3
                    && Gridc[x - 1][y] != 4
                    && Gridc[x][y + 1] != 4
                    && Gridc[x + 1][y] != 4) { // ������ �������
                    cell.setTexture(shipedgetexp);
                }
                else if (Gridc[x][y] == 4
                    && (Gridc[x][y + 1] == 1
                        || Gridc[x][y + 1] == 3
                        || Gridc[x][y + 1] == 4)
                    && Gridc[x - 1][y] != 1
                    && Gridc[x + 1][y] != 1
                    && Gridc[x][y - 1] != 1
                    && Gridc[x - 1][y] != 3
                    && Gridc[x + 1][y] != 3
                    && Gridc[x][y - 1] != 3
                    && Gridc[x - 1][y] != 4
                    && Gridc[x + 1][y] != 4
                    && Gridc[x][y - 1] != 4) { // ������ �������
                    cell.setTexture(shipedgedexp);
                }
                else if (Gridc[x][y] == 4
                    && Gridc[x][y + 1] != 1
                    && Gridc[x][y - 1] != 1
                    && Gridc[x][y + 1] != 3
                    && Gridc[x][y - 1] != 3
                    && Gridc[x][y + 1] != 4
                    && Gridc[x][y - 1] != 4
                    && ((Gridc[x + 1][y] == 1
                        && Gridc[x - 1][y] == 1)
                        || (Gridc[x + 1][y] == 3
                            && Gridc[x - 1][y] == 3)
                        || (Gridc[x + 1][y] == 1
                            && Gridc[x - 1][y] == 3)
                        || (Gridc[x + 1][y] == 3
                            && Gridc[x - 1][y] == 1)
                        || (Gridc[x + 1][y] == 4
                            && Gridc[x - 1][y] == 4))) { // ������ �������
                    cell.setTexture(shipmidlrexp);
                }
                else if (Gridc[x][y] == 4
                    && Gridc[x + 1][y] != 1
                    && Gridc[x - 1][y] != 1
                    && Gridc[x + 1][y] != 3
                    && Gridc[x - 1][y] != 3
                    && Gridc[x + 1][y] != 4
                    && Gridc[x - 1][y] != 4
                    && ((Gridc[x][y + 1] == 1
                        && Gridc[x][y - 1] == 1)
                        || (Gridc[x][y + 1] == 3
                            && Gridc[x][y - 1] == 3)
                        || (Gridc[x][y + 1] == 1
                            && Gridc[x][y - 1] == 3)
                        || (Gridc[x][y + 1] == 3
                            && Gridc[x][y - 1] == 1)
                        || (Gridc[x][y + 1] == 4
                            && Gridc[x][y - 1] == 4))) { // ������ �������
                    cell.setTexture(shipmidtdexp);
                }
                else if (Gridc[x][y] == -1) {
                    cell.setTexture(sand);
                    if (Gridc[x][y] != -1) {
                        return 1;
                    }
                }
                window.draw(cell);
            }
        }
    }

    for (int x = 0; x < sizeg + 2; x++) {
        for (int y = 0; y < sizeg + 2; y++) {
            cell.setPosition(x * cellsizeg, y * cellsizeg);
            if (Gridp[x][y] == 0) { // ���������� ������
                cell.setTexture(sea);
                if (Gridp[x][y] != 0) {
                    return 1;
                }
            }
            else if (Gridp[x][y] == 1
                && Gridp[x + 1][y] != 1
                && Gridp[x - 1][y] != 1
                && Gridp[x][y + 1] != 1
                && Gridp[x][y - 1] != 1
                && Gridp[x + 1][y] != 3
                && Gridp[x - 1][y] != 3
                && Gridp[x][y + 1] != 3
                && Gridp[x][y - 1] != 3
                && Gridp[x + 1][y] != 4
                && Gridp[x - 1][y] != 4
                && Gridp[x][y + 1] != 4
                && Gridp[x][y - 1] != 4) { // ������ �������
                cell.setTexture(ship1);
            }
            else if (Gridp[x][y] == 4
                && Gridp[x + 1][y] != 1
                && Gridp[x - 1][y] != 1
                && Gridp[x][y + 1] != 1
                && Gridp[x][y - 1] != 1
                && Gridp[x + 1][y] != 3
                && Gridp[x - 1][y] != 3
                && Gridp[x][y + 1] != 3
                && Gridp[x][y - 1] != 3
                && Gridp[x + 1][y] != 4
                && Gridp[x - 1][y] != 4
                && Gridp[x][y + 1] != 4
                && Gridp[x][y - 1] != 4) { // ������ �������
                cell.setTexture(ship1exp);
            }
            else if (Gridp[x][y] == 1
                && (Gridp[x + 1][y] == 1
                    || Gridp[x + 1][y] == 3)
                && Gridp[x - 1][y] != 1
                && Gridp[x][y + 1] != 1
                && Gridp[x][y - 1] != 1
                && Gridp[x - 1][y] != 3
                && Gridp[x][y + 1] != 3
                && Gridp[x][y - 1] != 3
                && Gridp[x - 1][y] != 4
                && Gridp[x][y + 1] != 4
                && Gridp[x][y - 1] != 4) { // ������ �������
                cell.setTexture(shipedger);
            }
            else if (Gridp[x][y] == 1
                && (Gridp[x - 1][y] == 1
                    || Gridp[x - 1][y] == 3)
                && Gridp[x + 1][y] != 1
                && Gridp[x][y + 1] != 1
                && Gridp[x][y - 1] != 1
                && Gridp[x + 1][y] != 3
                && Gridp[x][y + 1] != 3
                && Gridp[x][y - 1] != 3
                && Gridp[x + 1][y] != 4
                && Gridp[x][y + 1] != 4
                && Gridp[x][y - 1] != 4) { // ������ �������
                cell.setTexture(shipedgel);
            }
            else if (Gridp[x][y] == 1
                && (Gridp[x][y - 1] == 1
                    || Gridp[x][y - 1] == 3)
                && Gridp[x - 1][y] != 1
                && Gridp[x][y + 1] != 1
                && Gridp[x + 1][y] != 1
                && Gridp[x - 1][y] != 3
                && Gridp[x][y + 1] != 3
                && Gridp[x + 1][y] != 3
                && Gridp[x - 1][y] != 4
                && Gridp[x][y + 1] != 4
                && Gridp[x + 1][y] != 4) { // ������ �������
                cell.setTexture(shipedget);
            }
            else if (Gridp[x][y] == 1
                && (Gridp[x][y + 1] == 1
                    || Gridp[x][y + 1] == 3)
                && Gridp[x - 1][y] != 1
                && Gridp[x + 1][y] != 1
                && Gridp[x][y - 1] != 1
                && Gridp[x - 1][y] != 3
                && Gridp[x + 1][y] != 3
                && Gridp[x][y - 1] != 3
                && Gridp[x - 1][y] != 4
                && Gridp[x + 1][y] != 4
                && Gridp[x][y - 1] != 4) { // ������ �������
                cell.setTexture(shipedged);
            }

            else if ((Gridp[x][y] == 3 || Gridp[x][y] == 4)
                && (Gridp[x + 1][y] == 1
                    || Gridp[x + 1][y] == 3
                    || Gridp[x + 1][y] == 4)
                && Gridp[x - 1][y] != 1
                && Gridp[x][y + 1] != 1
                && Gridp[x][y - 1] != 1
                && Gridp[x - 1][y] != 3
                && Gridp[x][y + 1] != 3
                && Gridp[x][y - 1] != 3
                && Gridp[x - 1][y] != 4
                && Gridp[x][y + 1] != 4
                && Gridp[x][y - 1] != 4) { // ������ �������
                cell.setTexture(shipedgerexp);
            }
            else if ((Gridp[x][y] == 3 || Gridp[x][y] == 4)
                && (Gridp[x - 1][y] == 1
                    || Gridp[x - 1][y] == 3
                    || Gridp[x - 1][y] == 4)
                && Gridp[x + 1][y] != 1
                && Gridp[x][y + 1] != 1
                && Gridp[x][y - 1] != 1
                && Gridp[x + 1][y] != 3
                && Gridp[x][y + 1] != 3
                && Gridp[x][y - 1] != 3
                && Gridp[x + 1][y] != 4
                && Gridp[x][y + 1] != 4
                && Gridp[x][y - 1] != 4) { // ������ �������
                cell.setTexture(shipedgelexp);
            }
            else if ((Gridp[x][y] == 3 || Gridp[x][y] == 4)
                && (Gridp[x][y - 1] == 1
                    || Gridp[x][y - 1] == 3
                    || Gridp[x][y - 1] == 4)
                && Gridp[x - 1][y] != 1
                && Gridp[x][y + 1] != 1
                && Gridp[x + 1][y] != 1
                && Gridp[x - 1][y] != 3
                && Gridp[x][y + 1] != 3
                && Gridp[x + 1][y] != 3
                && Gridp[x - 1][y] != 4
                && Gridp[x][y + 1] != 4
                && Gridp[x + 1][y] != 4) { // ������ �������
                cell.setTexture(shipedgetexp);
            }
            else if ((Gridp[x][y] == 3 || Gridp[x][y] == 4)
                && (Gridp[x][y + 1] == 1
                    || Gridp[x][y + 1] == 3
                    || Gridp[x][y + 1] == 4)
                && Gridp[x - 1][y] != 1
                && Gridp[x + 1][y] != 1
                && Gridp[x][y - 1] != 1
                && Gridp[x - 1][y] != 3
                && Gridp[x + 1][y] != 3
                && Gridp[x][y - 1] != 3
                && Gridp[x - 1][y] != 4
                && Gridp[x + 1][y] != 4
                && Gridp[x][y - 1] != 4) { // ������ �������
                cell.setTexture(shipedgedexp);
            }

            else if (Gridp[x][y] == 1
                && Gridp[x][y + 1] != 1
                && Gridp[x][y - 1] != 1
                && Gridp[x][y + 1] != 3
                && Gridp[x][y - 1] != 3
                && Gridp[x][y + 1] != 4
                && Gridp[x][y - 1] != 4
                && ((Gridp[x + 1][y] == 1
                    && Gridp[x - 1][y] == 1)
                    || (Gridp[x + 1][y] == 3
                        && Gridp[x - 1][y] == 3)
                    || (Gridp[x + 1][y] == 1
                        && Gridp[x - 1][y] == 3)
                    || (Gridp[x + 1][y] == 3
                        && Gridp[x - 1][y] == 1))) { // ������ �������
                cell.setTexture(shipmidlr);
            }
            else if (Gridp[x][y] == 1
                && Gridp[x + 1][y] != 1
                && Gridp[x - 1][y] != 1
                && Gridp[x + 1][y] != 3
                && Gridp[x - 1][y] != 3
                && Gridp[x + 1][y] != 4
                && Gridp[x - 1][y] != 4
                && ((Gridp[x][y + 1] == 1
                    && Gridp[x][y - 1] == 1)
                    || (Gridp[x][y + 1] == 3
                        && Gridp[x][y - 1] == 3)
                    || (Gridp[x][y + 1] == 1
                        && Gridp[x][y - 1] == 3)
                    || (Gridp[x][y + 1] == 3
                        && Gridp[x][y - 1] == 1))) { // ������ �������
                cell.setTexture(shipmidtd);
            }

            else if ((Gridp[x][y] == 3 || Gridp[x][y] == 4)
                && Gridp[x][y + 1] != 1
                && Gridp[x][y - 1] != 1
                && Gridp[x][y + 1] != 3
                && Gridp[x][y - 1] != 3
                && Gridp[x][y + 1] != 4
                && Gridp[x][y - 1] != 4
                && ((Gridp[x + 1][y] == 1
                    && Gridp[x - 1][y] == 1)
                    || (Gridp[x + 1][y] == 3
                        && Gridp[x - 1][y] == 3)
                    || (Gridp[x + 1][y] == 1
                        && Gridp[x - 1][y] == 3)
                    || (Gridp[x + 1][y] == 3
                        && Gridp[x - 1][y] == 1)
                    || (Gridp[x + 1][y] == 4
                        && Gridp[x - 1][y] == 4))) { // ������ �������
                cell.setTexture(shipmidlrexp);
            }
            else if ((Gridp[x][y] == 3 || Gridp[x][y] == 4)
                && Gridp[x + 1][y] != 1
                && Gridp[x - 1][y] != 1
                && Gridp[x + 1][y] != 3
                && Gridp[x - 1][y] != 3
                && Gridp[x + 1][y] != 4
                && Gridp[x - 1][y] != 4
                && ((Gridp[x][y + 1] == 1
                    && Gridp[x][y - 1] == 1)
                    || (Gridp[x][y + 1] == 3
                        && Gridp[x][y - 1] == 3)
                    || (Gridp[x][y + 1] == 1
                        && Gridp[x][y - 1] == 3)
                    || (Gridp[x][y + 1] == 3
                        && Gridp[x][y - 1] == 1)
                    || (Gridp[x][y + 1] == 4
                        && Gridp[x][y - 1] == 4))) { // ������ �������
                cell.setTexture(shipmidtdexp);
            }
            else if (Gridp[x][y] == 2) { // ������
                cell.setTexture(miss);
                if (Gridp[x][y] != 2) {
                    return 1;
                }
            }
            else if (Gridp[x][y] == -1) { // ���������
                cell.setTexture(sand);
                if (Gridp[x][y] != -1) {
                    return 1;
                }
            }
            window.draw(cell);
        }
    }
    return 0;
}

int initGraphic() {
    if (!sea.loadFromFile("../external/images/sea.jpg")
        || !sand.loadFromFile("../external/images/sand.jpg")
        || !miss.loadFromFile("../external/images/miss.jpg")
        || !ship1.loadFromFile("../external/images/ship1.jpg")
        || !ship1exp.loadFromFile("../external/images/ship1exp.jpg")
        || !shipedger.loadFromFile("../external/images/shipedge(r).jpg")
        || !shipedgerexp.loadFromFile("../external/images/shipedge(r)exp.jpg")
        || !shipedgel.loadFromFile("../external/images/shipedge(l).jpg")
        || !shipedgelexp.loadFromFile("../external/images/shipedge(l)exp.jpg")
        || !shipedget.loadFromFile("../external/images/shipedge(t).jpg")
        || !shipedgetexp.loadFromFile("../external/images/shipedge(t)exp.jpg")
        || !shipedged.loadFromFile("../external/images/shipedge(d).jpg")
        || !shipedgedexp.loadFromFile("../external/images/shipedge(d)exp.jpg")
        || !shipmidlr.loadFromFile("../external/images/shipmid(lr).jpg")
        || !shipmidlrexp.loadFromFile("../external/images/shipmid(lr)exp.jpg")
        || !shipmidtd.loadFromFile("../external/images/shipmid(td).jpg")
        || !shipmidtdexp.loadFromFile("../external/images/shipmid(td)exp.jpg")
        || !explosion.loadFromFile("../external/images/explosion.jpg")) {
        return 1;
    }
    return 0;
}
