#include "PersistenciaDeDatos.h"
#include "Productor.h"

void PersistenciaDeDatos::guardarPersonal(ListaPersonal* personal)
{
	ofstream archivoPersonal("Personal.txt");
	Nodo<Personal>* trabajador = personal->getPtrPersonal()->getCabeza();
	while (trabajador != nullptr) {
		Personal* p = trabajador->getDato();
		string tipo;

		if (Artista* aux = dynamic_cast<Artista*>(p))
		{
			tipo = "Artista";
			archivoPersonal << tipo << ";"
				<< aux->getNombre() << ";"
				<< aux->getId() << ";"
				<< aux->getEmail() << ";"
				<< aux->getEspecialidad() << ";"
				<< aux->getHerramientasDeDibujo() << "\n";
		}
		else if (IngenieroSonido* aux = dynamic_cast<IngenieroSonido*>(p))
		{
			tipo = "IngenieroSonido";
			archivoPersonal << tipo << ";"
				<< aux->getNombre() << ";"
				<< aux->getId() << ";"
				<< aux->getEmail() << ";"
				<< aux->getEspecialidad() << ";"
				<< aux->getAnniosExperiencia() << ";"
				<< aux->getExperienciaEnMezcla() << "\n";
		}
		else if (Productor* aux = dynamic_cast<Productor*>(p))
		{
			tipo = "Productor";
			archivoPersonal << tipo << ";"
				<< aux->getNombre() << ";"
				<< aux->getId() << ";"
				<< aux->getEmail() << ";"
				<< aux->getEspecialidad() << ";"
				<< aux->getCronograma() << ";"
				<< aux->getPresupuesto() << "\n";
		}

		trabajador = trabajador->getSiguiente();
	}
	archivoPersonal.close();
}

ListaPersonal* PersistenciaDeDatos::cargarPersonal()
{
	ifstream archivo("Personal.txt");
	ListaPersonal* lista = new ListaPersonal();
	string linea;

	while (getline(archivo, linea)) {
		stringstream ss(linea);
		string tipo, nombre, id, email, especialidad;

		getline(ss, tipo, ';');
		getline(ss, nombre, ';');
		getline(ss, id, ';');
		getline(ss, email, ';');
		getline(ss, especialidad, ';');

		Personal* p = nullptr;

		if (tipo == "Artista") {
			string herramientas;
			getline(ss, herramientas, '\n');
			p = new Artista(nombre, id, email, especialidad, herramientas);
		}
		else if (tipo == "IngenieroSonido") {

			string annosExpStr, expMezcla;
			getline(ss, annosExpStr, ';');
			getline(ss, expMezcla, '\n');
			int annosExp = stoi(annosExpStr);
			p = new IngenieroSonido(nombre, id, email, especialidad, annosExp, expMezcla);
		}
		else if (tipo == "Productor") {

			string cronograma, presupuestoStr;
			getline(ss, cronograma, ';');
			getline(ss, presupuestoStr, '\n');
			double presupuesto = stod(presupuestoStr);
			p = new Productor(nombre, id, email, especialidad, presupuesto, cronograma);
		}

		if (p != nullptr)
			lista->insertarPersonal(p);
	}

	archivo.close();
	return lista;
}


void PersistenciaDeDatos::guardarPeliculas(ListaPeliculas* peliculas)
{
	ofstream archivoPeliculas("Peliculas.txt");
	Nodo<Pelicula>* pelicula = peliculas->getPeliculas()->getCabeza();
	while (pelicula != nullptr) {
		archivoPeliculas << pelicula->getDato()->getTitulo() << ";"
						<< pelicula->getDato()->getId() << "\n";
		pelicula = pelicula->getSiguiente();
	}
	archivoPeliculas.close();

}

