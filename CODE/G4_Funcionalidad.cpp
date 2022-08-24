#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include <ctype.h>
#include<windows.h>
#include<stdio.h>
#include<unistd.h>

using namespace std;

class employee{
    private:
        // Variables for employee details
        char name[30];
        char lastName[30];
        char id[5];
        char designation[30];
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
            cout<<"\n=============================================================";
            cout<<"\n NOMBRE       |   Apellido   |     ID     |     DESIGNACION\n";
            cout<<"\n==============================================================";
            while(fscanf(file, "%s %s %s %s %d %d %d", &name[0], &lastName[0],&id[0] , &designation[0], &age, &ctc, &experience)!= EOF)
				cout<<"\n"<<name<<"\t\t"<<lastName<<"\t\t"<<id<<"\t\t"<<designation;
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
            while(fscanf(file, "%s %s %s %s %d %d %d", &name[0], &lastName[30], &id[0] , &designation[0], &age, &ctc, &experience)!=EOF)
                if(strcmp(checkId,id)==0){
                	cout<<"\n---------------------";
                    cout<<"\nNombre: "<<name;
                    cout<<"\n---------------------";
                    cout<<"\nApellido: "<<lastName;
                    cout<<"\n---------------------";
                    cout<<"\nId: "<<id;
                    cout<<"\n---------------------";
                    cout<<"\nDesignacion: "<<designation;
                    cout<<"\n---------------------";
                    cout<<"\nEdad: "<<age;
                    cout<<"\n---------------------";
                    cout<<"\nSueldo: "<<ctc<<" dolares";
                    cout<<"\n---------------------";
                    cout<<"\nExperiencia: "<<experience<<" Anios";
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
            char newDesignation[30];
            cout<<"\n-----------------------------";
            cout<<"\nIntroduzca una nueva designación[Sinespacios] \t[Empleado, Gerente, Administrador] \n: ";
            cin>>newDesignation;
			if(newDesignation!="Empleado"||newDesignation!="Gerente"||newDesignation!="Administrador"||newDesignation!=""){
					cout<<"Ingrese un puesto Correcto: ";
					cin>>newDesignation;
				}
            
            int newCtc;
            cout<<"------------------------------";
            cout<<"\nIntroduzca un nuevo sueldo: ";
            cin>>newCtc;
            FILE *file, *tempfile;
            file= fopen("data.txt", "r");
            tempfile= fopen("temp.txt", "w");
            while(fscanf(file, "%s %s %s %s %d %d %d", &name[0], &lastName[30], &id[0] , &designation[0], &age, &ctc, &experience)!=EOF){
                if(strcmp(checkId, id)==0)
                    fprintf(tempfile, "%s %s %s %s %d %d %d \n", name, lastName, id, newDesignation, age, newCtc, experience );
                else
                    fprintf(tempfile, "%s %s %s %s %d %d %d \n", name, lastName, id, designation, age, ctc, experience );
            }
            fclose(file);
            fclose(tempfile);
            int isRemoved= remove("data.txt");
            int isRenamed= rename("temp.txt", "data.txt");
            waitForEnter();
        }
//
//        void addNewEmployee(void){ //adding records
//            system("cls");
//            cout<<"\n----------------------------------------";
//            cout<<"\n Ingrese el nombre del empleado: ";
//            cin>>name;
//            fgets(name, 30, stdin);
//            cout<<"\n----------------------------------------";
//            cout<<"\n Ingrese la identificación del empleado [max 4 digitos]: ";
//            cin>>id;
//            if(id<0||id==" "){
//            	cout<<"Ingrese un ID valido: ";
//				cin>>id;
//			}
//            cout<<"\n----------------------------------------";
//            cout<<"\n Ingrese la designación: \t\t[Empleado o Gerente o Administrador] \n:";
//            cin>>designation;
////            scanf("%s",designation);
////            gets(designation);
////			std::cin.getline(designation, 31, '\n');
////			cin.getline(designation, 30);
//			//fgets(designation, 30, stdin);
//			if(designation!="Empleado"||designation!="Gerente"||designation!="Administrador"){
//					cout<<"Ingrese un puesto Correcto: ";
//					cin>>designation;
//					//fgets(designation, 30, stdin);
//				}
////			MenuDesign();
//            cout<<"\n----------------------------------------";
//            cout<<"\n Ingrese la edad del empleado: ";
//            cin>>age;
//            if(age<0||age==NULL||age<18){
//            	cout<<"Ingrese una edad valida : ";
//				cin>>age;
//			}
//            cout<<"\n----------------------------------------";
//            cout<<"\n Ingrese el sueldo del empleado: ";
//            cin>>ctc;
//            cout<<"\n----------------------------------------";
//            cout<<"\n Ingrese la experiencia del empleado [Anios]: ";
//            cin>>experience;
//            cout<<"\n----------------------------------------";
//
//            char ch;
//            cout<<"\nIngrese 'S' para guardar la información anterior\n";
//            cin>>ch;
//            if(ch=='S'){
//                FILE  *file;
//                file= fopen("data.txt","a");
//                fprintf(file, "%s %s %s %d %d %d \n", name, id, designation, age, ctc, experience );
//                fclose(file);
//                cout<<"\nSe ha agregado un nuevo empleado a la base de datos.\n";
//            }
//            else
//                addNewEmployee();
//            waitForEnter();
//        }
//        
		void addNewEmployee(void){ //adding records
            system("cls");
            cout<<"\n----------------------------------------";
            cout<<"\n Ingrese el nombre del empleado: ";
            cin>>name;
//            fgets(name, 30, stdin);
            cout<<"\n Ingrese el apellido del empleado: ";
            cin>>lastName;
//            fgets(lastName, 30, stdin);
//            for (int i = 0; i < strlen(name); i++)
//			{
//				if(name[i]=)
//				char actual = name[i];
//				printf("Tenemos el caracter '%c'\n", actual);
//			}
//			int i = 0;
//			while (cadena[i] != '\0')
//			{
//				char actual = cadena[indice];
//				printf("Tenemos el caracter '%c'\n", actual);
//				indice++;
//			}
//            if (isalpha(name)) {
//    			std::cout << "\n\t Ingreso Valido";
//  			} else {
//    			std::cout << "Ingrese de Nuevo el nombre del empleado: ";
//    			cin>>name;
//  			}
//			scanf("%[^\n]%*c", name);
//			fgets(name, 30, stdin);
            cout<<"\n----------------------------------------";
            cout<<"\n Ingrese la identificación del empleado [max 4 digitos]: ";
            cin>>id;
            if(id<0||id==" "){
            	cout<<"Ingrese un ID valido: ";
				cin>>id;
			}
            cout<<"\n----------------------------------------";
            cout<<"\n Ingrese la designación[sinEspacios] \t[Empleado, Gerente, Administrador] \n";
            cin>>designation;
//            ingresarDato(designation);
//            fgets(designation, 30, stdin);
			if(designation!="Empleado"||designation!="Gerente"||designation!="Administrador"||designation==" "){
					cout<<"Ingrese un puesto Correcto: ";
					cin>>designation;
//					fgets(designation, 30, stdin);
				}
            cout<<"\n----------------------------------------";
            cout<<"\n Ingrese la edad del empleado: ";
            cin>>age;
            if(age<0||age<18){
            	cout<<"Ingrese una edad valida : ";
				cin>>age;
			}
            cout<<"\n----------------------------------------";
            cout<<"\n Ingrese el sueldo del empleado: ";
            cin>>ctc;
            cout<<"\n----------------------------------------";
            cout<<"\n Ingrese la experiencia del empleado [ANIOS]: ";
            cin>>experience;
            cout<<"\n----------------------------------------";

            char ch;
            cout<<"\nIngrese 'S' para guardar la información anterior\n";
            cin>>ch;
            if(ch=='S'){
                FILE  *file;
                file= fopen("data.txt","a");
                fprintf(file, "%s %s %s %s %d %d %d \n", name, lastName, id, designation, age, ctc, experience );
                fclose(file);
                cout<<"\nSe ha agregado un nuevo empleado a la base de datos.\n";
            }
            else
                addNewEmployee();
            waitForEnter();
        }
        
//        void MenuDesign(){
//        	int a;
//        	cout<<"\n\t\t\t=======DESIGNACION========================";
//            cout<<"\n\t\t\t   1:   Empleado";
//            cout<<"\n\t\t\t   2:   Gerente";
//            cout<<"\n\t\t\t   3:   Secretario";
//            cout<<"\n\t\t\t   4:   SubGerente";
//            cout<<"\n\t\t\t   5:   Otro [Introducir nueva Designacion]";
//            cout<<"\n\n\t\t\t   Ingrese su elección: ";
//            cin>>a;
//            switch (a) {
//                    case 1:{
//                    	const char design[30]="Empleado";
//                        strcpy(designation, design);	
//                        cout<<designation;
//						break;
//					}
//                    case 2:{
//                    	const char design[30]="Gerente";
//                        strcpy(designation, design);	
//                        cout<<designation;
//						break;
//					}
//                    case 3:{
//                    	const char design[30]="Secretario";
//                        strcpy(designation, design);	
//                        cout<<designation;
//						break;
//					}
//                    case 4:{
//                    	const char design[30]="SubGerente";
//                        strcpy(designation, design);	
//                        cout<<designation;
//						break;
//					}
//                    case 5:{
//                    	cout<<"\n Ingrese nueva designación: ";
//            			cin>>designation;
//                        break;
//					}
//                        
//                    default:{
//                    	cout<<"\n ¡Lo siento! Ingrese un valor válido \n";
//						break;
//					}
//                }
//                //return;
//		}
//		void ValidaEmpl(char c){
//			if(c=="Empleado"||c=="Gerente"){
//				print
//			}
//		}

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
                while(fscanf(file, "%s %s %s %s %d %d %d", &name[0], &lastName[30],&id[0] , &designation[0], &age, &ctc, &experience)!=EOF)
                    if(strcmp(checkId, id)!=0)
                        fprintf(tempfile, "%s %s %s %s %d %d %d \n", name, lastName, id, designation, age, ctc, experience );
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
//        char* ingresarDato(char *msj){
//        	char *dato=new char[10],c;
//			int i=0;
//			printf("%s ",msj);
//			while((c=getch())!=13){
//				if(c>='0'&& c<='9'){
//					printf("%c",c);
//					dato[i++]=c;
//				}
//				else if(c==8||c==127){
//					printf("\b \b");
//					dato[i--]=0;
//				}
//			}
//			dato[i]='\0';
//			return dato;
//		}
//		
//		char* ingresarDatoSinMsj(){
//			char *dato=new char[10],c;
//			int i=0;
//			while((c=getch())!=13){
//				if(c>='0'&& c<='9'){
//					printf("%c",c);
//					dato[i++]=c;
//				}
//				else if(c==8||c==127){
//					printf("\b \b");
//					dato[i--]=0;
//				}
//			}
//			dato[i]='\0';
//			return dato;
//		}

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

