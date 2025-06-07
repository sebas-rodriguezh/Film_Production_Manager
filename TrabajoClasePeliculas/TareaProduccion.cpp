#include "TareaProduccion.h"
#include "Pelicula.h"

TareaProduccion::TareaProduccion(string idTarea, Pelicula* pelicula, const string& idDelResponsable, const string& descripcion, const bool& estado) :
    idTarea(idTarea), pelicula(pelicula), idDelResponsable(idDelResponsable), descripcion(descripcion), estado(estado) {
}

TareaProduccion::~TareaProduccion() {
}

Pelicula* TareaProduccion::getPelicula() {
    return pelicula;
}

string TareaProduccion::getIdDelResponsable() {
    return idDelResponsable;
}

string TareaProduccion::getDescripcion() {
    return descripcion;
}

bool TareaProduccion::getEstado() {
    return estado;
}

string TareaProduccion::getIdTarea() {
    return idTarea;
}


void TareaProduccion::setIdTarea(const string& idTarea) {
    this->idTarea = idTarea;
}


void TareaProduccion::setPelicula(Pelicula* pelicula) {
    this->pelicula = pelicula;
}

void TareaProduccion::setIdDelResponsable(const string& idDelResponsable) {
    this->idDelResponsable = idDelResponsable;
}

void TareaProduccion::setDescripcion(const string& descripcion) {
    this->descripcion = descripcion;
}

void TareaProduccion::setEstado(const bool& estado) {
    this->estado = estado;
}

bool TareaProduccion::encontroResponsable(string idDelResponsable)
{
    if (!pelicula) {
        return false;
    }
    Personal* responsableTarea = pelicula->getPersonalPorID(idDelResponsable);

    if (responsableTarea) {
        return true;
    }
    return false;
}

Personal* TareaProduccion::getResponsableDelLlamador() {
    return getResponsable(idDelResponsable);
}


Personal* TareaProduccion::getResponsable(string idDelResponsable) {
    if (!pelicula)
    {
        return nullptr;
    }

    Personal* responsableTarea = pelicula->getPersonalPorID(idDelResponsable);

    if (responsableTarea) {
        return responsableTarea;
    }
    else {
        throw runtime_error("El responsable con ID " + idDelResponsable + " no se encuentra en la pelicula.");
    }
}

string TareaProduccion::completarTarea()
{
    //La idea aca es que se puedan llamar las strategias de las personas que trabajan en la pelicula.
    stringstream s;

    Personal* responsableTarea = getResponsable(idDelResponsable);

    if (!responsableTarea) {
        throw runtime_error("El responsable con ID " + idDelResponsable + " no se encuentra en la pelicula.");
    }
    estado = true;
    s << responsableTarea->finalizarLaTareaStrategy(this) << endl;

    return s.str();
}


string TareaProduccion::toString() const {
    stringstream s;
    s << "Tarea de Produccion: " << descripcion << endl;
    s << "ID de la tarea: " << idTarea << endl;
    s << "Pelicula: " << (pelicula ? pelicula->getTitulo() : "N/A") << endl;

    if (!estado) {
        s << "Estado: NO finalizado.  " << endl;
    }
    else {
        s << "Estado: Finalizado.  " << endl;
    }

    s << "ID del responsable: " << idDelResponsable << endl;
    return s.str();
}


void TareaProduccion::asignarleTareaAlResponsable(string idDelResponsable) {
    if (encontroResponsable(idDelResponsable)) {
        setIdDelResponsable(idDelResponsable);
        Personal* responsableTarea = getResponsable(idDelResponsable);
    }
    else {
        throw runtime_error("El responsable con ID " + idDelResponsable + " no se encuentra en la pelicula.");
    }
}


