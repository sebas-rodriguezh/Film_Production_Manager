#pragma once

#include <string>
#include "GestorRecursos.h"
#include "Personal.h" 
#include "TareaProduccion.h"

using namespace std;

class Pelicula
{
private:
    string titulo;
    string id;
    GestorRecursos<Personal>* personal;
    GestorRecursos<TareaProduccion>* tareas; //Esta seria como para que cada peli tiene sus tareas de produccion, pero no lo implementamos por ahora

public:
    Pelicula(string titulo = "", string id = "");
    ~Pelicula();

    void agregarPersonal(Personal* p);
    void eliminarPersonal(Personal* p);
    string mostrarPersonal();
    string mostrarPelicula();

    string getTitulo();
    string getId();
    void setTitulo(string titulo);
    void setId(string id);

    GestorRecursos<Personal>* getPersonal();
    Personal* getPersonalPorID(string id);

    //Cambios para asignaciones de tareas. 

    void agregarTarea(TareaProduccion* tarea);
    void eliminarTarea(TareaProduccion* tarea);
    string mostrarTareas();
    string mostrarTareasDeUnPersonal(string idPersonal);
    TareaProduccion* getTareaPorIDTarea(string idTarea);

    GestorRecursos<TareaProduccion>* getTareas();
    string mostrarPeliculasSimplificado();
    string mostrarTareasPendientes();

};
