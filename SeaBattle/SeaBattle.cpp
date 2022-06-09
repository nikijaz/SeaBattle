#include "Mode.h"

int main() {
	setCursorVisibility(false);
	cout << "SeaBattle 0.1 BETA" << endl;
	cout << "Press any key to continue..." << endl;

	(void)_getch();
	clearConsole();

	cout << "Choose game mode:" << endl;
	cout << "1. Player vs Player" << endl;

	while (true) {
		int key = _getch();
		switch (key) {
		case KEY_1:
			playerVsPlayer();
			setCursorPosition(0, 13);
			return 0;
		}
	}
}
