									/*UNIVERSIDAD DE LAS FUERZAS ARMADAS 
												ESPE
											PROGRAMA PARA REGISTRO DE DATOS
											AUTOR:OCLER DELGADO, kEVIN JESUS,DIEGO HIDALGO
											VERSION:1.0	*/
#pragma once
#include <iostream>

template <class T>
class Node {
public:
	Node();
	Node(T);
	~Node();

	Node* next;
	T data;
	void delete_all();
};


