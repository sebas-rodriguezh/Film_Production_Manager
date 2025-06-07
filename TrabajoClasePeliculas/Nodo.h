#ifndef NODO_H
#define NODO_H
#include <iostream>
#include <sstream>
using namespace std;

template<class T>
class Nodo
{
private:
    T* dato;  // Puntero al dato
    Nodo<T>* siguiente;

public:
    // Constructor para el nodo, se espera un puntero a T
    Nodo(T* d) : dato(d), siguiente(nullptr) {}

    // Métodos getter y setter
    T* getDato() const { return dato; }
    Nodo<T>* getSiguiente() const { return siguiente; }

    void setDato(T* nuevoDato) { dato = nuevoDato; }
    void setSiguiente(Nodo<T>* siguiente) { this->siguiente = siguiente; }

    // Destructor, para eliminar el dato si es necesario
    ~Nodo() {
        //No lo borro, ya que es una relacion de agregacion. 
    }
};

#endif //NODO_H
