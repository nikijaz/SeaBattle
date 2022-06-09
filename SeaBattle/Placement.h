#pragma once
#include "Draw.h"
#include "Random.h"
#include "Keys.h"
#include <conio.h>

void initShipPlacement(vector<vector<int>>& field, string name);
void initPlayerVsPlayerWar(vector<vector<vector<int>>> fields, vector<string> names);
