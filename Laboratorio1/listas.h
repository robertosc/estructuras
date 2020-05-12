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
class Lista
{
private:
    Nodo<T> *inicial;

public:
    Lista<T>();

    ~Lista<T>();

    bool buscar(T);

    void agregar(T);

    void eliminar(T);

    int longitud();

    bool estaVacio();

    void reiniciar();

    void mostrar();
};

namespace listas
{
void main();
}
