template <class T>
class Nodo
{
private:
    T valor;
    Nodo<T> *siguiente; // Nótese que el puntero es a un nodo del mismo tipo.
public:
    Nodo<T>(T);

    ~Nodo<T>();

    void establecerSiguiente(Nodo<T> *);

    Nodo<T> *obtenerSiguiente();

	T obtenerValor();
};

template <class T>
class Pila{
	private:

	public:
};