#pragma once
#include "Personal.h"
#include "EstrategiaProductor.h"

class Productor : public Personal
{
private:
	double presupuesto;
	string cronograma;
public:
	Productor(string nombre = "", string id = "", string email = "", string especialidad = "", double presupuest = 0.0, string cronograma = "");
	virtual ~Productor();

	double getPresupuesto();
	void setPresupuesto(double presupuesto);


	string getCronograma();
	void setCronograma(string cronograma);

	string mostrarPerfil() const override;
	string finalizarLaTareaStrategy(TareaProduccion* tareaQueCompleto) override;
};

