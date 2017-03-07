#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <sstream>
#include <map>

using namespace std;



class nodo {
   public:
    nodo(string v)
    {
       valor = v;
       siguiente = NULL;
    }

nodo(string v, nodo * signodo)
    {
       valor = v;
       siguiente = signodo;
    }

nodo(int v)
    {
       valor = v;
       siguiente = NULL;
    }
    
nodo(int v, nodo * signodo)
    {
       valor = v;
       siguiente = signodo;
    }
    
   private:
    string valor;
    nodo *siguiente;
    
        
   friend class lista;
};

typedef nodo *pnodo;

class lista {
   public:
    lista() { primero = actual = NULL; }
    ~lista();
    
    void InsertarInicio(string v);
    void InsertarFinal(string v);
    void InsertarFinal(int v);
    void InsertarPos (string v, int pos);
    void EliminarInicio();
    void EliminarFinal();
    void EliminarPos(int pos);
    bool ListaVacia() { return primero == NULL; } 
    void Imprimir();
    void Borrar(int v);
    void Mostrar();
    void Siguiente();
    void Primero();
    void Ultimo();
    void BorrarFinal();
    void BorrarInicio();
    void borrarPosicion(int pos);
    int largoLista();
    int LeerArchivo();
    pnodo RetornarPrimero();
    string LeerPrimerCaracter();
    void recorrer();
    string retUltimo();
    void evaluar();
    
    
   private:
    pnodo primero;
    pnodo actual;
};

lista::~lista()
{
   pnodo aux;
   
   while(primero) {
      aux = primero;
      primero = primero->siguiente;
      delete aux;
   }
   actual = NULL;
}

int lista::largoLista(){
    int cont=0;

    pnodo aux;
    aux = primero;
    if(ListaVacia()){
        return cont;
    }else{
        while(aux!=NULL){
        aux=aux->siguiente;
        cont++;
    }
    return cont;
    }
    
}


void lista::InsertarInicio(string v)
{
   if (ListaVacia())
     primero = new nodo(v);
   else
     primero=new nodo (v,primero);
}
 
 
void lista::InsertarFinal (string v)
{
   if (ListaVacia())
     primero = new nodo(v);
   else
     { pnodo aux = primero;
        while ( aux->siguiente != NULL)
          aux= aux->siguiente;
        aux->siguiente=new nodo(v);
      }    
}

void lista::InsertarFinal (int v)
{
   if (ListaVacia())
     primero = new nodo(v);
   else
     { pnodo aux = primero;
        while ( aux->siguiente != NULL)
          aux= aux->siguiente;
        aux->siguiente=new nodo(v);
      }    
}

void lista::InsertarPos(string v,int pos)
{
   if (ListaVacia())
     primero = new nodo(v);
   else{
        if(pos <=1){
          pnodo nuevo = new nodo(v);
          nuevo->siguiente= primero;
          primero= nuevo;     
        }      
        else{
             pnodo aux= primero;
             int i =2;
             while((i != pos )&&(aux->siguiente!= NULL)){
                   i++;
                   aux=aux->siguiente;
             }
             pnodo nuevo= new nodo(v);
             nuevo->siguiente=aux->siguiente;
             aux->siguiente=nuevo;
             
        }
        }
}
      
void lista::BorrarFinal()
{
    if (ListaVacia()){
     cout << "No hay elementos en la lista:" << endl;
    
   }else{
        if (primero->siguiente == NULL) {
                primero= NULL;
            } else {

                pnodo aux = primero;
                while (aux->siguiente->siguiente != NULL) {
                    aux = aux->siguiente;

                }
                
              pnodo temp = aux->siguiente;
              aux->siguiente= NULL;

                
                delete temp;
            }
        }
}

void lista::BorrarInicio()
{
    if (ListaVacia()){
     cout << "No hay elementos en la lista:" << endl;
    
   }else{
        if (primero->siguiente == NULL) {
                primero= NULL;
            } else {

                pnodo aux = primero;
                primero=primero->siguiente;                
                delete aux;
            }
        }
}



void lista:: borrarPosicion(int pos){
     if(ListaVacia()){
              cout << "Lista vacia" <<endl;
    }else{
         if((pos>largoLista())||(pos<0)){
        cout << "Error en posicion" << endl;
        }else{
        if(pos==1){
        primero=primero->siguiente;
        }else{
          int cont=2;
            pnodo aux=  primero;
            while(cont<pos){
             aux=aux->siguiente;
             cont++;
            }
            aux->siguiente=aux->siguiente->siguiente;
            }
        }
     }

}
 

void lista::Mostrar()
{
   nodo *aux;
   
   aux = primero;
   while(aux) {
      cout << aux->valor << " -> ";
      aux = aux->siguiente;
   }
   cout << endl;
}

void lista::Siguiente()
{
   if(actual) actual = actual->siguiente;
}


void lista::Primero()
{
	
	cout<<"Primero UNO: ";
	cout<<primero<<endl;
   actual = primero;
}


void lista::Ultimo()
{
   actual = primero;  
   if(!ListaVacia()) 
      while(actual->siguiente) Siguiente();
} 

string lista :: retUltimo(){ //Retorna el ultimo valor de una lista 
	pnodo aux;
	aux = primero;
	
	while (aux ->siguiente != NULL){
		aux = aux ->siguiente;
	}
	
	return aux->valor;
}

//Metí estas funciones en la clase de lista *
string lista::LeerPrimerCaracter() //Esta funcion saca solo la primera linea del .txt y lo mete en Arch1
	{
	string line;
  	ifstream myfile ("Arch1.txt");
  	if (myfile.is_open())
  		{
    	while ( getline (myfile,line) )
    		{
    		return line;
    		}
    	myfile.close();
		}
	}
