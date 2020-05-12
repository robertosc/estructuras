#include<iostream>
#include<cstdio>

using namespace std;

template <class T>
class Nodo{
	private:
		Nodo<T> *siguiente;
		T valor;
	public:
		Nodo<T>(T val){  //Constructor
			this->valor = val;
			this->siguiente = nullptr;
		}

		void establecerSiguiente(Nodo<T> *nodo){
			siguiente = nodo;
		}

		T obtenerValor(){
			return valor;
		}

		Nodo<T> *obtenerSiguiente(){
        return siguiente;
		}
};




template <class T>

//Clase tipo LIFO: last in first out, llevamos cuenta del final
class Pila{
	private:
		Nodo<T> *inicio;
	public:
		Pila<T>(){
			inicio = nullptr;
		}

		~Pila<T>(){
			if (inicio != nullptr){
				delete inicio;
			}
		}

		void agregar(T valor){
			Nodo<T> *nuevo = new Nodo<T>(valor);
			Nodo<T> *temp = inicio;
			
			if (temp == nullptr){
				inicio = nuevo; //ORDEN IMPORTAAAA
				//cout << nuevo->obtenerValor();
			}
			else{
				inicio = nuevo;
				nuevo->establecerSiguiente(temp);
			}
		}

		void mostrar(){
			Nodo<T> *temp = inicio;
			while (temp != nullptr){
				cout << temp->obtenerValor() << "\n";
				temp = temp->obtenerSiguiente();
			}
		}

		void eliminar(){
			Nodo<T> *temp = inicio;
			Nodo<T> *nuevo_inicio = inicio->obtenerSiguiente();
			//cout << nuevo_inicio->obtenerValor() << inicio->obtenerValor();
			inicio = nuevo_inicio;
			//cout << nuevo_inicio->obtenerValor() << inicio->obtenerValor();
			temp->establecerSiguiente(nullptr);
			delete temp;			
		}

		bool buscar(T valor){
			Nodo<T> *temp = inicio;
			while(temp != nullptr){
				if(temp->obtenerValor() == valor){
					//cout << "Hola";
					return 1;
				}
				temp = temp->obtenerSiguiente();
			}
			return 0;
		}

		int longitud(){
			Nodo<T> *temp = inicio;
			int contador = 0;
			while (temp != nullptr){
				contador+=1;
				temp = temp->obtenerSiguiente();
			}
			return contador;
		}

		bool estaVacio(){
			if (longitud() == 0){
				return 1;
			}
			else{
				return 0;
			}
		}

		void reiniciar(){
			if (inicio == nullptr){
				return;
			}
			else{
        	    Nodo<T> *temp = inicio; //Se inicia un segundo puntero al inicio de la lista
				while (inicio != nullptr){ //Mientras que el inicio de la lista no apunte a null
        	        //inicio = inicio->obtenerSiguiente(); //El inicio se la lista pasa al nodo que le sigue
        	        //temp->establecerSiguiente(nullptr); //El primer nodo, pasa a apuntar a null
        	        //delete temp; //Se elimina el puntero
					eliminar();
				}
			}
		}
};

int main(){
	Pila<int> pila;
	//Nodo<int> nodo1(1);
	//cout << nodo1.obtenerValor();
	//cout << pila.longitud();
	pila.agregar(1);
	pila.agregar(2);
	pila.reiniciar();
	pila.agregar(3);
	//cout << "Hola";
	//cout << pila.buscar(3);
	//cout << pila.longitud();
	//pila.eliminar();
	//cout << pila.longitud();
	pila.mostrar();
	//pila.mostrar();
}