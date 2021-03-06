#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include<regex>
#include <time.h>
#include <ctime>
#include <fstream>
using namespace std;
struct Nodo{
  string placa;
  string tipoV;
  string fecha;
  Nodo *siguiente;
};
void menuP(Nodo *&);
void ingreso(Nodo *&);
void salida(Nodo *&);
void generarArchivo(Nodo *);
void validarArchivo(Nodo *&);
void vaciarlista (Nodo *&);
void salir();
bool validarplacaM(string);
bool validarplacaC(string);
int validarP(Nodo *,string);

int main(){
	struct Nodo *lista;
	lista = NULL;
	validarArchivo(lista);
	menuP(lista);
	generarArchivo(lista);
	vaciarlista(lista);
}

void menuP(Nodo *&lista){
	
  	int op;			
  	do
    {
    cout << "\n\t MENU DE OPCIONES\n\n";
    cout << " 1. Ingresar " << endl;
    cout << " 2. Salida vehiculo" << endl;
    cout << " 3. Salir  " << endl;
    cout << "\n INGRESE OPCION: ";
    cin >> op;

      	switch (op)
		{
			case 1:
	  		ingreso(lista);
	  			break;

			case 2:
				salida(lista);
	  			break;
	  
			case 3:
				salir();
				break;		
		}

      	cout << endl << endl;
      	system ("pause");
      	system ("cls");

    }while (op != 3);
  
	
}
void ingreso(Nodo *&lista){
	Nodo *nuevo=new Nodo ();
	string placa;
	string tipo;
 	string fecha;
	
	int op=0;	
	while(op==0){
	op=1;
	//elegir el tipo de vehiculo a ingresar
	cout<<"\n Ingrese el tipo de vehiculo\n";
	cout<<" (1)moto\n (2)automovil\n (3)camioneta\n (4)camion :\n";
	cin>>tipo;
	if(tipo!="1" && tipo!="2" && tipo!="3" && tipo!="4"){
		op=0;
	}	
	}	
	
	//ingresar y validar la placa
	int u=0;
	if(tipo=="1"){
		while(u==0){
			cout<<"Ingrese la placa :\n";
			cin>>placa;
			if(validarplacaM(placa) && validarP(lista,placa)==1){
				cout<<"placa valido"<<endl;
			u=1;	
			}
			else{
				cout<<"placa Inavalido"<<endl;
			u=0;	
			}
		}
	}	else{
		while(u==0){
			cout<<"Ingrese la placa :\n";
			cin>>placa;
			if(validarplacaC(placa) && validarP(lista,placa)==1){
				cout<<"placa valido"<<endl;
			u=1;	
			}
			else{
				cout<<"placa Inavalido"<<endl;
			u=0;	
			}
		}
	}
	//ingresar la hora actual desde el odenador 
		time_t tiempo = time(0);
        struct tm *tlocal = localtime(&tiempo);
        char output[128];
        strftime(output,128,"%d/%m/%y-%H:%M:%S",tlocal);
        printf("%s\n",output);
	fecha=output;
	nuevo->placa=placa;
	nuevo->tipoV=tipo;
	nuevo->fecha=fecha;
	Nodo *aux=lista;
	Nodo *aux2;
	while(aux!=NULL){
		aux2=aux;
		aux=aux->siguiente;
	}
	if (lista == aux)
		{
			lista = nuevo;
		}else
		{
		aux2->siguiente = nuevo;
		}
		nuevo->siguiente = aux;
	cout<<"\ninsertado en la lista corectamente\n";
}

