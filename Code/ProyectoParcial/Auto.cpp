#pragma warning(disable : 4996)
#include "Auto.h"

Auto::Auto(const Auto& a) {
	*this = a;
}

void Auto::set_placa(char _placa[]) {
	placa = new char[strlen(_placa) + 1];
	strcpy(placa, _placa);
}

char* Auto::get_placa() {
	return placa;
}

void Auto::set_modelo(char _modelo[]) {
	modelo = new char[strlen(_modelo) + 1];
	strcpy(modelo, _modelo);
}

char* Auto::get_modelo() {
	return modelo;
}

std::ostream& operator <<(std::ostream& os, Auto& a) {
	os << a.get_placa() << std::endl;
	os << a.get_modelo() << std::endl;
	return os;
}

std::istream& operator >>(std::istream& is, Auto& a) {
	char aux_placa[11], aux_modelo[40];
	is >> aux_placa;
	a.set_placa(aux_placa);
	is >> aux_modelo;
	a.set_modelo(aux_modelo);
	is.ignore();
	return is;
}

bool Auto::operator > (const Auto& p) {
	if (p.placa > this->placa) {
		return true;
	}
	else {
		return false;
	}

}

