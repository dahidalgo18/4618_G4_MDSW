#pragma warning(disable : 4996)
#pragma once

#include <iostream>
#include <string.h>
#include <vector>


class Person {
public:
	char* id;
	char* first_name;
	char* last_name;
	std::vector <std::string> vehiculos;
	int num_vehiculos;

	Person() = default;
	Person(const Person&);
	void set_id(char[]);
	char* get_id();
	void set_first_name(char[]);
	char* get_first_name();
	void set_last_name(char[]);
	char* get_last_name();
	void set_vehiculos(std::vector <std::string>);
	std::vector <std::string> get_vehiculos();
	void set_num_vehiculos(int);
	int get_num_vehiculos();
	friend std::ostream& operator << (std::ostream& os, Person& p);
	friend std::istream& operator >> (std::istream& is, Person& p);
	bool operator== (Person& p);
	~Person();
};

