#pragma once
#include "Personal.h"
#include "GestorRecursos.h"

class ListaPersonal
{
private:
	GestorRecursos<Personal>* personalLista;
public:
	ListaPersonal();
	virtual ~ListaPersonal();
	void setListaPersonal(GestorRecursos<Personal>* personal);
	GestorRecursos<Personal>* getPtrPersonal();

	Personal* getPersonalPorID(string idPersona);
	bool insertarPersonal(Personal* personaInset);
	void eliminarPersonal(Personal* personaElim);
	string mostrarTodoElPersonal();
	string mostrarPersonalPorID(string idPer);
	bool existePersonalConEseID(string id);
};

