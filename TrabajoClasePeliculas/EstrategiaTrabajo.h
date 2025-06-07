#pragma once
#include <iostream>
#include <sstream>
using namespace std;

class TareaProduccion;

class EstrategiaTrabajo
{
public:
	virtual string realizarTarea(TareaProduccion* tareaQueCompleto) = 0;
	virtual ~EstrategiaTrabajo();
	EstrategiaTrabajo();
};

