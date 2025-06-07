#pragma once
#include "EstrategiaTrabajo.h"
#include "TareaProduccion.h"
#include "IngenieroSonido.h"

class EstrategiaSonido : public EstrategiaTrabajo
{
public:
	EstrategiaSonido();
	virtual ~EstrategiaSonido();
	string realizarTarea(TareaProduccion* tareaQueCompleto) override;
};




