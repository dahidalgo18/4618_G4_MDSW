#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<windows.h>
#include<unistd.h>
using namespace std;

class employee{
    private:
        // Variables for employee details
        char name[30];
        char id[5];
        char designation[10];
        int age;
        int ctc;
        int experience;

        // Utility functions
        void waitForEnter(void){
            cout<<"\n\n\n Presiona enter para volver \n\n";
            cin.get();
            cin.get();
        }

        // Functions to perform desired actions
        void listEmployees(void){ //To list total employees with Name, Id and Designation
            system("cls");
            FILE *file;
            file= fopen("data.txt", "r");
            cout<<"\n\t      Lista de empleados\n";
            cout<<"\n===============================================";
            cout<<"\n NOMBRE       |     ID     |     DESIGNACION\n";
            cout<<"=================================================";
            while(fscanf(file, "%s %s %s %d %d %d", &name[0], &id[0] , &designation[0], &age, &ctc, &experience)!= EOF)
                cout<<"\n"<<name<<"\t\t"<<id<<"\t\t"<<designation;
            fclose(file);
            waitForEnter();
        }

        void showDetails(void){ //Displays all details according to Employee's id
            system("cls");
            FILE *file;
            char checkId[5];
            cout<<"\n\nIngrese la identificación del empleado: ";
            cin>>checkId;
            file= fopen("data.txt", "r");
            while(fscanf(file, "%s %s %s %d %d %d", &name[0], &id[0] , &designation[0], &age, &ctc, &experience)!=EOF)
                if(strcmp(checkId,id)==0){
                	cout<<"\n---------------------";
                    cout<<"\nNombre: "<<name;
                    cout<<"\n---------------------";
                    cout<<"\nId: "<<id;
                    cout<<"\n---------------------";
                    cout<<"\nDesignacion: "<<designation;
                    cout<<"\n---------------------";
                    cout<<"\nEdad: "<<age;
                    cout<<"\n---------------------";
                    cout<<"\nSueldo: "<<ctc;
                    cout<<"\n---------------------";
                    cout<<"\nExperiencia: "<<experience;
                    cout<<"\n---------------------";
                }
            fclose(file);
            waitForEnter();
        }

        void editExisting(void){ //edits Designation and CTC of an employee
            system("cls");
            char checkId[5];
            cout<<"\nIngrese la identificación del empleado: ";
            cin>>checkId;
            char newDesignation[10];
            cout<<"\n-----------------------------";
            cout<<"\nIntroduzca una nueva designación: ";
            cin>>newDesignation;
            int newCtc;
            cout<<"------------------------------";
            cout<<"\nIntroduzca un nuevo sueldo: ";
            cin>>newCtc;
            FILE *file, *tempfile;
            file= fopen("data.txt", "r");
            tempfile= fopen("temp.txt", "w");
            while(fscanf(file, "%s %s %s %d %d %d", &name[0], &id[0] , &designation[0], &age, &ctc, &experience)!=EOF){
                if(strcmp(checkId, id)==0)
                    fprintf(tempfile, "%s %s %s %d %d %d \n", name, id, newDesignation, age, newCtc, experience );
                else
                    fprintf(tempfile, "%s %s %s %d %d %d \n", name, id, designation, age, ctc, experience );
            }
            fclose(file);
            fclose(tempfile);
            int isRemoved= remove("data.txt");
            int isRenamed= rename("temp.txt", "data.txt");
            waitForEnter();
        }

        void addNewEmployee(void){ //adding records
            system("cls");
            cout<<"\n----------------------------------------";
            cout<<"\n Ingrese el nombre del empleado: ";
            cin>>name;
            cout<<"\n----------------------------------------";
            cout<<"\n Ingrese la identificación del empleado [max 4 digitos]: ";
            cin>>id;
            cout<<"\n----------------------------------------";
            cout<<"\n Ingrese la designación: ";
            cin>>designation;
            cout<<"\n----------------------------------------";
            cout<<"\n Ingrese la edad del empleado: ";
            cin>>age;
            cout<<"\n----------------------------------------";
            cout<<"\n Ingrese el sueldo del empleado: ";
            cin>>ctc;
            cout<<"\n----------------------------------------";
            cout<<"\n Ingrese la experiencia del empleado: ";
            cin>>experience;
            cout<<"\n----------------------------------------";

            char ch;
            cout<<"\nIngrese 'S' para guardar la información anterior\n";
            cin>>ch;
            if(ch=='S'){
                FILE  *file;
                file= fopen("data.txt","a");
                fprintf(file, "%s %s %s %d %d %d \n", name, id, designation, age, ctc, experience );
                fclose(file);
                cout<<"\nSe ha agregado un nuevo empleado a la base de datos.\n";
            }
            else
                addNewEmployee();
            waitForEnter();
        }

