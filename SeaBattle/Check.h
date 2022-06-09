#pragma once
#include <Windows.h>
#include <iostream>
#include <vector>

using std::vector;

#define limitCoords(value) (max(min(value, 9), 0))

bool canMoveShipTo(vector<vector<int>> field, int x, int y, int shipSize, int rotation);
bool canPlaceShipTo(vector<vector<int>> field, int x, int y, int shipSize, int rotation);
