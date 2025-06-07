#pragma once
#include "Personal.h"
#include "EstrategiaArtista.h"

class Artista : public Personal
{
private:
	string herramientasDeDibujo; //Esas herramientas pueden ser diferentes. 

public:
	Artista(string nombre = "", string id = "", string email = "", string especialidad = "", string herramientas = "");
	virtual ~Artista();
	void setHerramientasDeDibujo(string herramientas);
	string getHerramientasDeDibujo() const;
	string mostrarPerfil() const override;
	string finalizarLaTareaStrategy(TareaProduccion* tareaQueCompleto) override;

};

