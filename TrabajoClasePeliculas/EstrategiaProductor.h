#pragma once
#include "EstrategiaTrabajo.h"
#include "TareaProduccion.h"
#include "Productor.h"

class EstrategiaProductor : public EstrategiaTrabajo
{
public:
	EstrategiaProductor();
	virtual ~EstrategiaProductor();
	string realizarTarea(TareaProduccion* tareaQueCompleto) override;
};