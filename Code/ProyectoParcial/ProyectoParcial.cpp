#include <iostream>
#include "Options.h"
#include "AsciiImage.h"
#include "Login.h"

int main() {
	AsciiImage image("../OpenVC/assets/img.jpg", 48);
	int opcion_escogida = 0;
	image.consoleFont(8, 15);
	image.resize(110, 60);
	image.showAscii();
	system("pause");
	system("cls");
	std::string marqueeText = "Ocler Moran ";
	std::thread t2(marquee, marqueeText);
	t2.detach();
	Options o;
	int option = 0;
	do {
		option = o.menu(2, "Ingresar.", "Salir.");
		switch (option)
		{
		case 1:
			login();
			break;
		case 2:
			system("pause");
			break;
		}

	} while (option != 2);
}

