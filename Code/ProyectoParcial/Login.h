#pragma once
#include <iostream>
#include <stdlib.h>
#include "Options.h"
#include "CircularDoublyLinkedList.h"
#include "CircularDoublyLinkedList.cpp"
#include "Person.h"
#include "Auto.h"

using namespace std;


void imprimir_personas() {
	CircularDoublyLinkedList<Person> list_personas;
	list_personas.load_file("personas.txt");
	list_personas.show(node_data);
}

void imprimir_autos() {
	CircularDoublyLinkedList<Auto> list_autos;
	list_autos.load_file("autos.txt");
	list_autos.show(node_data);
}

void imprimir_auto_persona() {
	CircularDoublyLinkedList<Person> list_personas;
	list_personas.load_file("personas.txt");
	list_personas.unir();
}

void registrar() {
	CircularDoublyLinkedList<Person> list_1;
	Person* person = new Person();
	char* ced = (char*)malloc(50 * sizeof(char));
	char* first_name = (char*)malloc(50 * sizeof(char));
	char* last_name = (char*)malloc(50 * sizeof(char));
	bool encontrado = false;

	list_1.load_file("personas.txt");
	cout<<"\n"<<"==============================================================================="<<"\n";
	cout<<"\n"<<"                                     DATOS DEL TRABAJADOR                            "<<"\n";
	cout<<"\n"<<"==============================================================================="<<"\n";
	cout << "DATOS DEL Trabajador: " << endl;
	cout << "Ingrese la cedula de la persona: " << endl;
	cin >> ced;
	cout << "Ingrese el primer nombre de la persona: " << endl;
	cin >> first_name;
	cout << "Ingrese el primer apellido de la persona: " << endl;
	cin >> last_name;

	person->set_id(ced);
	person->set_first_name(first_name);
	person->set_last_name(last_name);
	person->set_num_vehiculos(0);
	list_1.add_end(*person);
	list_1.save_file("personas.txt");

	cout << "DATOS ADICIONALES: " << endl;
	CircularDoublyLinkedList<Auto> list_autos;
	CircularDoublyLinkedList<Person> list_personas;
	list_personas.load_file("personas.txt");
	list_autos.load_file("autos.txt");
	Auto* automovil = new Auto();
	char* modelo = (char*)malloc(50 * sizeof(char));
	encontrado = false;
	bool existir = false;
	std::string aux, placa;

	std::cout << "Ingrese su direccion: " << endl;
	std::cin >> modelo;

	do {
		std::cout << "Ingrese su edad: " << endl;
		std::cin >> placa;
		if (list_autos.exist_placa(placa.c_str())) {
			std::cout << "direccion registrada";
		}
		else {
			existir = true;
		}
	} while (existir != true);

	char* c_placa = (char*)malloc(placa.length() * sizeof(char));
	for (int i = 0; i < placa.length(); i++) {
		c_placa[i] = placa.at(i);
	}
	c_placa[placa.length()] = '\0';
	automovil->set_modelo(modelo);
	automovil->set_placa(c_placa);

	int iterador = 0;

	Person p = list_personas.get_person(ced, iterador);
	int actual = p.get_num_vehiculos();
	actual++;
	p.set_num_vehiculos(actual);

	std::vector < std::string>v = p.get_vehiculos();
	v.push_back(c_placa);
	p.set_vehiculos(v);
	list_personas.del_by_position(iterador);
	list_personas.add_end(p);
	list_personas.save_file("personas.txt");

	list_autos.add_end(*automovil);
	list_autos.save_file("autos.txt");
	cout << "Registrado!" << endl;
	system("pause");
}

void login() {
	FILE* fptr;
	char texto[50], userA[50], passwordA[50];
	std::string user, password;
	Options op;
	int opcion = 0;
	std::cout<<"\n"<<"==============================================================================="<<"\n";
	std::cout<<"\n"<<"                                     BIENVENIDO                               "<<"\n";
	std::cout<<"\n"<<"==============================================================================="<<"\n";
	std::cout << "Ingrese su usuario: " << std::endl;
	std::cin >> user;
	std::cout << "Ingrese la contrasena: " << std::endl;
	std::cin >> password;
	password = password;
	fptr = fopen("users.txt", "r");

	while (fgets(texto, 100, fptr) != NULL) {
		strcpy(userA, texto);
		userA[strcspn(userA, "\n")] = 0;
		strcpy(passwordA, fgets(texto, 100, fptr));
		if (strcmp(userA, user.c_str()) == 0 && strcmp(passwordA, password.c_str()) == 0) {
			do {
				std::cout<<"\n"<<"==============================================================================="<<"\n";
				std::cout<<"\n"<<"                                     GESTION DE EMPLEADOS                               "<<"\n";
				std::cout<<"\n"<<"==============================================================================="<<"\n";
				std::cout<<"\n"<<"1.Registrar Trabajador.\n";
				std::cout<<"\n"<<"2.Mostrar Trabajador.\n";
				opcion = op.menu(6, "Registrar Trabajador.", "Mostrar Trabajador.", "Mostrar .......", "Mostrar .....", "......", "Volver.");
				switch (opcion)
				{
				case 1:
					registrar();
					break;
				case 2:
					imprimir_personas();
					system("pause");
					break;
				case 3:
					imprimir_autos();
					system("pause");
					break;
				case 4:
					imprimir_auto_persona();
					system("pause");
					break;
				case 5:
					system("start chrome https://www.sodapdf.com/es/txt-para-pdf/");
					break;
				case 6:
					break;
				}
			} while (opcion != 6);
			break;
		}
		else {
			std::cout<<"==============================================================================="<<"\n";
            std::cout<<"\n"<<"             ESTIMADO USUARIO LA OPCION MARCADA ES INVALIDA                    "<<"\n";
            std::cout<<"\n"<<"==============================================================================="; 
			std::cout << "Usuario/ password incorrectos!" << std::endl;
			system("pause");
		}
	}
}

