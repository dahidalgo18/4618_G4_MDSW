#pragma once
#include <stdlib.h>
#include <conio.h>
#include <iostream>
#include <cstdarg>
#include <vadefs.h>
#include <stdarg.h>
#include <windows.h>
#include <thread>

#define UP    72
#define LEFT  75
#define RIGTH 77
#define DOWN  80
#define ESC   27
#define ENTER 13

class Options
{
public:
	int menu(int nargs, ...);
};

void gotoXY(int x, int y) {
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

void marquee(std::string text) {
	HANDLE conhandler = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int ancho, alto;
	GetConsoleScreenBufferInfo(conhandler, &csbi);
	ancho = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	SetConsoleCursorPosition(conhandler, { 0, 4 });
	while (true) {
		std::string temp = text;
		text.erase(0, 1);
		text += temp[0];
		CHAR_INFO* buff = (CHAR_INFO*)calloc(ancho, sizeof(CHAR_INFO));

		for (int i = 0; i < text.length(); i++) {
			buff[i].Char.AsciiChar = text.at(i);
			buff[i].Attributes = 15;
		}

		SMALL_RECT pos = { 10, 0, ancho, 1 };
		WriteConsoleOutputA(conhandler, buff, { (SHORT)ancho, 1 }, { 0, 0 }, &pos);
		free(buff);
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
	}

}


int Options::menu(int nargs, ...) {
	int selection = 1;
	int key;
	bool flag = true;

	do {
		va_list args;
		va_start(args, nargs);
		system("cls");
		gotoXY(10, 10);
		std::cout << "BASE DE DATOS." << std::endl;

		for (int i = 0; i < nargs; i++) {
			if (selection == i + 1) {
				gotoXY(10, 12 + i);
				std::cout << ">" << va_arg(args, char*) << std::endl;
			}
			else {
				gotoXY(11, 12 + i);
				std::cout << va_arg(args, char*) << std::endl;
			}
		}
		va_end(args);

		unsigned char x;
		do {
			key = _getch();
			x = key;
			if (0 == x) {
				x = _getch();
			}
		} while (key != UP && key != DOWN && key != ENTER && x != ';');

		switch (key) {
		case UP:
			selection--;
			if (selection <= 0) {
				selection = nargs;
			}
			break;
		case DOWN:
			selection++;
			if (selection > nargs) {
				selection = 1;
			}
			break;
		case ENTER:
			flag = false;
			break;
		}
		switch (x)
		{
		case ';':
			system("start C:\\Users\\LUNA\\Downloads\\ProyectoParcial\\ManualUsuario.pdf");
			break;
		}

	} while (flag);

	return selection;
}
