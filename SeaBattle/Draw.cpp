#include "Draw.h"

void drawName(string name) {
	for (int i = 0; i < (23 - name.length()) / 2; i++)
		cout << " ";
	cout << name << endl;
}

void drawBorder(void) {
	cout << char(201);
	for (int i = 0; i < 21; i++)
		cout << char(205);
	cout << char(187) << endl;

	for (int i = 0; i < 10; i++) {
		cout << char(186) << " ";
		for (int j = 0; j < 20; j++)
			cout << " ";
		cout << char(186) << endl;
	}

	cout << char(200);
	for (int i = 0; i < 21; i++)
		cout << char(205);
	cout << char(188) << endl;
}

void drawField(vector<vector<int>> field) {
	for (int i = 0; i < 10; i++) {
		setCursorPosition(2, 2 + i);
		for (int j = 0; j < 10; j++) {
			switch (field[i][j]) {
			case 0:
				cout << ". ";
				break;
			case 1:
				cout << "o ";
				break;
			case 2:
				cout << char(254) << " ";
				break;
			case 3:
				cout << "~ ";
				break;
			case 4:
				cout << char(254) << " ";
				break;
			case 5:
				cout << "X ";
				break;
			}
		}
	}
}


void drawNames(vector<string> names) {
	int firstNameSpaceLength = (int)((23 - names[0].length()) / 2);
	for (int i = 0; i < firstNameSpaceLength; i++)
		cout << " ";
	cout << names[0];

	for (int i = 0; i < 23 - firstNameSpaceLength - names[0].length() + 10 + (23 - names[1].length()) / 2; i++)
		cout << " ";
	cout << names[1] << endl;
}

void drawBorders(void) {
	cout << char(201);
	for (int i = 0; i < 21; i++)
		cout << char(205);
	cout << char(187);

	for (int i = 0; i < 10; i++)
		cout << " ";

	cout << char(201);
	for (int i = 0; i < 21; i++)
		cout << char(205);
	cout << char(187) << endl;


	for (int i = 0; i < 10; i++) {
		cout << char(186) << " ";
		for (int j = 0; j < 20; j++)
			cout << " ";
		cout << char(186);

		for (int j = 0; j < 10; j++)
			cout << " ";

		cout << char(186) << " ";
		for (int j = 0; j < 20; j++)
			cout << " ";
		cout << char(186) << endl;
	}

	cout << char(200);
	for (int i = 0; i < 21; i++)
		cout << char(205);
	cout << char(188);

	for (int i = 0; i < 10; i++)
		cout << " ";

	cout << char(200);
	for (int i = 0; i < 21; i++)
		cout << char(205);
	cout << char(188) << endl;
}

void drawFields(vector<vector<vector<int>>> fields) {
	for (int i = 0; i < 10; i++) {
		setCursorPosition(2, 2 + i);
		for (int j = 0; j < 10; j++) {
			switch (fields[0][i][j]) {
			case 0:
				cout << ". ";
				break;
			case 1:
				cout << "o ";
				break;
			case 2:
				cout << char(254) << " ";
				break;
			case 3:
				cout << "~ ";
				break;
			case 4:
				cout << char(254) << " ";
				break;
			case 5:
				cout << "X ";
				break;
			}
		}
	}

	for (int i = 0; i < 10; i++) {
		setCursorPosition(35, 2 + i);
		for (int j = 0; j < 10; j++) {
			switch (fields[1][i][j]) {
			case 0:
				cout << ". ";
				break;
			case 1:
				cout << "o ";
				break;
			case 2:
				cout << char(254) << " ";
				break;
			case 3:
				cout << "~ ";
				break;
			case 4:
				cout << char(254) << " ";
				break;
			case 5:
				cout << "X ";
				break;
			}
		}
	}
}
