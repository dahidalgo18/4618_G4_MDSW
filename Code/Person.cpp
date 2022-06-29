#include "Person.h"

Person::Person(const Person& p) {
	*this = p;
}

void Person::set_id(char _set_id[]) {
	id = new char[strlen(_set_id) + 1];
	strcpy(id, _set_id);
}

char* Person::get_id() {
	return id;
}

void Person::set_first_name(char _first_name[]) {
	first_name = new char[strlen(_first_name) + 1];
	strcpy(first_name, _first_name);
}

char* Person::get_first_name() {
	return first_name;
}

void Person::set_last_name(char _last_name[]) {
	last_name = new char[strlen(_last_name) + 1];
	strcpy(last_name, _last_name);
}

char* Person::get_last_name() {
	return last_name;
}

void Person::set_vehiculos(std::vector<std::string> _vehiculos) {
	vehiculos = _vehiculos;
}

std::vector<std::string> Person::get_vehiculos() {
	return vehiculos;
}

void Person::set_num_vehiculos(int _num_vehiculos) {
	num_vehiculos = _num_vehiculos;
}

int Person::get_num_vehiculos() {
	return num_vehiculos;
}

std::ostream& operator <<(std::ostream& os, Person& p) {
	os << p.get_id() << std::endl;
	os << p.get_first_name() << std::endl;
	os << p.get_last_name() << std::endl;
	os << p.get_num_vehiculos() << std::endl;

	for (int i = 0; i < p.get_num_vehiculos(); i++) {
		os << p.get_vehiculos().at(i);
		os << " ";
	}
	os << std::endl;
	return os;
}

std::istream& operator >>(std::istream& is, Person& p) {
	char aux_id[11], aux_first_name[40], aux_last_name[40];
	int aux_num_vehiculos;
	std::string aux;
	std::vector <std::string> aux_autos;
	is >> aux_id;
	p.set_id(aux_id);

	is >> aux_first_name;
	p.set_first_name(aux_first_name);

	is >> aux_last_name;
	p.set_last_name(aux_last_name);

	is >> aux_num_vehiculos;
	p.set_num_vehiculos(aux_num_vehiculos);

	for (int i = 0; i < p.get_num_vehiculos(); i++) {
		is >> aux;
		aux_autos.push_back(aux);
	}
	p.set_vehiculos(aux_autos);
	is.ignore();
	return is;
}

bool Person::operator==(Person& p) {
	if (strcmp(this->id, p.id) == 0) {
		return true;
	}

	if (strcmp(this->first_name, p.first_name) == 0 &&
		strcmp(this->last_name, p.last_name) == 0) {
		return true;
	}
	return false;
}

Person::~Person() {}