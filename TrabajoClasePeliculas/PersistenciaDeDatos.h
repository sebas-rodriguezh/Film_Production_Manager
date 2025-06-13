#pragma once
#include "Studio.h"
#include "GestorRecursos.h"
#include <fstream> 
#include "IngenieroSonido.h"
#include "Artista.h"

class PersistenciaDeDatos
{

public:

     void guardarPersonal(ListaPersonal* personal);
     ListaPersonal* cargarPersonal();

     void guardarPeliculas(ListaPeliculas* peliculas);
     ListaPeliculas* cargarPeliculas();

     void guardarTareas(ListaPeliculas* peliculas);
     void cargarTareas(ListaPeliculas* peliculas);
     void guardarPersonalPorPelicula(ListaPeliculas* peliculas);
     void cargarPersonalPorPelicula(ListaPeliculas* peliculas, ListaPersonal* personal);
};



