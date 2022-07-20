#include <ctype.h>
#include <iostream>
#include <cstdlib>
#include <string.h>
#include "arbolAvl.h"
#include "empleado.h"

#include<iostream>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<string.h>


using namespace std;
void agregar();
void eliminar();

// Función de prueba para recorridos del árbol
template <class DATO>
void Mostrar(DATO &d, int FE)
{
   cout << d << "\t\t" << "(" << FE << ")" << endl;
}

AVL<Empleado> listaEmpleados;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {

	int opc;
	system("color 7F");
	system("color F0");
	int count;
    string user,pass,u,p;
    system("cls");
    cout<<"please enter the following details"<<endl;
    cout<<"USERNAME :";
    cin>>user;
    cout<<"PASSWORD :";
    cin>>pass;
        
    ifstream input("database.txt");
        while(input>>u>>p)
        {
                if(u==user && p==pass)
        
                {
                        count=1;
                        system("cls");
                }
        }
        input.close();
        if(count==1)
        {
                cout<<"\nHello"<<user<<"\nLOGIN SUCESS\nWe're glad that you're here.\nThanks for logging in\n";
                cin.get();
                cin.get();
                //main();
        }
        else
        {
                cout<<"\nLOGIN ERROR\nPlease check your username and password\n";
                //main();
        }
	
	do{
		system("cls");
		
		//cout << "\n\t\t\t****** Empresa ******" << endl;
		cout<<"\n"<<"==============================================================================="<<"\n";
		cout<<"\n"<<"                                    EMPRESA                          "<<"\n";
		cout<<"\n"<<"==============================================================================="<<"\n";
		cout << endl;
		
		cout << "\n1. Agregar Empleado"
		     << "\n2. Eliminar Empleado"
		     << "\n3. Imprimir Empleados"
		     << "\n4. Buscar Empleado"
		     << "\n0. salir" << endl;
		cout << "Escoja una opcion: ";
		cin >> opc;
		
		switch(opc){
			case 1:{
				system("cls");
				cout << "\n\t---- Registrar Empleado ----" << endl;
				agregar();
				system("pause");
				break;
			}
			case 2:{
				system("cls");
				cout << "\n\t---- Eliminar Empleado ----" << endl;
				eliminar();
				system("pause");
				break;
			}
			case 3:{
				//system("cls");
				cout << "\n\t---- Lista de Empleados ----" << endl;
				cout << "Codigo\t\t" << "Nombre\t\t" << "EstadoCivil\t\t" << "Antiguedad\t\t" << endl;
				//listaHerramientas.ParaCada(Mostrar);
				cout << "\n\t-------------------------------" << endl;
				//system("pause");
				listaEmpleados.InOrden(Mostrar);
				system("pause");
				break;
			}
			case 4:{
				int cod;
				system("cls");
				cout << "\n\t---- Buscar Empleado ----" << endl;
				cout << "Ingrese el codigo del empleado: ";
				cin >> cod;
				cout << endl;
				if(listaEmpleados.Buscar(cod)){
					listaEmpleados.ImpCada(cod);
				}else
					cout << "El empleado no existe" << endl;
				system("pause");
				break;
			}
			case 0:{
				system("cls");
				cout<<"\n\t*******************************"<<endl;
				cout<<"\t*********** GRACIAS ***********"<<endl;
				cout<<"\t**** POR USAR EL PROGRAMA ****"<<endl;
				cout<<"\t*******************************"<<endl;
				system("pause");
				break;
			}
			default:{
				cout<<"\nIngrese un valor valido del menu\n";
				system("pause");
				break;
			}				
		}
	}while(opc != 0);
	return 0;
}

void agregar(){
	
	char nombre[20];
	string nom;
	char estCivil[20];
	string estc;
	char antiguedad[20];
	string antg;
	int codigo;
	do{
		cout << "\nIngrese el codigo del empleado: ";
		cin >> codigo;
		if(listaEmpleados.Buscar(codigo)){
			cout << "Codigo repetido. Ingrese otro codigo" << endl;
		}
	}while(listaEmpleados.Buscar(codigo));
	cout << "\nIngrese el nombre del empleado: ";
	cin >> nom;
	strcpy(nombre,nom.c_str());
	cout << "\nIngrese el estado civil del empleado: ";
	cin >> estc;
	strcpy(estCivil,estc.c_str());
	cout << "\nIngrese la antiguedad del empleado: ";
	cin >> antg;
	strcpy(antiguedad,antg.c_str());
	
	Empleado *temp = new Empleado(nombre, estCivil, antiguedad, codigo);
	listaEmpleados.Insertar(*temp);
}

void eliminar(){
	int codigo;
	char opc;
	
	cout << "\nIngrese el codigo del empleado: ";
	cin >> codigo;
	
	if(listaEmpleados.Buscar(codigo)){
		listaEmpleados.ImpCada(codigo);
		cout << "Desea eliminar(Y/N): ";
		cin >> opc;
		if(opc == 'Y' || opc =='y'){
			listaEmpleados.Borrar(codigo);
			cout << "Se elimino el empleado." << endl;
		}else
			cout << "No se elimino ningun empleado." << endl;
	}else
		cout << "No existe el empleado." << endl;
	
}
