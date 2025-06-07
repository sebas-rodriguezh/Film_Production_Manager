#pragma once
#include "Personal.h"
#include "EstrategiaSonido.h"

class IngenieroSonido : public Personal
{
private:
	int anniosExperiencia;
	string experienciaEnMezcla;

public:
	IngenieroSonido(string nombre = "", string id = "", string email = "", string especialidad = "", int annniosExp = 0, string expEnMezcla = "");

	virtual ~IngenieroSonido();

	void setAnniosExperiencia(int anniosExp);
	void setExperienciaEnMezcla(string expEnMezcla);

	string getExperienciaEnMezcla();
	int getAnniosExperiencia();

	string mostrarPerfil() const override;
	string finalizarLaTareaStrategy(TareaProduccion* tareaQueCompleto) override;

};

