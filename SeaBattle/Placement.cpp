#include "Placement.h"

void initShipPlacement(vector<vector<int>>& field, string name) {
	vector<int> shipSizes{ 4, 3, 2, 1 };

	int x = 0, y = 0;
	int shipSize = 1;
	int rotation = 1;

	drawName(name);
	drawBorder();

	while (true) {
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 10; j++)
				if (field[i][j] == 1)
					field[i][j] = 0;

		for (int i = 0; i < 4; i++)
			if (shipSizes[i] > 0) {
				switch (rotation) {
				case 0:
					for (int i = 0; i < shipSize; i++)
						field[y - i][x] = 1;
					break;
				case 1:
					for (int i = 0; i < shipSize; i++)
						field[y][x + i] = 1;
					break;
				case 2:
					for (int i = 0; i < shipSize; i++)
						field[y + i][x] = 1;
					break;
				case 3:
					for (int i = 0; i < shipSize; i++)
						field[y][x - i] = 1;
					break;
				}
				break;
			}

		drawField(field);

		int key = _getch();
		if (key == KEY_ARROW)
			key = _getch();

		switch (key) {
		case KEY_ARROW_UP:
			for (int i = 1; i < 10; i++)
				if (canMoveShipTo(field, x, y - i, shipSize, rotation)) {
					y -= i;
					break;
				}
			break;
		case KEY_ARROW_DOWN:
			for (int i = 1; i < 10; i++)
				if (canMoveShipTo(field, x, y + i, shipSize, rotation)) {
					y += i;
					break;
				}
			break;
		case KEY_ARROW_LEFT:
			for (int i = 1; i < 10; i++)
				if (canMoveShipTo(field, x - i, y, shipSize, rotation)) {
					x -= i;
					break;
				}
			break;
		case KEY_ARROW_RIGHT:
			for (int i = 1; i < 10; i++)
				if (canMoveShipTo(field, x + i, y, shipSize, rotation)) {
					x += i;
					break;
				}
			break;

		case KEY_W:
			if (canMoveShipTo(field, x, y, shipSize, 0))
				rotation = 0;
			break;
		case KEY_A:
			if (canMoveShipTo(field, x, y, shipSize, 3))
				rotation = 3;
			break;
		case KEY_S:
			if (canMoveShipTo(field, x, y, shipSize, 2))
				rotation = 2;
			break;
		case KEY_D:
			if (canMoveShipTo(field, x, y, shipSize, 1))
				rotation = 1;
			break;

		case KEY_1:
			if (canMoveShipTo(field, x, y, 1, rotation))
				shipSize = 1;
			break;
		case KEY_2:
			if (canMoveShipTo(field, x, y, 2, rotation))
				shipSize = 2;
			break;
		case KEY_3:
			if (canMoveShipTo(field, x, y, 3, rotation))
				shipSize = 3;
			break;
		case KEY_4:
			if (canMoveShipTo(field, x, y, 4, rotation))
				shipSize = 4;
			break;

		case KEY_R:
			randomizeShips(field);
			shipSizes.assign(shipSizes.size(), 0);
			break;
		case KEY_C:
			for (int i = 0; i < 10; i++)
				for (int j = 0; j < 10; j++)
					field[i][j] = 0;

			shipSizes[0] = 4;
			shipSizes[1] = 3;
			shipSizes[2] = 2;
			shipSizes[3] = 1;
			break;

		case KEY_ENTER:
			if (shipSizes[shipSize - 1] == 0) {
				bool end = true;
				for (int i = 0; i < 4; i++)
					if (shipSizes[i] > 0) {
						end = false;
						break;
					}
				if (end == true) {
					shipSizes.clear();
					return;
				}
			}

			if (shipSizes[shipSize - 1] == 0)
				continue;

			if (canPlaceShipTo(field, x, y, shipSize, rotation)) {
				switch (rotation) {
				case 0:
					for (int i = 0; i < shipSize; i++)
						field[y - i][x] = 2;
					break;
				case 1:
					for (int i = 0; i < shipSize; i++)
						field[y][x + i] = 2;
					break;
				case 2:
					for (int i = 0; i < shipSize; i++)
						field[y + i][x] = 2;
					break;
				case 3:
					for (int i = 0; i < shipSize; i++)
						field[y][x - i] = 2;
					break;
				}

				shipSizes[shipSize - 1]--;
			}

			[&] {
				for (int i = 0; i < 10; i++)
					for (int j = 0; j < 10; j++)
						if (canMoveShipTo(field, i, j, shipSize, rotation) == true) {
							x = i;
							y = j;
							return;
						}
			}();
		}
	}
}