ListaPeliculas* PersistenciaDeDatos::cargarPeliculas()
{
	ifstream archivo("Peliculas.txt");
	if (!archivo.is_open()) {
		cout << "Error al abrir archivo Peliculas.txt\n";
		return new ListaPeliculas();
	}
	ListaPeliculas* lista = new ListaPeliculas();
	string linea;

	while (getline(archivo, linea)) {
		stringstream ss(linea);
		string id, titulo;

		getline(ss, titulo, ';'); 
		getline(ss, id, ';'); 

		Pelicula* p = new Pelicula(titulo, id);
		lista->insertarPelicula(p);
	}

	archivo.close();
	return lista;
}

void PersistenciaDeDatos::guardarTareas(ListaPeliculas* peliculas)
{
	ofstream archivoTareas("Tareas.txt");
	Nodo<Pelicula>* nodoPeli = peliculas->getPeliculas()->getCabeza();

	while (nodoPeli != nullptr) {
		Pelicula* peli = nodoPeli->getDato();
		Nodo<TareaProduccion>* nodoTarea = peli->getTareas()->getCabeza(); 
		while (nodoTarea != nullptr) {
			TareaProduccion* tarea = nodoTarea->getDato();
			archivoTareas << tarea->getIdTarea() << ";" 
				<< peli->getId() << ";"
				<< tarea->getIdDelResponsable() << ";"
				<< tarea->getDescripcion() << ";"
				<< tarea->getEstado() << "\n";
			nodoTarea = nodoTarea->getSiguiente(); 
		}

		nodoPeli = nodoPeli->getSiguiente();
	}

	archivoTareas.close();

}

void PersistenciaDeDatos::cargarTareas(ListaPeliculas* peliculas)
{
	ifstream archivo("Tareas.txt");
	if (!archivo.is_open()) {
		cout << "Error al abrir archivo Tareas.txt\n";
		return;
	}
	string linea;

	while (getline(archivo, linea)) {
		stringstream ss(linea);
		string idTarea, idPeli, idResp, desc, estadoStr;

		getline(ss, idTarea, ';');
		getline(ss, idPeli, ';');
		getline(ss, idResp, ';');
		getline(ss, desc, ';');
		getline(ss, estadoStr, ';');

		Pelicula* peli = peliculas->getPeliculaPorID(idPeli);
		if (peli != nullptr) { 
			TareaProduccion* tarea = new TareaProduccion(idTarea, peli, idResp, desc, estadoStr == "1"); 
			peli->agregarTarea(tarea); 
		}
	}

	archivo.close();
}

void PersistenciaDeDatos::guardarPersonalPorPelicula(ListaPeliculas* peliculas) {
	ofstream archivo("PersonalPorPelicula.txt");
	Nodo<Pelicula>* nodoPeli = peliculas->getPeliculas()->getCabeza();

	while (nodoPeli != nullptr) {
		Pelicula* peli = nodoPeli->getDato();
		Nodo<Personal>* nodoPersonal = peli->getPersonal()->getCabeza();

		while (nodoPersonal != nullptr) {
			archivo << peli->getId() << ";" << nodoPersonal->getDato()->getId() << "\n";
			nodoPersonal = nodoPersonal->getSiguiente();
		}

		nodoPeli = nodoPeli->getSiguiente();
	}

	archivo.close();
}

void PersistenciaDeDatos::cargarPersonalPorPelicula(ListaPeliculas* peliculas, ListaPersonal* personal) { 
	ifstream archivo("PersonalPorPelicula.txt");
	string linea;

	while (getline(archivo, linea)) {
		stringstream ss(linea);
		string idPeli, idPersonal;

		getline(ss, idPeli, ';');
		getline(ss, idPersonal, ';');

		Pelicula* peli = peliculas->getPeliculaPorID(idPeli);
		Personal* pers = personal->getPersonalPorID(idPersonal);

		if (peli != nullptr && pers != nullptr) {
			peli->agregarPersonal(pers); 
		}
	}

	archivo.close();
}
