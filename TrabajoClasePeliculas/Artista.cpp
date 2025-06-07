#include "Artista.h"


Artista::Artista(string nombre, string id, string email, string especialidad, string herramientas)
	:Personal(nombre, id, email, especialidad), herramientasDeDibujo(herramientas)
{
	estrategiaTrabajo = new EstrategiaArtista();
}

Artista::~Artista()
{
}

void Artista::setHerramientasDeDibujo(string herramientas)
{
	herramientasDeDibujo = herramientas;
}


string Artista::getHerramientasDeDibujo() const
{
	return herramientasDeDibujo;
}

string Artista::mostrarPerfil() const
{
	stringstream s;
	s << "Perfil del Artista:" << endl;
	s << "	Nombre: " << getNombre() << endl;
	s << "	ID: " << getId() << endl;
	s << "	Email: " << getEmail() << endl;
	s << "	Especialidad: " << getEspecialidad() << endl;
	s << "	Herramientas de Dibujo: " << getHerramientasDeDibujo() << endl;
	return s.str();

}

string Artista::finalizarLaTareaStrategy(TareaProduccion* tareaQueCompleto) {
	return estrategiaTrabajo->realizarTarea(tareaQueCompleto);
}



