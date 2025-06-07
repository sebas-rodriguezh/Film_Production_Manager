#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include "EstrategiaTrabajo.h"
using namespace std;


class Personal
{
protected:
	string nombre;
	string id;
	string email;
	string especialidad;
	EstrategiaTrabajo* estrategiaTrabajo; // Puntero a la estrategia de trabajo 
public:
	Personal(const string& nombre = "", const string& id = "", const string& email = "", const string& especialidad = "");
	virtual ~Personal();
	virtual string mostrarPerfil() const = 0;
	virtual string finalizarLaTareaStrategy(TareaProduccion* tareaQueCompleto) = 0;


	// Getters
	string getNombre() const;
	string getId() const;
	string getEmail() const;
	string getEspecialidad() const;

	// Setters
	void setNombre(const string& nombre);
	void setId(const string& id);
	void setEmail(const string& email);
	void setEspecialidad(const string& especialidad);

	friend ostream& operator<<(ostream& os, const Personal& personal) {
		os << personal.mostrarPerfil();
		return os;
	}
};