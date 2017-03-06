#include <iostream>
#include <fstream>
#include <string>

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
 
void lista::InsertarFinal(string v)
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
      cout << aux->valor << "-> ";
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
int lista::LeerArchivo() //Esta funciona saca todas las demas lineas
	{
	//Este es el que lee line by line

	string line;
  	ifstream myfile ("Arch1.txt");
  	if (myfile.is_open())
  		{
  		getline (myfile,line);
    	while ( getline (myfile,line) )
    		{
    		
    		InsertarFinal(line);
      		//cout << line << '\n';     		
			}
    	myfile.close();
    	Mostrar();
  		}
  			
  	else cout << "Unable to open file"; 
  	return 0;
	}

pnodo lista::RetornarPrimero() //Esta funcion retorna el puntero "primero" de una lista. Sí se usa :P
	{
	cout<<primero<<endl;
	return primero; 
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


int main()
	{
	NodoLista ExpOriginal; //La cola con los punteros 
	
	
	lista Arch1; //La lista (pila) donde se va a guardar la expresión del primer archivo
	string PrimerCaracter = Arch1.LeerPrimerCaracter(); //Esto es para meter el primer caracter a la lista y crear un primero
	Arch1.InsertarFinal(PrimerCaracter); //Se inserta el primer caracter a la lista (pila)
	
	pnodo primero = Arch1.RetornarPrimero(); //Retorna el puntero "primero" de la lista para pegarlo a la cola
	
	
	//ExpOriginal.imprimir();
	//ExpOriginal.insertar(Arch1.RetornarPrimero());
	//ExpOriginal.imprimir();
	
	ExpOriginal.insertar(primero); //Inserta el puntero a la NodoLista
	
	Arch1.LeerArchivo(); //LeerArchivo saca todos los demas elementos de la expresion y los mete a la lista (pila) Arch1
	
	
	ExpOriginal.imprimir();
	}

// prueba
