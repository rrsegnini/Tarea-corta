#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <sstream>
#include <map>
#include <cmath> 

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
    
    int LeerArchivo(string num_archivo);
    pnodo RetornarPrimero();
    string LeerPrimerCaracter(string num_archivo);
    lista recorrer();
    string retUltimo();
    void evaluar();
    int evaluarNumeros(int numero1, int numero2, string operacion);
    
    
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

//MetÃƒÂ­ estas funciones en la clase de lista *
string lista::LeerPrimerCaracter(string num_archivo) //Esta funcion saca solo la primera linea del .txt y lo mete en Arch1
	{
	string line;
	string Arch = "Arch";
	string txt = ".txt";
	string numero_archivo = Arch  + num_archivo + txt;
	
	const char * c = numero_archivo.c_str();
  	ifstream myfile (c);
  	if (myfile.is_open())
  		{
    	while ( getline (myfile,line) )
    		{
    		return line;
    		}
    	myfile.close();
		}
	}
	
	
int lista::LeerArchivo(string num_archivo) //Esta funcion saca todas las demas lineas
	{
	//Este es el que lee linea por linea

	string linea;
	string Arch = "Arch";
	string txt = ".txt";
	string numero_archivo = Arch  + num_archivo + txt;

	
	
	const char * c = numero_archivo.c_str(); //Para pasar el string a constant char
  	ifstream archivo (c); //Solo acepta constant chars
  	
  	if (archivo.is_open())
  		{
  		getline (archivo, linea);
    	while ( getline (archivo, linea) )
    		{
    		
    		InsertarFinal(linea);
       		
			}
    	archivo.close();
    	cout<<"Expresion original: ";
    	Mostrar();
  		}
  			
  	else cout << "No se puede abrir el archivo"; 
  	return 0;
	
	}
	

pnodo lista::RetornarPrimero() //Esta funcion retorna el puntero "primero" de una lista. SÃƒÂ­ se usa :P
	{
	return primero; 
	}



int convInt (string s){  //Convierte un string a un int
	int x;
	
	stringstream convert(s);
	convert >> x;
	cout << x<<endl;
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
	
	
	
lista lista :: recorrer(){ //recorre la lista que contiene la expresion original

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
				
				if (aux->valor == ")"){ 
					if (listaTemp.primero -> valor == "("){
						listaTemp.BorrarInicio();
					}else{
						pilaPosFijo.InsertarFinal(listaTemp.primero->valor);
						listaTemp.BorrarInicio();
						
					}
					
					
				}else{
					
					if (prioriDP(listaTemp.retUltimo()) >= prioriFP(aux->valor)){ 
					pilaPosFijo.InsertarFinal(listaTemp.retUltimo());
					listaTemp.BorrarFinal();
					listaTemp.InsertarFinal(aux->valor);
					
					}else{
					listaTemp.InsertarFinal(aux->valor);
					}
				
					
				}
				
			}
			
			}
		listaTemp.Mostrar();
		 aux = aux -> siguiente;
		
	
	}
	
	if (listaTemp.retUltimo() != ")"){
		pilaPosFijo.InsertarFinal(listaTemp.retUltimo());
	}
	
		
	cout<< "Lista Temp";
	listaTemp.Mostrar();
	cout<< "PosFijo: ";
	pilaPosFijo.Mostrar();
	return pilaPosFijo;
	}
	

void lista::evaluar(){
	//Evalua la expresion posfijo 
	
	int num1;
	int num2;
	pnodo aux = primero;
	lista listDeNumeros;
	int primerNumero = convInt(aux->valor);
	
	while (aux!=NULL)
		{
		//Mostrar();
		num1 = primerNumero;
		num2 = convInt(aux->siguiente->valor);
		
		//cout<<num1<<endl;
		//listDeNumeros.InsertarFinal(num1);
		//listDeNumeros.InsertarFinal(num2);
		//listDeNumeros.Mostrar();
		
		aux=aux->siguiente->siguiente;
		primerNumero = evaluarNumeros(num1, num2, aux->valor);
		
		}
	
	
}


