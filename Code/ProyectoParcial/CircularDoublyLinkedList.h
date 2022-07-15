#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <functional>
#include <vector>
#include "Node.h"
#include "Node.cpp"
#include "Person.h"
#include "Auto.h"

template <class T>
class CircularDoublyLinkedList {
public:
	CircularDoublyLinkedList();
	~CircularDoublyLinkedList();

	void add_head(T);
	void add_end(T);
	void add_sort(T);
	void concat(CircularDoublyLinkedList);
	void del_all();
	void del_by_data(T);
	void del_by_position(int);
	void fill_by_user(int);
	void fill_random(int);
	void intersection(CircularDoublyLinkedList);
	void invert();
	void load_file(std::string);
	void show(void (*func)(T&));
	void save_file(std::string);
	void search(T);
	bool exist(char* data_);
	bool exist_placa(const char* data_);
	Person get_person(char* data_, int& i);
	Auto get_auto(char* data_, int& i);
	void sort();
	void unir();

private:
	Node<T>* m_head;
	int m_num_nodes;
};