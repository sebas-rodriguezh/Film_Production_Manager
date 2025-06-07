#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include "Personal.h"
using namespace std;

class Pelicula;

class TareaProduccion
{
private:
	string idTarea;
	Pelicula* pelicula;
	string idDelResponsable; //Este ID lo tiene pelicula adentro de ella, ya que la peli debe de buscar al responsable. 
	string descripcion;
	bool estado; // En Proceso, Completada

public:
	TareaProduccion(string idTarea = "", Pelicula* pelicula = nullptr, const string& idDelResponsable = "", const string& descripcion = "", const bool& estado = false);
	virtual ~TareaProduccion();
	Pelicula* getPelicula();
	string getIdDelResponsable();
	string getDescripcion();
	bool getEstado();
	string getIdTarea();


	void setIdTarea(const string& idTarea);
	void setPelicula(Pelicula* pelicula);
	void setIdDelResponsable(const string& idDelResponsable);
	void setDescripcion(const string& descripcion);
	void setEstado(const bool& estado);

	bool encontroResponsable(string idDelResponsable);
	void asignarleTareaAlResponsable(string idDelResponsable);
	Personal* getResponsable(string idDelResponsable);
	Personal* getResponsableDelLlamador();
	string toString() const;

	string completarTarea();

	friend ostream& operator<<(ostream& os, const TareaProduccion& tarea) {
		os << tarea.toString();
		return os;
	}


};

