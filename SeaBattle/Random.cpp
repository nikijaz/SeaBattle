#include "Random.h"

static unsigned long xorshf96(void) {
	static unsigned long x = 123456789, y = 362436069, z = 521288629;
	unsigned long t;

	x ^= x << 16;
	x ^= x >> 5;
	x ^= x << 1;

	t = x;
	x = y;
	y = z;

	z = t ^ x ^ y;
	return z;
}

void randomizeShips(vector<vector<int>>& field) {
	vector<int> shipSizes{ 4, 3, 2, 1 };
	int shipSize = 4;

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			field[i][j] = 0;

	while (true) {
		int x = xorshf96() % 10, y = xorshf96() % 10;
		int rotation = xorshf96() % 4;

		if (canMoveShipTo(field, x, y, shipSize, rotation) && canPlaceShipTo(field, x, y, shipSize, rotation)) {
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

			if (--shipSizes[shipSize - 1] == 0)
				if (--shipSize == 0)
					break;
		}
	}

	shipSizes.clear();
}
