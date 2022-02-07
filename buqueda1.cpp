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
cout<<"Los numeros en la lista son: \n\n ";
imprimir(lista);

cout<<"\n ingrese el numero que desea buscar: \n";cin>>numero;	
Nodo *aux1 = new Nodo();
Nodo *aux2 = new Nodo();
aux1=lista;
int suma=0,x=0;
while(aux1!=NULL){
	aux2=lista;
	while(aux2->siguiente!=NULL){
	suma=aux1->numeros+aux2->numeros;	
	if(suma==numero){
		x=1;
	}	
	aux2=aux2->siguiente;
	}
	aux1=aux1->siguiente;
}


if(x==1){
	cout<<"\nSi hay dos numeros que al sumarlos su resultado es :"<<numero;
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
