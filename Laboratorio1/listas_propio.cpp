#include<iostream>
#include<cstdio>
#include<string>


using namespace std;

template <class T>

class Node{
	private:
		T value;
		Node<T> *next; //Debemos definir un puntero que permita apuntar al siguiente nodo
	public:
		Node<T> (T value){
			this->value = value;
			this->next = nullptr;
		}
		
		void setNext(Node<T> *node){
			next = node;
		}

		Node<T> *getNext(Node<T> *node){
			return next;
		}

		T getValue(){
			return value;
		}
};

template <class T>
class List{
	private:
		Node<T> *start; //inicializamos el primer puntero

	public:
		List<T>(){
			start = nullptr; //apuntamos el inicio de la lista a vacio
		}

		void add(T value){
			
		}



}