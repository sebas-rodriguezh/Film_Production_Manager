#include "ListaPeliculas.h"


ListaPeliculas::ListaPeliculas() :
    peliculas(new GestorRecursos<Pelicula>())
{

}
ListaPeliculas::~ListaPeliculas() {
    Nodo<Pelicula>* actual = peliculas->getCabeza();
    while (actual != nullptr) {
        Nodo<Pelicula>* siguiente = actual->getSiguiente();
        delete actual->getDato();
        delete actual;
        actual = siguiente;
    }
    delete peliculas;
}

void ListaPeliculas::setListaPeliculas(GestorRecursos<Pelicula>* pelis) {
    peliculas = pelis;
}

GestorRecursos<Pelicula>* ListaPeliculas::getPeliculas() {
    return peliculas;
}

Pelicula* ListaPeliculas::getPeliculaPorID(string idPeli) {
    Nodo<Pelicula>* current = peliculas->getCabeza();

    while (current != nullptr) {
        if (current->getDato()->getId() == idPeli) {
            return current->getDato();
        }
        current = current->getSiguiente();
    }
    return nullptr;
}

bool ListaPeliculas::insertarPelicula(Pelicula* peliInsertar) {
    //Para insertar una pelicula, la pelicula debe de tener insertados ya los empleados. 

    if (!existePeliculaConEseID(peliInsertar->getId()))
    {
        peliculas->agregar(peliInsertar);
        return true; // Si se pudo insertar, retornar true
    }

    return false; // Si no se pudo insertar, retornar false 
}

void ListaPeliculas::eliminarPelicula(Pelicula* peliEliminar)
{
    peliculas->eliminar(peliEliminar);
}

string ListaPeliculas::mostrarTodasLasPeliculas()
{
    stringstream s;
    Nodo<Pelicula>* current = peliculas->getCabeza();
    while (current) {
        s << current->getDato()->mostrarPelicula() << endl;
        current = current->getSiguiente();
    }
    return s.str();
}


string ListaPeliculas::mostrarPeliculaPorID(string idPeli) {
    stringstream s;
    Nodo<Pelicula>* current = peliculas->getCabeza();

    while (current)
    {
        if (current->getDato()->getId() == idPeli)
        {
            s << current->getDato()->mostrarPelicula() << endl;
        }
        current = current->getSiguiente();
    }
    return s.str();
}

bool ListaPeliculas::existePeliculaConEseID(string id) {

    Nodo<Pelicula>* current = peliculas->getCabeza();

    while (current != nullptr) {
        if (current->getDato()->getId() == id) {
            return true;
        }
        current = current->getSiguiente();
    }
    return false;
}


string ListaPeliculas::mostrarPeliculasQueTienesPersonalAsignado()
{
    stringstream s;
    Nodo<Pelicula>* current = peliculas->getCabeza();

    while (current != nullptr) {
        if (!current->getDato()->getPersonal()->estaVacia()) {
            s << current->getDato()->mostrarPelicula() << endl;
        }
        current = current->getSiguiente();
    }
    return s.str();
}

string ListaPeliculas::mostrarPeliculasConTareasAsignadas() {
    stringstream s;
    Nodo<Pelicula>* current = peliculas->getCabeza();

    while (current != nullptr) {
        if (!current->getDato()->getPersonal()->estaVacia() && !(current->getDato()->getTareas()->estaVacia()))
        {
            s << current->getDato()->mostrarPeliculasSimplificado() << endl;
        }
        current = current->getSiguiente();
    }
    return s.str();
}



//PENDING
//string ListaPeliculas::mostrarPersonalAsignadoAPelicula(string idPelicula) {
//    stringstream s;
//    Nodo<Pelicula>* current = peliculas->getCabeza();
//
//    while (current != nullptr) {
//        if (!current->getDato()->getPersonal()->estaVacia()) {
//            s << current->getDato()->mostrarPelicula() << endl;
//        }
//        current = current->getSiguiente();
//    }
//    return s.str();
//}

