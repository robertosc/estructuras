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
		Nodo<T> *start = inicio;
		Nodo<T> *temp = final; //Debemos llevar cuenta del final, el incio se mantiene
		if (start == nullptr){

			inicio = nuevo;
			final = nuevo;
			//cout << final->obtenerValor();
		}
		else{
			//cout << "Hola";
			final->establecerSiguiente(nuevo); //incialmente final es el anterior al nuevo
			temp = nuevo; //Queremos que final, guardado en temp, apunte al nuevo
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
};

int main(){
	Cola<int> cola;
	cola.agregar(1);
	cola.agregar(2);
	cola.agregar(3);
	cola.mostrar();
}