#include "EstrategiaProductor.h"

EstrategiaProductor::EstrategiaProductor() :
	EstrategiaTrabajo()
{
}

EstrategiaProductor::~EstrategiaProductor()
{
}


string EstrategiaProductor::realizarTarea(TareaProduccion* tareaQueCompleto)
{
	stringstream s;
	Personal* ProductorQueLoHizo = tareaQueCompleto->getResponsableDelLlamador();

	if (Productor* aux = dynamic_cast<Productor*> (ProductorQueLoHizo))
	{
		s << "El Productor ha completado la tarea: " << tareaQueCompleto->getDescripcion() << endl;
		s << "Nombre del Productor: " << aux->getNombre() << endl;
		s << "ID del Productor: " << aux->getId() << endl;
		s << "Ha utilizado un presupuesto de: " << aux->getPresupuesto() << " con la finalidad de terminar su tarea. " << endl;
		s << "Ha trabajado en un lapso de cronograma de: " << aux->getCronograma() << " dias. " << endl;
	}
	return s.str();
}