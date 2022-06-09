#pragma once
#include "Utils.h"
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

void drawName(string name);
void drawBorder(void);
void drawField(vector<vector<int>> field);

void drawNames(vector<string> names);
void drawBorders(void);
void drawFields(vector<vector<vector<int>>> fields);
