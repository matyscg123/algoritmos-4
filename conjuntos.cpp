#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include<string.h>
#include <stdio.h>
#include<math.h>
#include <string>

using namespace std;


struct Nodo{
  int numeroelementos;
 
  string elementos[20],nombreconjunto;
  Nodo *siguiente;
};


struct nodo{
      char dato;
      struct nodo *sgte;
};
typedef struct nodo *TPila;
void insertar(Nodo);
void insertar2(Nodo);
void insertar3(Nodo);
void mostrar(Nodo);
void solucion();
TPila crearNodo(char x)
{
      TPila newNodo = new(struct nodo);
      newNodo->dato = x;
      return newNodo;
}

void push(TPila &top, char x)
{
     TPila aux = crearNodo(x);
     aux->sgte = top;
     top = aux;
}

char pop(TPila &top)
{
     int c ;
     TPila aux;
     
     aux = top ;
     c = aux->dato;  
     top = aux->sgte ;
     delete(aux);
     return c;
}

void balanceoSimbolos( TPila &p, string cad)
{
     TPila aux;
     int i = 0;
     
     while( cad[i] != '\0')
     {
            if( cad[i]=='(' || cad[i]=='[' || cad[i]=='{' )
            {
                 push( p, cad[i] );          
            }
            else if( cad[i]==')' || cad[i]==']' || cad[i]=='}' )
            {
                 aux = p;
                 
                 if(aux!=NULL)
                 {
                      if( cad[i]==')' )
                      {
                           if( aux->dato == '(')
                              pop( p );
                      }
                      else if( cad[i]==']' )
                      {
                           if( aux->dato == '[')
                              pop( p );
                      }
                      else if( cad[i]=='}' )
                      {
                           if( aux->dato == '{')
                              pop( p );
                      }        
                 }
                 else
                     push( p, cad[i] );
            }
            i++;           
     }
     
     if(p==NULL)
         cout<<"\n\tLA EXPRECION ES CORRECTA"<<endl;
     else
         cout<<"\n\tLA EXPRECION ES INCORRECTA"<<endl;          
     
     
}

	
	void insertar(Nodo *&lista){
		string vector[] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
	
	int canelem=0,can=0,sumcon=0;
	 Nodo *nuevo = new Nodo();
	cout<<"ingrese el nombre del conjunto: ";cin>>nuevo->nombreconjunto;
		cout<<"ingrese el numero de elementos que desea ingresar en el conjunto """<<nuevo->nombreconjunto<<""" :";cin>>nuevo->numeroelementos;
		int i=0;
		while(i<nuevo->numeroelementos){
			cout<<"ingrese el valor para la posicion "<<i<<" :\n";cin>>nuevo->elementos[i];
			i++;
		}
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
	
	
	void insertar2(Nodo *&lista){
			Nodo *aux1 = new Nodo();
		Nodo *nuevo = new Nodo();
		aux1=lista;
		nuevo->nombreconjunto="Conjunto universal";
	
		int suma;
		while(aux1!=NULL){
			suma=suma+aux1->numeroelementos;
			aux1=aux1->siguiente;
		}
		int cantidad=0;
		cout<<"\n ingrese el numero de elementos que desea ingrear al conjunto universal";cin>>cantidad;
		suma=suma+cantidad;
		nuevo->numeroelementos=suma;
		string elementosUn[suma];
		int x=0,z=0;
		aux1=lista;
		while(aux1!=NULL){
			x=0;
			while(x<aux1->numeroelementos){
			elementosUn[z]=aux1->elementos[x];
			z++;
			x++;
			}
			aux1=aux1->siguiente;
		}
		x=0;
		while(x<cantidad){
			cout<<"ingrese el elemento : ";cin>>elementosUn[z];
			x++;
			z++;
		}
		x=0;
		while(x<suma){
			nuevo->elementos[x]=elementosUn[x];
			x++;
		}
		
		
		
		
		
		
		
		
		
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

void insertar3(Nodo *&lista){
		Nodo *aux1 = new Nodo();
		Nodo *nuevo = new Nodo();
		aux1=lista;
		nuevo->nombreconjunto="Conjunto universal";
	
		int suma;
		while(aux1!=NULL){
			suma=suma+aux1->numeroelementos;
			aux1=aux1->siguiente;
		}
		nuevo->numeroelementos=suma;
		string elementosUn[suma];
		int x=0,z=0;
		aux1=lista;
		while(aux1!=NULL){
			x=0;
			while(x<aux1->numeroelementos){
			elementosUn[z]=aux1->elementos[x];
			z++;
			x++;
			}
			aux1=aux1->siguiente;
		}
		x=0;
		while(x<suma){
			nuevo->elementos[x]=elementosUn[x];
			x++;
		}
	
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

	void mostrar(Nodo *lista){
		 Nodo *aux= new Nodo();
		 aux=lista;
		 while(aux!=NULL){
		 	cout<<"Conjunto\n";
		 	cout<<"El nombre del conjunto es : ";cout<<aux->nombreconjunto<<"\n";
		 	cout<<"El numero de datos que contiene el conjunto es : ";cout<<aux->numeroelementos<<"\n";
		 	int i=0;
		 	cout<<"Los elementos del conjunto son : \n";
		 	while(i<aux->numeroelementos){
		 		cout<<aux->elementos[i]<<", ";
		 		i++;
			 }cout<<"\n";
			 cout<<"|-----------------------------------------------------|";
			 cout<<"\n";
			 aux=aux->siguiente;
		 }
	}

void solucion(){
	cout<<"|---------------CONJUNTOS---------------|\n";
	cout<<"Las operaciones que puede realizar son :\n";
	cout<<"Union(+), diferencia(-), interseccion(*) y diferencia simetrica(^). \n\n";
	
	
	
}
int main()
{
    TPila pila = NULL;   
    string cad;
     struct Nodo *lista=NULL;
    /* int cancon=0;
	cout<<"ingrese el numero de conjuntos que desea operar: ";cin>>cancon;
	int i=0;
	while(i<cancon){
		insertar(lista);
		i++;
	}
	int op;
     cout<<"si desea agregar mas valores al conjunto universal (1) para si o (2) para no : ";cin>>op; 
     while(op!=1 && op!=2){
     	cout<<"ingrese una opcion valida";cin>>op;
     	
	 }
	 if(op==1){
	 	insertar2(lista);
	 }else{
	 	insertar3(lista);
	 }*/
   /* cout << " Ingrese expresion usando los conjuntos ingresados anteriormente : ";
    cin>>cad;
    string cad1=cad;
    balanceoSimbolos( pila, cad );
    mostrar(lista);*/
    solucion();
    
}
