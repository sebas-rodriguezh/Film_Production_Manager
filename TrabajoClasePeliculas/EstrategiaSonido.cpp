#include "EstrategiaSonido.h"

EstrategiaSonido::EstrategiaSonido() :
	EstrategiaTrabajo()
{

}

EstrategiaSonido::~EstrategiaSonido() {

}

string EstrategiaSonido::realizarTarea(TareaProduccion* tareaQueCompleto) {
	stringstream s;

	Personal* IngenieroSonidoQueLoHizo = tareaQueCompleto->getResponsableDelLlamador();

	if (IngenieroSonido* aux = dynamic_cast<IngenieroSonido*> (IngenieroSonidoQueLoHizo))
	{
		s << "El Ing. Sonido ha completado la tarea: " << tareaQueCompleto->getDescripcion() << endl;
		s << "Nombre del Ing. Sonido: " << aux->getNombre() << endl;
		s << "ID del Ing. Sonido: " << aux->getId() << endl;
		s << "El ha utilizado sus " << aux->getAnniosExperiencia() << " annios de experiencia en mezcla de sonido: " << aux->getExperienciaEnMezcla() << " para completar su tarea. " << endl;
	}


	return s.str();
}
