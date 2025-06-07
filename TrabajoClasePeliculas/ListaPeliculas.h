#pragma once
#include "Pelicula.h"

class ListaPeliculas
{
private:
	GestorRecursos<Pelicula>* peliculas;
public:
	ListaPeliculas();
	virtual ~ListaPeliculas();
	void setListaPeliculas(GestorRecursos<Pelicula>* pelis);
	GestorRecursos<Pelicula>* getPeliculas();

	Pelicula* getPeliculaPorID(string idPeli);
	bool insertarPelicula(Pelicula* peliInsertar);
	void eliminarPelicula(Pelicula* peliEliminar);
	string mostrarTodasLasPeliculas();
	string mostrarPeliculaPorID(string idPeli);
	bool existePeliculaConEseID(string id);
	string mostrarPeliculasQueTienesPersonalAsignado();
	//string mostrarPersonalAsignadoAPelicula(string idPelicula); 
	string mostrarPeliculasConTareasAsignadas();
};

