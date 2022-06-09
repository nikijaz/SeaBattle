#include "Check.h"

bool canMoveShipTo(vector<vector<int>> field, int x, int y, int shipSize, int rotation) {
	if (x > 9 || y > 9 || x < 0 || y < 0)
		return false;

	switch (rotation) {
	case 0:
		for (int i = 0; i < shipSize; i++)
			if (y - i < 0 || field[y - i][x] == 2 || field[y - i][x] == 3 || field[y - i][x] == 4)
				return false;
		break;
	case 1:
		for (int i = 0; i < shipSize; i++)
			if (x + i > 9 || field[y][x + i] == 2 || field[y][x + i] == 3 || field[y][x + i] == 4)
				return false;
		break;
	case 2:
		for (int i = 0; i < shipSize; i++)
			if (y + i > 9 || field[y + i][x] == 2 || field[y + i][x] == 3 || field[y + i][x] == 4)
				return false;
		break;
	case 3:
		for (int i = 0; i < shipSize; i++)
			if (x - i < 0 || field[y][x - i] == 2 || field[y][x - i] == 3 || field[y][x - i] == 4)
				return false;
		break;
	}

	return true;
}

bool canPlaceShipTo(vector<vector<int>> field, int x, int y, int shipSize, int rotation) {
	if (x > 9 || y > 9 || x < 0 || y < 0)
		return false;

	switch (rotation) {
	case 0:
		for (int i = -1; i < 2; i++)
			for (int j = -1; j < 2; j++)
				for (int k = 0; k < shipSize; k++)
					if (field[limitCoords(y - k + i)][limitCoords(x + j)] == 2)
						return false;
		break;
	case 1:
		for (int i = -1; i < 2; i++)
			for (int j = -1; j < 2; j++)
				for (int k = 0; k < shipSize; k++)
					if (field[limitCoords(y + i)][limitCoords(x + k + j)] == 2)
						return false;
		break;
	case 2:
		for (int i = -1; i < 2; i++)
			for (int j = -1; j < 2; j++)
				for (int k = 0; k < shipSize; k++)
					if (field[limitCoords(y + k + i)][limitCoords(x + j)] == 2)
						return false;
		break;
	case 3:
		for (int i = -1; i < 2; i++)
			for (int j = -1; j < 2; j++)
				for (int k = 0; k < shipSize; k++)
					if (field[limitCoords(y + i)][limitCoords(x - k + j)] == 2)
						return false;
		break;
	}

	return true;
}
