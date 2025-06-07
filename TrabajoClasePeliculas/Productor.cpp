#include "Productor.h"

Productor::Productor(string nombre, string id, string email, string especialidad, double presupuest, string cronograma)
	: Personal(nombre, id, email, especialidad), presupuesto(presupuest), cronograma(cronograma)
{
	estrategiaTrabajo = new EstrategiaProductor();
}

Productor::~Productor()
{

}

double Productor::getPresupuesto()
{
	return presupuesto;
}

void Productor::setPresupuesto(double presupuesto)
{
	this->presupuesto = presupuesto;
}

string Productor::getCronograma()
{
	return cronograma;
}

void Productor::setCronograma(string cronograma)
{
	this->cronograma = cronograma;
}

string Productor::mostrarPerfil() const {
	stringstream s;
	s << "Perfil del Productor:" << endl;
	s << "	Nombre: " << getNombre() << endl;
	s << "	ID: " << getId() << endl;
	s << "	Email: " << getEmail() << endl;
	s << "	Presupuesto: " << presupuesto << endl;
	s << "	Herramientas de Dibujo: " << cronograma << endl;
	return s.str();
}


string Productor::finalizarLaTareaStrategy(TareaProduccion* tareaQueCompleto) {
	return estrategiaTrabajo->realizarTarea(tareaQueCompleto);
}
