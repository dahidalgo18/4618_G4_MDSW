#include <ctype.h>
#include <iostream>
#include <cstdlib>
#include <string.h>

using namespace std;

class Empleado
{
	private:
		int codigo;
		char *nombre;
		char *estCivil;
		char *antiguedad;
	public:
		Empleado(){}
		Empleado(int cod);
		Empleado(char nom[],char estc[],char antg[],int cod);		
		//~Persona();
		Empleado &operator=(const Empleado &c)
		{
			if(this!=&c)
			{
 				nombre = new char[strlen(c.nombre)+1];
				strcpy(nombre,c.nombre);
				estCivil = new char[strlen(c.estCivil)+1];
				strcpy(estCivil,c.estCivil);
				antiguedad = new char[strlen(c.antiguedad)+1];
				strcpy(antiguedad,c.antiguedad);
				codigo=c.codigo;
			}
			return *this;
		}
		bool operator>(const Empleado &d) const{
			return codigo > d.codigo;
		}
		bool operator<=(const Empleado &d) const{
			return codigo <= d.codigo;
		}
		bool operator!=(const Empleado &d) const{
			return codigo != d.codigo;
		}
		
		bool operator==(const Empleado &d) const{
			return codigo == d.codigo;
		}
		
		bool operator!=(const int cod) const{
			return codigo > cod;
		}
		
		bool operator<(const Empleado &d) const{
			return codigo < d.codigo;
		}	
		
		//Getters
		char *getNombre(){return nombre;}
		char *getEstCivil(){return estCivil;}
		char *getAntiguedad(){return antiguedad;}
		int getCodigo(){return codigo;}
			
};
Empleado::Empleado(char nom[],char estc[],char antg[],int cod){
	nombre = new char[strlen(nom)+1];
	strcpy(nombre,nom);
	estCivil = new char[strlen(estc)+1];
	strcpy(estCivil,estc);
	antiguedad = new char[strlen(antg)+1];
	strcpy(antiguedad,antg);
	codigo=cod;
}
Empleado::Empleado(int cod)
{
	codigo = cod;
}
//~Empleado::Empleado(){
//	delete[] nombre;
//}
//>> ---- cin>>p;

ostream& operator <<(ostream &os,Empleado a)
{
	os << "\t" << a.getCodigo() << "\t";
	os << "\t" << a.getNombre() << "\t";
	os << "\t" << a.getEstCivil() << "\t";
	os << "\t" << a.getAntiguedad() << "\t";
	return os;
}

