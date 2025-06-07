#pragma once
#include "ListaPeliculas.h"
#include "ListaPersonal.h"

class Studio
{
private:
	ListaPeliculas* peliculas;
	ListaPersonal* personal;

public:
	Studio();
	virtual ~Studio();

	bool registrarPelicula(Pelicula* peli);
	bool registrarPersonal(Personal* person);

	Pelicula* getPeliculaPorID(string id);
	Personal* getPersonalPorID(string id);

	string listadoPeliculas();
	string listadoPersonal();

	ListaPeliculas* getPeliculas();
	ListaPersonal* getPersonal();

	void setPeliculas(ListaPeliculas* peliculas);
	void setPersonal(ListaPersonal* personal);
};

