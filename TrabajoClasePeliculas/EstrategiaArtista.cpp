#include "EstrategiaArtista.h"


EstrategiaArtista::EstrategiaArtista() :
	EstrategiaTrabajo()
{

}

EstrategiaArtista::~EstrategiaArtista()
{

}

string EstrategiaArtista::realizarTarea(TareaProduccion* tareaQueCompleto) {
	stringstream s;
	Personal* artistaQueLoHizo = tareaQueCompleto->getResponsableDelLlamador();

	if (Artista* aux = dynamic_cast<Artista*> (artistaQueLoHizo))
	{
		s << "El artista ha completado la tarea: " << tareaQueCompleto->getDescripcion() << endl;
		s << "Nombre del artista: " << aux->getNombre() << endl;
		s << "ID del artista: " << aux->getId() << endl;
		s << "Ha usado sus herramientas de dibujo como estrategia de trabajo: " << aux->getHerramientasDeDibujo() << endl;
	}
	return s.str();
}

