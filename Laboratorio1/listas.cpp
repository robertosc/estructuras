#include <iostream>
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
class Lista
{
private:
    Nodo<T> *inicial; // Nótese que el puntero es a un nodo del mismo tipo.
public:
    Lista<T>(){
        inicial = nullptr;
    }

    ~Lista<T>(){
        if (inicial != nullptr){
            delete inicial;
        }
    }

    bool buscar(T valor){
        Nodo<T> *actual = inicial;
        while (actual != nullptr){
            if (actual->obtenerValor() == valor){
                return true;
            }
            actual = actual->obtenerSiguiente();
        }
        return false;
    }

    void agregar(T valor){
        Nodo<T> *nuevo = new Nodo<T>(valor);
        Nodo<T> *actual = inicial;
        if (actual == nullptr){
            inicial = nuevo;
            //cout << inicial->obtenerValor();
        }
        else{
            while (actual->obtenerSiguiente() != nullptr){
                actual = actual->obtenerSiguiente();
            }
            actual->establecerSiguiente(nuevo);
        }
    }

    void eliminar(T valor){
        if (inicial == nullptr){
            return;
        }
        if (inicial->obtenerValor() == valor){
            Nodo<T> *temp = inicial;
            inicial = inicial->obtenerSiguiente();
            temp->establecerSiguiente(nullptr);
            delete temp;
            return;
        }

        Nodo<T> *anterior = inicial;
        Nodo<T> *actual = inicial->obtenerSiguiente();
        while (actual != nullptr){
            if (actual->obtenerValor() == valor){
                anterior->establecerSiguiente(actual->obtenerSiguiente());
                actual->establecerSiguiente(nullptr);
                delete actual;
                return;
            }
            else{
                anterior = actual;
                actual = actual->obtenerSiguiente();
            }
        }
    }

    int longitud(){
        if (inicial == nullptr){ //OK
            return 0;
        }
        else{
            int contador = 1;
            Nodo<T> *actual = inicial->obtenerSiguiente();
            while(actual != nullptr){
                actual = actual->obtenerSiguiente(); //Se apunta el puntero actual a el siguiente de actual
                contador +=1;
            }
            return contador;
        }
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
        if (inicial == nullptr){
				return;
		}
        else{
            while (inicial != nullptr){
                Nodo<T> *temp = inicial; //¿Xq fuera del while no sirve??
                Nodo<T> *nuevo_inicio = inicial->obtenerSiguiente(); //cout << nuevo_inicio->obtenerValor() << inicio->obtenerValor();
			    inicial = nuevo_inicio; //cout << nuevo_inicio->obtenerValor() << inicio->obtenerValor();
			    temp->establecerSiguiente(nullptr);
			    delete temp;
            }
        }
    }

    void mostrar(){
		Nodo<T> *temp = inicial;
		while (temp != nullptr){
			cout << temp->obtenerValor() << "\n";
			temp = temp->obtenerSiguiente();
		}
	}
};

namespace listas{
void main(){
    Lista<int> lista;
    cout << "Listas1:\n";
    lista.agregar(0);
    lista.agregar(1);
    lista.agregar(2);
    lista.agregar(3);
    lista.mostrar();
    lista.eliminar(2);
    cout << "Listas2:\n";
    lista.agregar(4);
    lista.mostrar();
    //cout << lista.buscar(2) << "\n"; // Imprime 1
    //cout << lista.buscar(5) << "\n"; // Imprime 0
    //cout << lista.estaVacio() << "\n";
    //lista.eliminar(2);
    //cout << lista.buscar(2) << "\n"; // Imprime 0
    lista.reiniciar();
    cout << "Listas2:\n";
    lista.agregar(1);
    lista.mostrar();

    lista.reiniciar();
} // namespace listas
}
