#include "Personal.h"

Personal::Personal(const string& nombre, const string& id, const string& email, const string& especialidad)
    : nombre(nombre), id(id), email(email), especialidad(especialidad)
{
    estrategiaTrabajo = nullptr;
}


Personal::~Personal() {

}

// Getters
string Personal::getNombre() const {
    return nombre;
}

string Personal::getId() const {
    return id;
}

string Personal::getEmail() const {
    return email;
}

string Personal::getEspecialidad() const {
    return especialidad;
}

// Setters
void Personal::setNombre(const string& nombre) {
    this->nombre = nombre;
}

void Personal::setId(const string& id) {
    this->id = id;
}

void Personal::setEmail(const string& email) {
    this->email = email;
}

void Personal::setEspecialidad(const string& especialidad) {
    this->especialidad = especialidad;
}


