#include <iostream>
#include "../game15_logic/game15_logic.h"
#include "../game15_graph/game15_graph.h"

using namespace sf;

int win = 0;
int lose = 0;
bool isPaused = 0;

bool isPlayerTurn = true; // ��� ������

int main() {
	int playerGrid[10 + 2][10 + 2]; // ������� ���� ������
    int computerGrid[10 + 2][10 + 2]; // ������� ���� ����������

    RenderWindow window(VideoMode((10+2) * 50 * 2, (10 + 2) * 50), "Battleships", Style::Titlebar | Style::Close);
    window.setFramerateLimit(60);

    srand(time(NULL));

    if (zeroGrid(playerGrid, computerGrid) != 0) {
        return 1;
    }

    if (initGraphic() != 0) {
        return 1;
    }

    if (Ship_placement(computerGrid) != 0 || Ship_placement(playerGrid) != 0) {
        return 1;
    }

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
            if (isPlayerTurn && event.type == Event::MouseButtonPressed && (event.mouseButton.x < ((10 + 2) * 2) * 50) && (event.mouseButton.x > (10 + 2) * 50)) { // ���� ������ ��� ������ � �� ����� �� ������
                int x = (event.mouseButton.x - (10 + 2) * 50) / 50;
                int y = event.mouseButton.y / 50;

                if (computerGrid[x][y] == 1) { // ����
                    computerGrid[x][y] = 3;
                    win += 1;
                    isPaused = 1;
                }
                else if (computerGrid[x][y] == 0) { // ������
                    computerGrid[x][y] = 2;
                    isPlayerTurn = false;
                    isPaused = 1;
                }
            }
        }
        window.clear(Color::White);

        for (int x = 1; x < 10 + 1; x++) {
            for (int y = 1; y < 10 + 1; y++) {
                if ((computerGrid[x][y] == 3 && isSunk(x, y, computerGrid) == true && aroundHit(computerGrid, x, y) != 0)
                    || (playerGrid[x][y] == 3 && isSunk(x, y, playerGrid) == true && aroundHit(playerGrid, x, y) != 0)) {
                    return 1;
                }
            }
        }

        if (drawGrid(window, playerGrid, computerGrid, true) != 0 || drawGrid(window, playerGrid, computerGrid, false) != 0) {
            return 1;
        }

        window.display();
        if (isPaused == 1) {
            if (timer() != 0) {
                return 1;
            }
            isPaused = 0;
        }

        if (!isPlayerTurn) { // ���� ������ ��� ����������

            int x = rand() % 10 + 1;
            int y = rand() % 10 + 1;

            computerHit(playerGrid, checkforHit(playerGrid), x, y);

            if (playerGrid[x][y] == 1) { // �����
                playerGrid[x][y] = 3;
                lose += 1;
                isPaused = 1;
            }
            else { // ������
                playerGrid[x][y] = 2;
                isPlayerTurn = true;
                isPaused = 1;
            }

        }
        if (win == 20) {
            std::cout << "You won!";
            window.close();
        }
        if (lose == 20) {
            std::cout << "You lost!";
            window.close();
        }
    }

	return 0;
}