int lista::evaluarNumeros(int numero1, int numero2, string operacion)
	{
	//string num1 = retUltimo();
	//convInt(num1);
	//cout<<convInt(num1);
	
	map <string, int> pFP;
  	
  	pFP["("]= 0;
	pFP["+"]= numero1+numero2;
	pFP["-"]= numero1-numero2;
	pFP["*"]= numero1*numero2;
	pFP["/"]= numero1/numero2;
	pFP["^"]= pow(numero1, numero2);
	

	cout<<"Resutlado: ";
	cout<<pFP [operacion]<<endl;
	return pFP [operacion]; 
  
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
   
   
   
   
//*************Yo creo que no hace falta hacerlo en un funcion aparte***************
	
	
	
}



	



int main()
	{
	NodoLista ExpOriginal; //La cola con los punteros 
	
	
	lista Arch1; //La lista (pila) donde se va a guardar la expresion del primer archivo
	lista Arch2;
	lista Arch3;
	lista Arch4;
	lista Arch5;
	
	string cont = "1";
	
	string PrimerCaracter = Arch1.LeerPrimerCaracter(cont); //Esto es para meter el primer caracter a la lista y crear un primero
	Arch1.InsertarFinal(PrimerCaracter); //Se inserta el primer caracter a la lista (pila)
	pnodo primero = Arch1.RetornarPrimero(); //Retorna el puntero "primero" de la lista para pegarlo a la cola
	ExpOriginal.insertar(primero); //Inserta el puntero a la NodoLista
	Arch1.LeerArchivo(cont); //LeerArchivo saca todos los demas elementos de la expresion y los mete a la lista (pila) Arch1
	lista ExpresionPostfijo = Arch1.recorrer();
	//ExpresionPostfijo.evaluar();
	
	
	cout<<"Presione ENTER para evaluar el siguiente archivo"<<endl;
	cin.get();
	
	

	cont = "2";
	PrimerCaracter = Arch2.LeerPrimerCaracter(cont); 
	Arch2.InsertarFinal(PrimerCaracter); 
	primero = Arch2.RetornarPrimero(); 
	ExpOriginal.insertar(primero); 
	Arch2.LeerArchivo(cont);
	Arch2.recorrer();
	cout<<"Presione ENTER para evaluar el siguiente archivo"<<endl;
	cin.get();
	
	
	cont = "3";
	PrimerCaracter = Arch3.LeerPrimerCaracter(cont); 
	Arch3.InsertarFinal(PrimerCaracter); 
	primero = Arch3.RetornarPrimero(); 
	ExpOriginal.insertar(primero); 
	Arch3.LeerArchivo(cont); 
	Arch3.recorrer();
	cout<<"Presione ENTER para evaluar el siguiente archivo"<<endl;
	cin.get();
	
	
	
	
	cont = "4";
	PrimerCaracter = Arch4.LeerPrimerCaracter(cont); 
	Arch4.InsertarFinal(PrimerCaracter); 
	primero = Arch4.RetornarPrimero(); 
	ExpOriginal.insertar(primero); 
	Arch4.LeerArchivo(cont); 
	Arch4.recorrer();
	cout<<"Presione ENTER para evaluar el siguiente archivo"<<endl;
	cin.get();
	
	
	cont = "5";
	PrimerCaracter = Arch5.LeerPrimerCaracter(cont); 
	Arch5.InsertarFinal(PrimerCaracter); 
	primero = Arch5.RetornarPrimero(); 
	ExpOriginal.insertar(primero); 
	Arch5.LeerArchivo(cont); 
	Arch5.recorrer();
	cout<<"Presione ENTER para SALIR"<<endl;
	cin.get();
	

	
	
	
	
	
	ExpOriginal.imprimir();
	//convInt("345");
	
	

	}

// prueba
