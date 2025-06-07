#include "Studio.h"

Studio::Studio() :
	peliculas(new ListaPeliculas()), personal(new ListaPersonal())
{

}

Studio::~Studio() {
	if (peliculas) {
		delete peliculas;
	}

	if (personal) {
		delete personal;
	}
}

bool Studio::registrarPelicula(Pelicula* peli) {
	return peliculas->insertarPelicula(peli);
}
bool Studio::registrarPersonal(Personal* person) {
	return personal->insertarPersonal(person);
}

Pelicula* Studio::getPeliculaPorID(string id) {
	return peliculas->getPeliculaPorID(id);
}
Personal* Studio::getPersonalPorID(string id) {
	return personal->getPersonalPorID(id);
}

string Studio::listadoPeliculas() {
	return peliculas->mostrarTodasLasPeliculas();
}

string Studio::listadoPersonal() {
	return personal->mostrarTodoElPersonal();
}

ListaPeliculas* Studio::getPeliculas() {
	return peliculas;
}

ListaPersonal* Studio::getPersonal() {
	return personal;
}

void Studio::setPeliculas(ListaPeliculas* peliculas) {
	this->peliculas = peliculas;
}

void Studio::setPersonal(ListaPersonal* personal) {
	this->personal = personal;
}