int lista::LeerArchivo() //Esta funcion saca todas las demas lineas
	{
	//Este es el que lee linea por linea

	string linea;
  	ifstream archivo ("Arch1.txt");
  	
  	if (archivo.is_open())
  		{
  		getline (archivo, linea);
    	while ( getline (archivo, linea) )
    		{
    		
    		InsertarFinal(linea);
       		
			}
    	archivo.close();
    	//Mostrar();
  		}
  			
  	else cout << "No se puede abrir el archivo"; 
  	return 0;
	}

pnodo lista::RetornarPrimero() //Esta funcion retorna el puntero "primero" de una lista. Sí se usa :P
	{
	cout<<primero<<endl;
	return primero; 
	}



int convInt (string s){  //Convierte un string a un int
	int x;
	
	stringstream convert(s);
	convert >> x;
	cout << x;
	return x;
			
	}
	
int prioriDP (string s){ //Retorna la prioridad de un operador dentro de la pila usando un mapa

  map <string, int> pDP;
  
  pDP["("]= 0;
  pDP["+"]= 1;
  pDP["-"]= 1;
  pDP["*"]= 2;
  pDP["/"]= 2;
  pDP["^"]= 3;

  return pDP [s];  
}



int prioriFP (string s){
	
  map <string, int> pFP;
  
  pFP["("]= 5;
  pFP["+"]= 1;
  pFP["-"]= 1;
  pFP["*"]= 2;
  pFP["/"]= 2;
  pFP["^"]= 4;

  return pFP [s];  
}
	
	
	
void lista :: recorrer(){ //recorre la lista que contiene la expresion original

	pnodo aux;
	aux = primero;
	lista listaTemp;
	lista pilaPosFijo;
	int tempNum;
	
	while (aux){
		
		if (isdigit(aux->valor[0])){  //Si es numero, la pone en el posfijo de una vez
			//tempNum = convInt(aux->valor);
			//pilaPosFijo.InsertarFinal(tempNum);
			pilaPosFijo.InsertarFinal(aux->valor);
			
		
		}else{
			if (listaTemp.ListaVacia()){  //Si la listatemp de simbolos esta vacia, mete el operador de una vez
				listaTemp.InsertarFinal(aux->valor);
				
			}else{
				if (prioriDP(listaTemp.retUltimo()) >= prioriFP(aux->valor)){ 
					pilaPosFijo.InsertarFinal(listaTemp.retUltimo());
					listaTemp.BorrarFinal();
					listaTemp.InsertarFinal(aux->valor);
					
				if (aux->valor == ")"){ 
					listaTemp.BorrarInicio();
					
				}
				}else{
					listaTemp.InsertarFinal(aux->valor);
					
				}
				
			}
			
			}
		 aux = aux -> siguiente;
		
	
	}
	
	if (listaTemp.retUltimo() != ")"){
		pilaPosFijo.InsertarFinal(listaTemp.retUltimo());
	}
	
		
	//cout<< "Lista Temp";
	//listaTemp.Mostrar();
	cout<< "PosFijo ";
	pilaPosFijo.Mostrar();
	
	}
	

void lista::evaluar(){
	//Evalua la expresion posfijo 
	
}











class NodoLista 
{
   private:
   int frente;
   int fondo;
   pnodo Cola [5]={0};
   int tamano;


public:
       NodoLista(){
       frente = 0;
       fondo = -1;
       tamano = sizeof(Cola)/sizeof(int);
        for(int i =0;i<tamano;i++){
         Cola[i]=0;    
           }
       }
       
      bool ColaVacia(){return fondo < frente;}        
	  void insertar(pnodo v); 
	  void eliminar ();
	  void imprimir();
	  void recorrer();
	  
	  //int LeerArchivo();
};


void NodoLista:: insertar (pnodo v)
{
         if(fondo < tamano){
             fondo++;
             Cola[fondo]= v; 
           
         }
         else{
         cout<<"La cola esta llena";  
         }
}   


void NodoLista:: eliminar ()
{
         if(!ColaVacia()){
            frente++;
         }
         else{
         cout<<"La cola esta vacia";  
         }
}  


void NodoLista:: imprimir(){
     for(int i = frente;i<fondo+1;i++){
         cout<<Cola[i]<<"->";    
           }
}


void NodoLista::recorrer(){ //Para recorrer la cola
   //Para recorrer la cola ExpOriginal, entra a cada lista y hace lista.recorrer()
   //Cuando se termine de evaluar, pasa a la siguiente
	
}



	



int main()
	{
	NodoLista ExpOriginal; //La cola con los punteros 
	
	
	lista Arch1; //La lista (pila) donde se va a guardar la expresion del primer archivo
	string PrimerCaracter = Arch1.LeerPrimerCaracter(); //Esto es para meter el primer caracter a la lista y crear un primero
	Arch1.InsertarFinal(PrimerCaracter); //Se inserta el primer caracter a la lista (pila)
	
	pnodo primero = Arch1.RetornarPrimero(); //Retorna el puntero "primero" de la lista para pegarlo a la cola
	
	
	
	Arch1.Primero();
	ExpOriginal.insertar(primero); //Inserta el puntero a la NodoLista
	
	Arch1.LeerArchivo(); //LeerArchivo saca todos los demas elementos de la expresion y los mete a la lista (pila) Arch1
	ExpOriginal.imprimir();
	//convInt("345");
	Arch1.recorrer();
	

	}

// prueba