        void deleteEmployeeDetails(void){ //removing records
            system("cls");
            char checkId[5];
            cout<<"\n----------------------------------";
            cout<<"\nIngrese la identificación del empleado para eliminar: ";
            cin>>checkId;
            char ch;
            cout<<"----------------------------------";
            cout<<"\n\n\n\n\nCONFIRMACIÓN\nIngrese 'S' para confirmar la eliminación \n";
            cin>>ch;
            if(ch=='S'){
                FILE *file, *tempfile;
                file= fopen("data.txt", "r");
                tempfile= fopen("temp.txt", "w");
                while(fscanf(file, "%s %s %s %d %d %d", &name[0], &id[0] , &designation[0], &age, &ctc, &experience)!=EOF)
                    if(strcmp(checkId, id)!=0)
                        fprintf(tempfile, "%s %s %s %d %d %d \n", name, id, designation, age, ctc, experience );
                fclose(file);
                fclose(tempfile);
                int isRemoved= remove("data.txt");
                int isRenamed= rename("temp.txt", "data.txt");
                cout<<"\nEliminado con éxito\n";
                waitForEnter();
            }
            else
                deleteEmployeeDetails();
        }


    public:
        
        void options(void){ 
        int login(); 
                login();
            while(true){
                system("cls");
                
                //MENU
                cout<<"\n\t\t\t>>>>>>>>>  SISTEMA DE GESTIÓN DE EMPLEADOS  <<<<<<<<<";
                cout<<"\n";
                cout<<"\n\t\t\t=================================================";
                cout<<"\n\t\t\t   1:   Ver la lista de empleados";
                cout<<"\n\t\t\t   2:   Ver los detalles del empleado";
                cout<<"\n\t\t\t   3:   Modificar detalles de empleados existentes";
                cout<<"\n\t\t\t   4:   Agregar nuevos detalles del empleado";
                cout<<"\n\t\t\t   5:   Eliminar los detalles de un empleado";
                cout<<"\n\t\t\t   0:   Salir     ";
                cout<<"\n\t\t\t=================================================";
                cout<<"\n\n\t\t\t   Ingrese su elección: ";

                // Taking the action input
                int choice;
                cin>>choice;
                // Calling relevant function as per choice
                switch (choice) {
                    case 0:
                    	system("CLS");
                        cout<<"\n\nSISTEMA DE GESTIÓN DE EMPLEADOS \n\n \n\n ";
                        Sleep(10);
                        return;
                    case 1:
                        listEmployees();
                        break;
                    case 2:
                        showDetails();
                        break;
                    case 3:
                        editExisting();
                        break;
                    case 4:
                        addNewEmployee();
                        break;
                    case 5:
                        deleteEmployeeDetails();
                        break;
                    default:
                        cout<<"\n ¡Lo siento! Ingrese un valor válido \n";
                        break;
                }

            }
        }

};

int main(){
    // Call the options function
    employee e;
    e.options();
    return 0;
}

int login(){ //login procedure
   string pass ="";
   char ch;
   cout <<"\n\n\n\n\t\t\t\t\tSISTEMA DE GESTION DE EMPLEADOS";
   cout <<"\n\n\n\n\n\t\t\t\t\tIngresa tu clave admin :";
   ch = _getch();
   while(ch != 13){//character 13 is enter
      pass.push_back(ch);
      cout << '*';
      ch = _getch();
   }
   if(pass == "pass" || pass=="amen"){
   	cout<<"\n\n\n\t\t\t\t\tCARGANDO \n\t\t\t\t\t";
   	for(int a=1;a<8;a++) // Change 'a<?' to how many * you want
	{
		Sleep(500);
		cout << "...";
	}
      cout << "\n\n\n\t\t\t\t\t¡¡Acceso permitido!! \n\n\n BIENVENIDO\n\n\n";
      
      system("PAUSE");
      system("CLS");
   }else{
      cout << "\nAcceso cancelado o denegado...\n";
      login();
   }
}

