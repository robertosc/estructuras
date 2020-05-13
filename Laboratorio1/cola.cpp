#include<iostream>
//#include "listas.h"
using namespace std;

template <class T>
// T es el parámetro de tipo. Dentro de la definición de la clase,
// T funciona como un tipo (como int, o char).
class Nodo
{
private:
    T valor;
    Nodo<T> *siguiente; // Nótese que el puntero es a un nodo del mismo tipo.
public:
    Nodo<T>(T valor)
    {
        this->siguiente = nullptr;
        this->valor = valor;
    }

    ~Nodo<T>(){ //Destructor
        if (siguiente != nullptr){
            delete siguiente;
        }
    }

    void establecerSiguiente(Nodo<T> *nodo){
        siguiente = nodo;
    }

    Nodo<T> *obtenerSiguiente(){
        return siguiente;
    }

    T obtenerValor(){
        return valor;
    }
};


template <class T>
class Cola{
private:
	Nodo<T> *inicio;
	Nodo<T> *final;
public:
	Cola<T> (){
		inicio = nullptr;
		final = nullptr;

	}
	~Cola<T> (){
		if (inicio == nullptr){
			delete inicio;
			delete final;
		}
	}

	void agregar(T valor){
		Nodo<T> *nuevo = new Nodo<T>(valor);
		if (inicio == nullptr){

			inicio = nuevo;
			final = nuevo;
			//cout << final->obtenerValor();
		}
		else{
			final->establecerSiguiente(nuevo); //incialmente final es el anterior al nuevo
			final = nuevo; //Queremos que final, guardado en temp, apunte al nuevo
			//cout << final->obtenerValor();
		}
	}

	void mostrar(){
		Nodo<T> *temp = inicio;
		//cout << temp;
		while (temp != nullptr){
			//cout << "Hola";
			cout << temp->obtenerValor() << "\n";
			temp = temp->obtenerSiguiente();
		}
	}

	void eliminar(){
		if (inicio == nullptr){
			return;
		}
		else if(inicio == final){
			//cout << "Hola";
			Nodo<T> *tmp_i = inicio;
			Nodo<T> *tmp_f = final;
			inicio = nullptr;
			final = nullptr;
		}
		else{
			Nodo<T> *tmp = inicio;
			inicio = inicio->obtenerSiguiente();
			tmp->establecerSiguiente(nullptr);
			delete tmp;
			return;
		}
	}

	int longitud(){
		Nodo<T> *tmp = inicio;
		int contador = 0;
		if (tmp == nullptr){
			return 0;
		}
		while (tmp != nullptr){
			contador +=1;
			tmp = tmp->obtenerSiguiente();
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
		int i = 0;
		//Nodo<T> *tmp = inicio;
		if (estaVacio()){
			//cout << "Hola";
			return;
		}
		else{
			for (i = 0; i<=longitud()+1; i++){
				//cout << "Hola";
				eliminar();
			}
		}
	}


};

int main(){
	Cola<int> cola;
	cola.agregar(2);
	cola.agregar(3);
	cola.agregar(1);
	//cola.eliminar();
	cola.reiniciar();
	cola.agregar(10);
	cola.mostrar();
	//cout << cola.longitud();
}