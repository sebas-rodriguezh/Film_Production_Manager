#include "ListaPersonal.h"

ListaPersonal::ListaPersonal() :
    personalLista(new GestorRecursos<Personal>())
{
}

ListaPersonal::~ListaPersonal() {
    Nodo<Personal>* actual = personalLista->getCabeza();
    while (actual != nullptr) {
        Nodo<Personal>* siguiente = actual->getSiguiente();
        delete actual->getDato();
        delete actual;
        actual = siguiente;
    }
    delete personalLista;
}


void ListaPersonal::setListaPersonal(GestorRecursos<Personal>* personal) {
    this->personalLista = personal;
}

GestorRecursos<Personal>* ListaPersonal::getPtrPersonal() {
    return personalLista;
}

Personal* ListaPersonal::getPersonalPorID(string idPersona)
{
    Nodo<Personal>* current = personalLista->getCabeza();

    while (current != nullptr) {
        if (current->getDato()->getId() == idPersona) {
            return current->getDato();
        }
        current = current->getSiguiente();
    }
    return nullptr;
}

bool ListaPersonal::insertarPersonal(Personal* personaInset) {
    if (existePersonalConEseID(personaInset->getId())) {
        return false;
    }
    personalLista->agregar(personaInset);
    return true;
}
void ListaPersonal::eliminarPersonal(Personal* personaElim) {
    personalLista->eliminar(personaElim);
}

string ListaPersonal::mostrarTodoElPersonal() {
    stringstream s;
    Nodo<Personal>* current = personalLista->getCabeza();

    while (current != nullptr)
    {
        s << current->getDato()->mostrarPerfil() << endl;
        current = current->getSiguiente();
    }
    return s.str();
}


string ListaPersonal::mostrarPersonalPorID(string idPer)
{
    stringstream s;
    Nodo<Personal>* current = personalLista->getCabeza();

    while (current != nullptr) {
        if (current->getDato()->getId() == idPer) {
            s << current->getDato()->mostrarPerfil() << endl;
        }
        current = current->getSiguiente();
    }
    return s.str();
}

bool ListaPersonal::existePersonalConEseID(string id) {
    Nodo<Personal>* current = personalLista->getCabeza();

    while (current != nullptr) {
        if (current->getDato()->getId() == id) {
            return true;
        }
        current = current->getSiguiente();
    }
    return false;
}