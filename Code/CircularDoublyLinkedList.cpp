#include "CircularDoublyLinkedList.h"

template<typename T>
CircularDoublyLinkedList<T>::CircularDoublyLinkedList() {
	m_num_nodes = 0;
	m_head = NULL;
}

template<typename T>
void CircularDoublyLinkedList<T>::add_head(T data_) {
	Node<T>* new_node = new Node<T>(data_);
	Node<T>* temp = m_head;

	if (!m_head) {
		m_head = new_node;
	}
	else {
		new_node->next = m_head;
		m_head = new_node;

		while (temp) {
			temp = temp->next;
		}
	}
	m_num_nodes++;
}

template<typename T>
void CircularDoublyLinkedList<T>::add_end(T data_) {
	Node<T>* new_node = new Node<T>(data_);
	Node<T>* temp = m_head;

	if (!m_head) {
		m_head = new_node;
	}
	else {
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = new_node;
	}
	m_num_nodes++;
}

template<typename T>
void CircularDoublyLinkedList<T>::add_sort(T data_) {
	Node<T>* new_node = new Node<T>(data_);
	Node<T>* temp = m_head;

	if (!m_head) {
		m_head = new_node;
	}
	else {
		if (m_head->data > data_) {
			new_node->next = m_head;
			m_head = new_node;
		}
		else {
			while ((temp->next != NULL) && (temp->next->data < data_)) {
				temp = temp->next;
			}
			new_node->next = temp->next;
			temp->next = new_node;
		}
	}
	m_num_nodes++;
}

template<typename T>
void CircularDoublyLinkedList<T>::concat(CircularDoublyLinkedList list) {
	Node<T>* temp2 = list.m_head;

	while (temp2) {
		add_end(temp2->data);
		temp2 = temp2->next;
	}
}

template<typename T>
void CircularDoublyLinkedList<T>::del_all() {
	m_head->delete_all();
	m_head = 0;
}

template<typename T>
void CircularDoublyLinkedList<T>::del_by_data(T data_) {
	Node<T>* temp = m_head;
	Node<T>* temp1 = m_head->next;

	int cont = 0;

	if (m_head->data == data_) {
		m_head = temp->next;
	}
	else {
		while (temp1) {
			if (temp1->data == data_) {
				Node<T>* aux_node = temp1;
				temp->next = temp1->next;
				delete aux_node;
				cont++;
				m_num_nodes--;
			}
			temp = temp->next;
			temp1 = temp1->next;
		}
	}

	if (cont == 0) {
		std::cout << "No existe el dato " << std::endl;
	}
}

template<typename T>
void CircularDoublyLinkedList<T>::del_by_position(int pos) {
	Node<T>* temp = m_head;
	Node<T>* temp1 = temp->next;

	if (pos < 1 || pos > m_num_nodes) {
		std::cout << "Fuera de rango " << std::endl;
	}
	else if (pos == 1) {
		m_head = temp->next;
	}
	else {
		for (int i = 2; i <= pos; i++) {
			if (i == pos) {
				Node<T>* aux_node = temp1;
				temp->next = temp1->next;
				delete aux_node;
				m_num_nodes--;
			}
			temp = temp->next;
			temp1 = temp1->next;
		}
	}
}

template<typename T>
void CircularDoublyLinkedList<T>::fill_by_user(int dim) {
	T ele;
	for (int i = 0; i < dim; i++) {
		std::cout << "Ingresa el elemento " << i + 1 << std::endl;
		std::cin >> ele;
		add_end(ele);
	}
}

template<typename T>
void CircularDoublyLinkedList<T>::fill_random(int dim) {
	srand(time(NULL));
	for (int i = 0; i < dim; i++) {
		add_end(rand() % 100);
	}
}

template<typename T>
void insert_sort(T a[], int size) {
	T temp;
	for (int i = 0; i < size; i++) {
		for (int j = i - 1; j >= 0 && a[j + 1] < a[j]; j--) {
			temp = a[j + 1];
			a[j + 1] = a[j];
			a[j] = temp;
		}
	}
}

template<typename T>
void CircularDoublyLinkedList<T>::intersection(CircularDoublyLinkedList list_2) {
	Node<T>* temp = m_head;
	Node<T>* temp2 = list_2.m_head;
	CircularDoublyLinkedList intersection_list;
	int num_nodes_2 = list_2.m_num_nodes;
	int num_inter = 0;
	T* v1 = new T[m_num_nodes];
	T* v2 = new T[num_nodes_2];
	int i = 0;

	while (temp) {
		v1[i] = temp->data;
		temp = temp->next;
		i++;
	}

	int j = 0;

	while (temp2) {
		v2[j] = temp2->data;
		temp2 = temp2->next;
		j++;
	}
	insert_sort(v1, m_num_nodes);
	insert_sort(v2, num_nodes_2);
	int v1_i = 0;
	int v2_i = 0;
	while (v1_i < m_num_nodes && v2_i < num_nodes_2) {
		if (v1[v1_i] == v2[v2_i]) {
			intersection_list.add_end(v1[v1_i]);
			v1_i++;
			v2_i++;
			num_inter++;
		}
		else if (v1[v1_i] < v2[v2_i]) {
			v1_i++;
		}
		else {
			v2_i++;
		}
	}

	if (num_inter > 0) {
		std::cout << "Existen " << num_inter << " intersecciones " << std::endl;
		intersection_list.print();
	}
	else {
		std::cout << "No hay intersección en ambas listas" << std::endl;
	}
}

