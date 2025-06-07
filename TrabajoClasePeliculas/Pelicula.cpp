#include "Pelicula.h"
#include <sstream>

Pelicula::Pelicula(string titulo, string id) : titulo(titulo), id(id), personal(new GestorRecursos<Personal>()), tareas(new GestorRecursos<TareaProduccion>())
{
}


Pelicula::~Pelicula() {

}

void Pelicula::agregarPersonal(Personal* p) {
    personal->agregar(p);
}

void Pelicula::eliminarPersonal(Personal* p) {
    personal->eliminar(p); //Lo borramos de la lista, pero no lo destruimos.
}

string Pelicula::mostrarPersonal() {
    return personal->mostrar();
}

string Pelicula::getTitulo() {
    return titulo;
}

string Pelicula::getId() {
    return id;
}

void Pelicula::setTitulo(string titulo) {
    this->titulo = titulo;
}

void Pelicula::setId(string id) {
    this->id = id;
}

string Pelicula::mostrarPelicula() {
    stringstream s;
    s << "Titulo: " << titulo << endl;
    s << "ID: " << id << endl;
    s << "Informacion del Personal: " << endl;
    s << mostrarPersonal() << endl;
    s << "Tareas pendientes registradas: " << endl;
    s << mostrarTareas() << endl;
    return s.str();
}

string Pelicula::mostrarPeliculasSimplificado() {
    stringstream s;
    s << "Titulo: " << titulo << endl;
    s << "ID: " << id << endl;
    s << "Tareas pendientes registradas: " << endl;
    s << mostrarTareas() << endl;
    return s.str();
}

string Pelicula::mostrarTareasPendientes() {
    stringstream s;
    s << "Tareas pendientes registradas: " << endl;
    s << mostrarTareas() << endl;
    return s.str();
}






GestorRecursos<Personal>* Pelicula::getPersonal() {
    return personal;
}

Personal* Pelicula::getPersonalPorID(string id) {
    Nodo<Personal>* current = personal->getCabeza();

    while (current != nullptr) {
        if (current->getDato()->getId() == id)
        {
            return current->getDato();
        }
        current = current->getSiguiente();
    }

    return nullptr;
}

void Pelicula::agregarTarea(TareaProduccion* tarea) {
    tareas->agregar(tarea);
}


void Pelicula::eliminarTarea(TareaProduccion* tarea) {
    string idResponsable = tarea->getIdDelResponsable();
    Personal* responsable = tarea->getResponsable(idResponsable);


    int contador = 0;
    Nodo<TareaProduccion>* actual = tareas->getCabeza();
    while (actual != nullptr) {
        if (actual->getDato()->getIdDelResponsable() == idResponsable) {
            contador++;
        }
        actual = actual->getSiguiente();
    }


    if (contador == 1 && responsable != nullptr) {
        personal->eliminar(responsable);
    }

    tareas->eliminar(tarea);
}




string Pelicula::mostrarTareas() {
    return tareas->mostrar();
}
GestorRecursos<TareaProduccion>* Pelicula::getTareas() {
    return tareas;
}


string Pelicula::mostrarTareasDeUnPersonal(string idPersonal) {
    stringstream s;

    Nodo<TareaProduccion>* current = tareas->getCabeza();

    while (current != nullptr)
    {
        if (current->getDato()->getIdDelResponsable() == idPersonal)
        {
            s << *current->getDato() << endl;
        }
        current = current->getSiguiente();
    }
    return s.str();
}


TareaProduccion* Pelicula::getTareaPorIDTarea(string idTarea) {

    Nodo<TareaProduccion>* current = tareas->getCabeza();

    while (current != nullptr) {
        if (current->getDato()->getIdTarea() == idTarea)
        {
            return current->getDato();
        }
        current = current->getSiguiente();
    }

    return nullptr;
}



