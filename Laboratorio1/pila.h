//template <class T>
//class Nodo
//{
//private:
//    T valor;
//    Nodo<T> *siguiente; // Nótese que el puntero es a un nodo del mismo tipo.
//public:
//    Nodo<T>(T);
//
//    ~Nodo<T>();
//
//    void establecerSiguiente(Nodo<T> *);
//
//    Nodo<T> *obtenerSiguiente();
//
//	T obtenerValor();
//};

template <class T>
class Pila{
	private:
		Nodo<T> *inicio;
	public:
		Pila<T> ();

		~Pila<T> ();

		void agregar(T valor);

		void mostrar();

		void eliminar();

		bool buscar();

		int longitud();

		bool estaVacio();

		void reiniciar();
};

namespace pila
{
void main();
}