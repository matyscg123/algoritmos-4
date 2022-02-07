#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include<time.h>

using namespace std;
struct Nodo{
  int numeros ;
  Nodo *siguiente;
};
void insertar(Nodo *&,int);
void imprimir(Nodo *);
void odernarlista(Nodo *&);

int main(){
	
int tam=0,i=0,numero=0;
srand(time(NULL));
numero = rand();

 struct Nodo *lista=NULL;
cout<<"ingrese el numero de elemntos: \n";
cin>>tam;
while(i<tam){
	  numero=rand()%51;
	insertar(lista,numero);
	i++;
}
odernarlista(lista);
cout<<"Los numeros en la lista son: \n\n ";
imprimir(lista);
cout<<"\n ingrese el numero que desea buscar: \n";cin>>numero;	


	//Algoritmo de la Busqueda Binaria
	int inf,sup,mitad,j=0;
	char band='F';
	Nodo *aux3 = new Nodo();
	int p=0;
	aux3=lista;
	inf=0;
	sup=tam;
	i=0;
	while((inf<=sup)&&(j<tam)){
		mitad = (inf+sup)/2;
		aux3=lista;
		
		p=0;
		while(p<mitad){
			aux3=aux3->siguiente;
			p++;
		}
		if(aux3->siguiente==NULL){
			break;
		}
		if((aux3->numeros+aux3->siguiente->numeros) == numero ){
			band='V';
			break;
		}
		if((aux3->numeros+aux3->siguiente->numeros)>numero){
			sup = mitad;
			mitad = (inf+sup)/2;
		}
		if((aux3->numeros+aux3->siguiente->numeros)<numero){
			inf = mitad;
			mitad = (inf+sup)/2;
		}
		j++;
	}

	if(band == 'V'){
		cout<<"El numero se encontro";
	}
	else{
		cout<<"El numero NO se encontro";
	}




}


void insertar(Nodo *&lista,int numero){
	Nodo *nuevo=new Nodo ();
	
	nuevo->numeros=numero;
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
void imprimir(Nodo *lista){
Nodo *aux = new Nodo();
aux=lista;
while(aux!=NULL){
	cout<<aux->numeros<<",";
	aux=aux->siguiente;
}
	
}

void odernarlista(Nodo *&lista){
	Nodo *aux1 = new Nodo();
	Nodo *aux2 = new Nodo();
	aux1=lista;
	int numero;	
	while(aux1!=NULL){
	aux2=lista;
	while(aux2->siguiente!=NULL){
		if(aux1->numeros<aux2->numeros){
			numero=aux2->numeros;
			aux2->numeros=aux1->numeros;
			aux1->numeros=numero;
		}
		aux2=aux2->siguiente;
	}
	aux1=aux1->siguiente;
	}
}
