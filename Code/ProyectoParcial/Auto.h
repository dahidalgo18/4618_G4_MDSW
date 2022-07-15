#pragma once
#include <iostream>
#include <string.h>

class Auto {
public:
	char* placa;
	char* modelo;

	Auto() = default;
	Auto(const Auto&);
	void set_placa(char[]);
	char* get_placa();
	void set_modelo(char[]);
	char* get_modelo();

	friend std::ostream& operator << (std::ostream& os, Auto& a);
	friend std::istream& operator >> (std::istream& is, Auto& a);
	bool operator > (const Auto& p);
};

