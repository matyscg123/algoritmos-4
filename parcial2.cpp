#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include <string>
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
void imprimir(Nodo *);
void generarArchivo(Nodo *);
void validarArchivo(Nodo *&);
void vaciarlista (Nodo *&);
//void imprimir(Nodo *);
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
    cout << " 2. salida vehiculo" << endl;
    cout << " 3. Salir  " << endl;
    cout << "\n INGRESE OPCION: ";
    cin >> op;

      	switch (op)
		{
			case 1:
	  		ingreso(lista);
	  		imprimir(lista);
	  			break;

			case 2:
				salida(lista);
	  			break;
	  
			case 3:
				
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
	cout<<"Ingrese la placa :\n";
	cin>>placa;	
	cout<<"\n Ingrese el tipo \n";
	cout<<" (1)moto\n (2)automovil\n (3)camioneta\n (4)camion :\n";
	cin>>tipo;	
	time_t t;
	cout<<"ingrese la fecha :\n";cin>>fecha;
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
				cout<<tipo<<"tipo aqui";
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
void imprimir(Nodo *lista){
	Nodo *aux = new Nodo();
	aux=lista;
	while(aux->siguiente!=NULL){
	cout<<"\n"<<aux->placa;
	if(aux->tipoV=="1"){
	cout<<"\nmoto";	
	}
	if(aux->tipoV=="2"){
	cout<<"\nautomovil";	
	}
	if(aux->tipoV=="3"){
	cout<<"\nCamioneta";	
	}
	if(aux->tipoV=="4"){
	cout<<"\nCamion";	
	}
	cout<<"\n"<<aux->fecha;
		aux=aux->siguiente;
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