void initPlayerVsPlayerWar(vector<vector<vector<int>>> fields, vector<string> names) {
	vector<vector<vector<int>>> attackFields(2, vector<vector<int>>(10, vector<int>(10)));
	vector<int> x(2, 0);
	vector<int> y(2, 0);
	bool turn = true;

	drawNames(names);
	drawBorders();

	while (true) {
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 10; j++) {
				if (!turn && attackFields[0][i][j] == 1)
					attackFields[0][i][j] = 0;
				if (turn && attackFields[1][i][j] == 1)
					attackFields[1][i][j] = 0;
			}

		attackFields[turn][y[turn]][x[turn]] = 1;

		drawFields(attackFields);

		int key = _getch();
		if (key == KEY_ARROW)
			key = _getch();

		switch (key) {
		case KEY_ARROW_UP:
		case KEY_W:
			if ((key == KEY_ARROW_UP && turn) || (key == KEY_W && !turn))
				break;
			for (int i = 1; i < 10; i++)
				if (canMoveShipTo(attackFields[turn], x[turn], y[turn] - i, 1, 1)) {
					y[turn] -= i;
					break;
				}
			break;
		case KEY_ARROW_DOWN:
		case KEY_S:
			if ((key == KEY_ARROW_DOWN && turn) || (key == KEY_S && !turn))
				break;
			for (int i = 1; i < 10; i++)
				if (canMoveShipTo(attackFields[turn], x[turn], y[turn] + i, 1, 1)) {
					y[turn] += i;
					break;
				}
			break;
		case KEY_ARROW_LEFT:
		case KEY_A:
			if ((key == KEY_ARROW_LEFT && turn) || (key == KEY_A && !turn))
				break;
			for (int i = 1; i < 10; i++)
				if (canMoveShipTo(attackFields[turn], x[turn] - i, y[turn], 1, 1)) {
					x[turn] -= i;
					break;
				}
			break;
		case KEY_ARROW_RIGHT:
		case KEY_D:
			if ((key == KEY_ARROW_RIGHT && turn) || (key == KEY_D && !turn))
				break;
			for (int i = 1; i < 10; i++)
				if (canMoveShipTo(attackFields[turn], x[turn] + i, y[turn], 1, 1)) {
					x[turn] += i;
					break;
				}
			break;

		case KEY_ENTER:
		case KEY_SPACE:
			if ((key == KEY_ENTER && turn) || (key == KEY_SPACE && !turn))
				break;
			if (fields[turn][y[turn]][x[turn]] == 2) {
				attackFields[turn][y[turn]][x[turn]] = 4;

				vector<int> sides(0);
				if (y[turn] > 0 && fields[turn][y[turn] - 1][x[turn]] == 2)
					sides.push_back(0);
				if (x[turn] < 9 && fields[turn][y[turn]][x[turn] + 1] == 2)
					sides.push_back(1);
				if (y[turn] < 9 && fields[turn][y[turn] + 1][x[turn]] == 2)
					sides.push_back(2);
				if (x[turn] > 0 && fields[turn][y[turn]][x[turn] - 1] == 2)
					sides.push_back(3);

				if (sides.size() == 0)
					for (int i = -1; i < 2; i++)
						for (int j = -1; j < 2; j++)
							if (attackFields[turn][limitCoords(y[turn] + i)][limitCoords(x[turn] + j)] != 4)
								attackFields[turn][limitCoords(y[turn] + i)][limitCoords(x[turn] + j)] = 3;

				bool killed = true;
				for (int i = 0; i < sides.size(); i++) {
					for (int j = 1; j < 4; j++) {
						switch (sides[i]) {
						case 0:
							if (fields[turn][limitCoords(y[turn] - j)][x[turn]] == 2 && attackFields[turn][limitCoords(y[turn] - j)][x[turn]] != 4)
								killed = false;
							break;
						case 1:
							if (fields[turn][y[turn]][limitCoords(x[turn] + j)] == 2 && attackFields[turn][y[turn]][limitCoords(x[turn] + j)] != 4)
								killed = false;
							break;
						case 2:
							if (fields[turn][limitCoords(y[turn] + j)][x[turn]] == 2 && attackFields[turn][limitCoords(y[turn] + j)][x[turn]] != 4)
								killed = false;
							break;
						case 3:
							if (fields[turn][y[turn]][limitCoords(x[turn] - j)] == 2 && attackFields[turn][y[turn]][limitCoords(x[turn] - j)] != 4)
								killed = false;
							break;
						}
					}
				}

				if (killed) {
					for (int i = 0; i < sides.size(); i++) {
						[&] {
							switch (sides[i]) {
							case 0:
								for (int j = 0; j < 4; j++)
									if (fields[turn][limitCoords(y[turn] - j)][x[turn]] == 2) {
										for (int a = -1; a < 2; a++)
											for (int b = -1; b < 2; b++)
												if (attackFields[turn][limitCoords(y[turn] - j + a)][limitCoords(x[turn] + b)] != 4)
													attackFields[turn][limitCoords(y[turn] - j + a)][limitCoords(x[turn] + b)] = 3;
									}
									else
										return;
								break;
							case 1:
								for (int j = 0; j < 4; j++)
									if (fields[turn][y[turn]][limitCoords(x[turn] + j)] == 2) {
										for (int a = -1; a < 2; a++)
											for (int b = -1; b < 2; b++)
												if (attackFields[turn][limitCoords(y[turn] + a)][limitCoords(x[turn] + j + b)] != 4)
													attackFields[turn][limitCoords(y[turn] + a)][limitCoords(x[turn] + j + b)] = 3;
									}
									else
										return;
								break;
							case 2:
								for (int j = 0; j < 4; j++)
									if (fields[turn][limitCoords(y[turn] + j)][x[turn]] == 2) {
										for (int a = -1; a < 2; a++)
											for (int b = -1; b < 2; b++)
												if (attackFields[turn][limitCoords(y[turn] + j + a)][limitCoords(x[turn] + b)] != 4)
													attackFields[turn][limitCoords(y[turn] + j + a)][limitCoords(x[turn] + b)] = 3;
									}
									else
										return;
								break;
							case 3:
								for (int j = 0; j < 4; j++)
									if (fields[turn][y[turn]][limitCoords(x[turn] - j)] == 2) {
										for (int a = -1; a < 2; a++)
											for (int b = -1; b < 2; b++)
												if (attackFields[turn][limitCoords(y[turn] + a)][limitCoords(x[turn] - j + b)] != 4)
													attackFields[turn][limitCoords(y[turn] + a)][limitCoords(x[turn] - j + b)] = 3;
									}
									else
										return;
								break;
							}
						}();
					}
				}
			}
			else
				attackFields[turn][y[turn]][x[turn]] = 3;

			int destroyed = 0;
			for (int i = 0; i < 10; i++)
				for (int j = 0; j < 10; j++)
					if (attackFields[turn][i][j] == 4)
						destroyed++;

			if (destroyed == 1 * 4 + 2 * 3 + 3 * 2 + 4 * 1) {
				for (int i = 0; i < 10; i++)
					for (int j = 0; j < 10; j++) {
						if (turn && attackFields[1][i][j] == 1)
							attackFields[1][i][j] = 0;
						if (!turn && attackFields[0][i][j] == 1)
							attackFields[0][i][j] = 0;
						if (fields[!turn][i][j] == 2 && attackFields[!turn][i][j] == 0)
							attackFields[!turn][i][j] = 5;
					}
				drawFields(attackFields);
				return;
			}

			[&] {
				if (attackFields[turn][y[turn]][x[turn]] != 4) {
					for (int i = 0; i < 10; i++)
						for (int j = 0; j < 10; j++)
							if (canMoveShipTo(attackFields[turn], i, j, 1, 1)) {
								x[turn] = i;
								y[turn] = j;
								turn = !turn;
								return;
							}
				}
				else
					for (int i = 0; i < 10; i++)
						for (int j = 0; j < 10; j++)
							if (canMoveShipTo(attackFields[turn], i, j, 1, 1)) {
								x[turn] = i;
								y[turn] = j;
								return;
							}
			}();
		}
	}
}