bool validarplacaM(string ced){ 
	const regex exp("\\D{3}\\d{2}\\D{1}");
	return regex_match(ced,exp);
}
bool validarplacaC(string ced){ 
	const regex exp("\\D{3}\\d{3}");
	return regex_match(ced,exp);
}
int validarP(Nodo *lista,string placa){
	Nodo *p = new Nodo();
	p=lista;
	int op=1;
	while(p!=NULL){
	if(placa==p->placa){
	op=0;
	}		
	p=p->siguiente;	
	}
	if(op==0){
		return op;
	}else{
		
		return op;
	}
	
}
void salida(Nodo *&lista){
	string co,tipo;
	int moto=0,automovil=0,camioneta=0,camion=0,horas=0;
	int total=0;
	if (lista == NULL)
	{
		cout<<"No hay nada en la lista";
	}else
	{
		cout<<"Digite el vehiculo de salida : ";
		cin>>co;
		cout<<"\nDigite el total de horas :";cin>>horas;
		Nodo *p = new Nodo();
		p=lista;
		while(p!=NULL){
			if(co==p->placa){
				tipo=p->tipoV;
			}
			p=p->siguiente;
		}
		ifstream fichero;
		fichero.open("tarifas.txt", ios::in);
		if (!fichero.fail())
	{
		fichero>>moto;
		fichero>>automovil;
		fichero>>camioneta;
		fichero>>camion;
		
	}else
	{
		cout<<"No se cargo la informacion\n";
	}
	
	if(tipo=="1"){
			total=horas*moto;
		}
		
		if(tipo=="2"){
			total=horas*automovil;
		}
		
		if(tipo=="3"){
			total=horas*camioneta;
		}
		
		if(tipo=="4"){
			total=horas*camion;
		}
		Nodo *aux1;
		Nodo *aux2 = NULL;
		aux1 = lista;
		while ((aux1 != NULL) && (co != aux1->placa))
		{
			aux2 = aux1;
			aux1 = aux1->siguiente;
		}
		if (aux1 == NULL)
		{
			cout<<"la placa no existe";
		}else if (aux2 == NULL)
		{
			lista =  lista->siguiente;
			delete aux1;
		}else
		{
			aux2->siguiente = aux1->siguiente;
			delete aux1;	
		}
	}
		cout<<"\nEl total a pagar es de  "<<total;
		ifstream file1;
		int valor=0;
		file1.open("total.txt", ios::in);	
		if (!file1.fail())
		{
		file1>>valor;
		file1.close();
		}
		ofstream file;
		file.open("total.txt", ios::out);
  		if(!file.fail()){
			valor=valor+total;
			file<<valor;
			file.close();
		}else{
			cout<<"Error al crear el archivo";
			exit(1);
		}
		
}

void generarArchivo(Nodo *lista)
{	
	ofstream file;
	
	if(lista == NULL){
		cout<<"Lista Vacia, No se genero el archivo";
	}
	else{
  		file.open("archivo.txt", ios::out);
  		if(file.fail()){
			cout<<"Error al crear el archivo";
			exit(1);
		}
		
		Nodo *aux = lista;

		while (aux != NULL)
		{
  			file<<aux->placa<<"  "<<aux->tipoV<<"  "<<aux->fecha<<"\n";
        	aux = aux->siguiente;
   		}
    	file.close();
	}		
}
void validarArchivo (Nodo *&lista)
{
	string plac, tip;
	string fech;
	ifstream file;
	file.open("archivo.txt", ios::in);	
	Nodo *aux = NULL;
	if (!file.fail())
	{
		file>>plac;
		while (!file.eof())
		{
			Nodo *nuevoNodo = new Nodo ();
			file>>tip;
			file>>fech;
			nuevoNodo->placa = plac;
			nuevoNodo->tipoV = tip;
			nuevoNodo->fecha = fech;
			nuevoNodo->siguiente = NULL;
			if (lista == NULL){
				lista = nuevoNodo;
				aux = lista;
			}
			else{
				aux->siguiente = nuevoNodo;
			}
			aux = nuevoNodo;
			file>>plac;
		}
		file.close();
	}else
	{
		cout<<"No se cargo la informacion\n";
	}
}		
 void salir(){
 	
 		ifstream file1;
		int valor=0;
		file1.open("total.txt", ios::in);	
		if (!file1.fail())
		{
		file1>>valor;
		cout<<"El total que debe haber en caja es de : "<<valor;
		file1.close();
		}
		ofstream file;
		file.open("total.txt", ios::out);
  		if(!file.fail()){
  			valor=0;
			file<<valor;
			file.close();
		}else{
			cout<<"Error al crear el archivo";
			exit(1);
		}
 }
void vaciarlista (Nodo *&lista)
{
	Nodo *aux1 = lista;
	while (lista != NULL)
	{
		lista = lista->siguiente;
		delete aux1;
		aux1 = lista;
	}
	cout<<"Se libero la memoria";
}
