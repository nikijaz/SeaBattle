#include "Mode.h"

void playerVsPlayer(void) {
	vector<string> names(2);
	vector<vector<vector<int>>> fields(2, vector<vector<int>>(10, vector<int>(10)));

	clearConsole();
	setCursorVisibility(true);
	cout << "First player name: ";
	cin >> names[0];
	cout << "Second player name: ";
	cin >> names[1];
	setCursorVisibility(false);

	clearConsole();
	initShipPlacement(fields[0], names[0]);
	clearConsole();
	initShipPlacement(fields[1], names[1]);

	clearConsole();
	initPlayerVsPlayerWar(fields, names);

	names.clear();
	fields.clear();
}
