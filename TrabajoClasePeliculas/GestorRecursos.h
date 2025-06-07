#pragma once

#include "Nodo.h"
#include <sstream>
#include <iostream>
using namespace std;

template <class T>
class GestorRecursos
{
private:
    Nodo<T>* cabeza;

public:
    // Constructor
    GestorRecursos() : cabeza(nullptr) {}

    // Destructor
    ~GestorRecursos() {
        Nodo<T>* actual = cabeza;
        while (actual != nullptr) {
            Nodo<T>* siguiente = actual->getSiguiente();
            delete actual;  // El destructor de Nodo manejará la eliminación del dato
            actual = siguiente;
        }
    }

    // Agregar un nuevo dato
    void agregar(T* dato) {
        Nodo<T>* nuevoNodo = new Nodo<T>(dato);
        nuevoNodo->setSiguiente(cabeza); // El siguiente del nuevo nodo será la cabeza actual
        cabeza = nuevoNodo;  // La cabeza ahora será el nuevo nodo
    }

    // Mostrar la GestorRecursos como un string
    string mostrar() const {
        stringstream ss;
        Nodo<T>* actual = cabeza;
        while (actual != nullptr) {
            ss << *actual->getDato() << endl;  // Desreferenciamos el puntero a T
            actual = actual->getSiguiente();
        }
        return ss.str();
    }

    // Sobrecarga del operador <<
    friend ostream& operator<<(ostream& os, const GestorRecursos<T>& GestorRecursos) {
        Nodo<T>* actual = GestorRecursos.cabeza;
        while (actual != nullptr) {
            os << *actual->getDato() << endl;  // Imprimimos el valor del dato
            actual = actual->getSiguiente();
        }
        return os;
    }

    bool buscar(T* dato) const {
        Nodo<T>* actual = cabeza;
        while (actual != nullptr) {
            if (actual->getDato() == dato) {
                return true;
            }
            actual = actual->getSiguiente();
        }
        return false;
    }

    // Obtener el tamaño de la GestorRecursos
    int tamanio() const {
        int tam = 0;
        Nodo<T>* actual = cabeza;
        while (actual != nullptr) {
            tam++;
            actual = actual->getSiguiente();
        }
        return tam;
    }

    Nodo<T>* getCabeza() {
        return this->cabeza;
    }


    void eliminar(T* dato) {
        Nodo<T>* actual = cabeza;
        Nodo<T>* anterior = nullptr;

        while (actual != nullptr) {
            if (actual->getDato() == dato) {
                if (anterior == nullptr) {
                    cabeza = actual->getSiguiente();
                }
                else {
                    anterior->setSiguiente(actual->getSiguiente());
                }
                delete actual;
                return;
            }
            anterior = actual;
            actual = actual->getSiguiente();
        }
    }

    bool estaVacia() const {
        return cabeza == nullptr;
    }
};