#include "IngenieroSonido.h"

IngenieroSonido::IngenieroSonido(string nombre, string id, string email, string especialidad, int annniosExp, string expEnMezcla)
	: Personal(nombre, id, email, especialidad), anniosExperiencia(annniosExp), experienciaEnMezcla(expEnMezcla)
{
	estrategiaTrabajo = new EstrategiaSonido();
}

IngenieroSonido::~IngenieroSonido()
{
}

void IngenieroSonido::setAnniosExperiencia(int anniosExp)
{
	anniosExperiencia = anniosExp;
}

void IngenieroSonido::setExperienciaEnMezcla(string expEnMezcla) {
	experienciaEnMezcla = expEnMezcla;
}

string IngenieroSonido::getExperienciaEnMezcla() {
	return experienciaEnMezcla;
}
int IngenieroSonido::getAnniosExperiencia() {
	return anniosExperiencia;
}

string IngenieroSonido::mostrarPerfil() const {
	stringstream s;
	s << "Perfil del Ing. Sonido:" << endl;
	s << "	Nombre: " << getNombre() << endl;
	s << "	ID: " << getId() << endl;
	s << "	Email: " << getEmail() << endl;
	s << "	Especialidad: " << getEspecialidad() << endl;
	s << "	Annios de experiencia: " << anniosExperiencia << endl;
	s << "	Tiene experiencia en: " << experienciaEnMezcla << endl;
	return s.str();

}

string IngenieroSonido::finalizarLaTareaStrategy(TareaProduccion* tareaQueCompleto)
{
	return estrategiaTrabajo->realizarTarea(tareaQueCompleto);
}