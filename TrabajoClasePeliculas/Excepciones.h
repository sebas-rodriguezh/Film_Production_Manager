#pragma once
#include "ExcepcionStudio.h"
class Excepciones: public ExcepcionStudio
{
public:

	string mensaje() const override {
		return "ERROR: Excepcion en el programa";
	}
};


class ExcepcionEntradaInvalida: public ExcepcionStudio {
public:
	string mensaje() const override {
		return "ERROR:Entrada invalida, intente de nuevo: ";
	}

};

class IdReptido : public ExcepcionStudio {
public:
	string mensaje() const override {
		return "ERROR:No se ingreso al sistema, ID repetido. ";
	}

};

class OpcionMenuInvalida : public ExcepcionStudio {
public:
	string mensaje() const override {
		return "ERROR:OpcionMenu invalida, intente de nuevo.";
	}

};

class NoHayPersonalParaLaPeli : public ExcepcionStudio {
public:
	string mensaje() const override {
		return  "ERROR: No hay ninguna pelicula con personal asignado. ";
	}

};

class NoHayPeliculaConPersonal : public ExcepcionStudio {
public:
	string mensaje() const override {
		return "ERROR: No hay personal que pueda trabajar en la pelicula. ";
	}

};

class PeliculaSinId : public ExcepcionStudio {
public: 
	string mensaje() const override {
		return "ERROR: No existe ninguna pelicula con ese ID.";
	}

};

class NoExistePersonalConEseId : public ExcepcionStudio {
public:
	string mensaje() const override {
		return "ERROR: No existe personal con ese ID.";
	}

};


class SinDatosParaRegistroTarea : public ExcepcionStudio
{
public:

	string mensaje() const override {
		return "ERROR: No hay suficientes datos para registrar una tarea. ";
	}
};

class NoHayPeliConTareaPendiente : public ExcepcionStudio
{
public:

	string mensaje() const override {
		return "ERROR: No hay peliculas que tengan tareas pendientes. ";
	}
};

class NoSeEncontroLaTareaConEseId : public ExcepcionStudio
{
public:

	string mensaje() const override { 
		return "ERROR:No se encontro la tarea con el ID: "; 
	}
};

