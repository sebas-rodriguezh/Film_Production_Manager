#pragma once
#include "EstrategiaTrabajo.h"
#include "TareaProduccion.h"
#include "Artista.h"

class EstrategiaArtista : public EstrategiaTrabajo
{
public:
	EstrategiaArtista();
	virtual ~EstrategiaArtista();
	string realizarTarea(TareaProduccion* tareaQueCompleto) override;
};

