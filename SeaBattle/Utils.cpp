#include "Utils.h"

void clearConsole(void) {
	COORD coordinates = { 0,0 };
	CONSOLE_SCREEN_BUFFER_INFO consoleScreenBufferInfo;
	HANDLE consoleHandler = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(consoleHandler, &consoleScreenBufferInfo);
	DWORD written, cells = consoleScreenBufferInfo.dwSize.X * consoleScreenBufferInfo.dwSize.Y;
	FillConsoleOutputCharacter(consoleHandler, ' ', cells, coordinates, &written);
	FillConsoleOutputAttribute(consoleHandler, consoleScreenBufferInfo.wAttributes, cells, coordinates, &written);
	SetConsoleCursorPosition(consoleHandler, coordinates);
}

void setCursorPosition(short x, short y) {
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void setCursorVisibility(bool visible) {
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
	cursorInfo.bVisible = visible;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}