template<typename T>
void CircularDoublyLinkedList<T>::invert() {
	Node<T>* prev = NULL;
	Node<T>* next = NULL;
	Node<T>* temp = m_head;

	while (temp) {
		next = temp->next;
		temp->next = prev;
		prev = temp;
		temp = next;
	}
	m_head = prev;
}

template<typename T>
void CircularDoublyLinkedList<T>::load_file(std::string file) {
	T line;
	std::ifstream in;
	in.open(file.c_str());

	if (!in.is_open()) {
		std::cout << "No se puede abrir el archivo: " << file << std::endl;
	}
	else {
		while (in >> line) {
			add_end(line);
		}
	}
	in.close();
}

template<class T>
void CircularDoublyLinkedList<T>::show(void (*func)(T&)) {
	Node<T>* temp = m_head;
	while (temp) {
		func(temp->data);
		temp = temp->next;
	}
}

template<typename T>
void CircularDoublyLinkedList<T>::search(T data_) {
	Node<T>* temp = m_head;
	int cont = 1;
	int cont2 = 0;

	while (temp) {
		if (temp->data == data_) {
			std::cout << "El dato se encuentra en la posición: " << cont << std::endl;
			cont2++;
		}
		temp = temp->next;
		cont++;
	}

	if (cont2 == 0) {
		std::cout << "No existe el dato " << std::endl;
	}
	std::cout << std::endl << std::endl;
}

template<typename T>
bool CircularDoublyLinkedList<T>::exist(char* data_) {
	Person p;
	Node<T>* temp = m_head;
	bool exists = false;
	while (temp) {
		p = temp->data;
		if (strcmp(p.id, data_) == 0) {
			return exists = true;
		}
		temp = temp->next;
	}
	return exists;
}

template<typename T>
Person CircularDoublyLinkedList<T>::get_person(char* data_, int& i) {
	i = 0;
	Person p;
	Node<T>* temp = m_head;
	bool exists = false;
	while (temp) {
		i++;
		p = temp->data;
		if (strcmp(p.id, data_) == 0) {
			return p;
		}
		temp = temp->next;
	}
	return p;
}

template<typename T>
Auto CircularDoublyLinkedList<T>::get_auto(char* data_, int& i) {
	i = 0;
	Auto a;
	Node<T>* temp = m_head;
	bool exists = false;
	while (temp) {
		i++;
		a = temp->data;
		if (strcmp(a.placa, data_) == 0) {
			return a;
		}
		temp = temp->next;
	}
	return a;
}

template<typename T>
void CircularDoublyLinkedList<T>::unir() {
	CircularDoublyLinkedList<Auto> list_autos;
	list_autos.load_file("autos.txt");
	Person p;
	Auto a;
	Node<T>* temp = m_head;
	bool exists = false;
	int j = 0, c = 0;
	while (temp) {
		p = temp->data;
		std::cout << "--PERSONA  [" << c + 1 << "]: " << std::endl;
		std::cout << "Nombre: " << p.get_first_name() << std::endl;
		std::cout << "Apellido: " << p.get_last_name() << std::endl;
		std::cout << "Cedula: " << p.get_id() << std::endl;
		std::cout << "Autos: " << p.get_num_vehiculos() << std::endl;
		std::vector <std::string> v = p.get_vehiculos();
		for (int i = 0; i < p.get_num_vehiculos(); i++) {
			char* aux = (char*)malloc(50 * sizeof(char));
			std::string s = v.at(i);
			for (int j = 0; j < s.size(); j++) {
				aux[j] = s[j];
			}
			aux[s.length()] = '\0';
			a = list_autos.get_auto(aux, j);
			std::cout << "AUTO  [" << i + 1 << "]: " << std::endl;
			std::cout << "Placa: " << a.get_placa() << std::endl;
			std::cout << "Modelo: " << a.get_modelo() << std::endl;
		}
		c++;
		std::cout << std::endl;
		temp = temp->next;
	}
}

template<typename T>
bool CircularDoublyLinkedList<T>::exist_placa(const char* data_) {
	Auto p;
	Node<T>* temp = m_head;
	bool exists = false;
	while (temp) {
		p = temp->data;
		if (strcmp(p.placa, data_) == 0) {
			return exists = true;
		}
		temp = temp->next;
	}
	return exists;
}

template<typename T>
void CircularDoublyLinkedList<T>::sort() {
	T temp_data;
	Node<T>* aux_node = m_head;
	Node<T>* temp = aux_node;

	while (aux_node) {
		temp = aux_node;

		while (temp->next) {
			temp = temp->next;

			if (aux_node->data > temp->data) {
				temp_data = aux_node->data;
				aux_node->data = temp->data;
				temp->data = temp_data;
			}
		}

		aux_node = aux_node->next;
	}
}

template<typename T>
void CircularDoublyLinkedList<T>::save_file(std::string file) {
	Node<T>* temp = m_head;
	std::ofstream out;
	out.open(file.c_str());

	if (!out.is_open()) {
		std::cout << "No se puede guardar el archivo " << std::endl;
	}
	else {
		while (temp) {
			out << temp->data;
			temp = temp->next;
		}
	}
	out.close();
}

template<typename T>
CircularDoublyLinkedList<T>::~CircularDoublyLinkedList() {}