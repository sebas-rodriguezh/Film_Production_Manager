#include <iostream>
#include <Windows.h>
#include "ListaPeliculas.h"
#include "Studio.h"
#include "Artista.h"
#include "IngenieroSonido.h"
#include "Productor.h"

void funcionPruebaConStategys();
void funcionPeliculasConYSinPersonal();

int main() {
	Studio* studioArt = new Studio();

	int opcionMenu = 0;

	do {
		system("cls");

		cout << "\n		MENU DE PRODUCCION		\n" << endl;
		cout << "1. Insertar Personal al sistema. \n";
		cout << "2. Insertar Pelicula al sistema. \n";
		cout << "3. Asignar tareas a personas.\n";
		cout << "4. Asignar personal a una pelicula [IMPORTANTE].\n";
		cout << "5. Marcar tareas como completadas.\n";
		cout << "6. Mostrar TODO el personal del sistema.\n";
		cout << "7. Mostrar TODAS las peliculas del sistema.\n";
		cout << "8. Cargar datos desde archivos.\n";
		cout << "9. Salir.\n" << endl;
		cout << "Seleccione una opcion: ";
		cin >> opcionMenu;

		system("cls");

		while (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Entrada invalida. Intente de nuevo: "; //excepcion
			cin >> opcionMenu;
		} //Esto valida por si meten strings en lugar de numeros. 

		switch (opcionMenu) {
		case 1:
		{
			string nombre, id, email, especialidad;
			int opcSubMenu = 0;
			Personal* personalAInsertar;

			cout << "1). Insertar artista en el sistema. " << endl;
			cout << "2). Insertar Ingeniero en sonido en el sistema. " << endl;
			cout << "3). Insertar Productor en el sistema. " << endl;
			cout << endl << "Digite la opcion: "; cin >> opcSubMenu;

			system("cls");

			switch (opcSubMenu)
			{
			case 1:
			{
				string herramientas;

				cout << "		Insertando Artista: " << endl;
				cout << "Digite el nombre: "; cin >> nombre;
				cout << "Digite el ID: "; cin >> id;
				cout << "Digite el email: "; cin >> email;
				cout << "Digite la especialidad: "; cin >> especialidad;
				cout << "Digite la herramienta de dibujo que usa: "; cin >> herramientas;

				personalAInsertar = new Artista(nombre, id, email, especialidad, herramientas);

				//Aca van los trys. 
				if (studioArt->registrarPersonal(personalAInsertar)) {
					cout << "Se ingreso correctamente al artista en el sistema. " << endl;
					system("pause");
					system("cls");
				}
				else {
					cout << "No se ingreso al sistema, ID repetido. " << endl; //excepcion 
					system("pause");
					system("cls");
					delete personalAInsertar;
				}
			}
			break;

			case 2:
			{
				int anniosExp = 0;
				string expMezcla;

				cout << "		Insertando Ing.Sonido: " << endl;
				cout << "Digite el nombre: "; cin >> nombre;
				cout << "Digite el ID: "; cin >> id;
				cout << "Digite el email: "; cin >> email;
				cout << "Digite la especialidad: "; cin >> especialidad;
				cout << "Digite los annios de experiencia: "; cin >> anniosExp;
				cout << "Digite el area en el que tiene experiencia: "; cin >> expMezcla;

				personalAInsertar = new IngenieroSonido(nombre, id, email, especialidad, anniosExp, expMezcla);

				//Aca van los trys. 
				if (studioArt->registrarPersonal(personalAInsertar)) {
					cout << "Se ingreso correctamente al Ing.Sonido en el sistema. " << endl;
					system("pause");
					system("cls");
				}
				else {
					cout << "No se ingreso al sistema, ID repetido. " << endl; //excepcion
					system("pause");
					system("cls");
					delete personalAInsertar;
				}

			}
			break;

			case 3:
			{
				double presupuesto = 0.0;
				string cronograma;

				cout << "		Insertando Productor: " << endl;
				cout << "Digite el nombre: "; cin >> nombre;
				cout << "Digite el ID: "; cin >> id;
				cout << "Digite el email: "; cin >> email;
				cout << "Digite la especialidad: "; cin >> especialidad;
				cout << "Digite el presupuesto que posee para la pelicula: "; cin >> presupuesto;
				cin.ignore();
				cout << "Digite su cronograma [L - D]: ";
				getline(cin, cronograma);

				personalAInsertar = new Productor(nombre, id, email, especialidad, presupuesto, cronograma);

				//Aca van los trys. 
				if (studioArt->registrarPersonal(personalAInsertar)) {
					cout << "Se ingreso correctamente al Productor en el sistema. " << endl;
					system("pause");
					system("cls");
				}
				else {
					cout << "No se ingreso al sistema, ID repetido. " << endl; //same excepction nigg
					system("pause");
					system("cls");
					delete personalAInsertar;
				}

			}
			break;

			default:
				cout << "opcionMenu invalida. Intente de nuevo.\n"; //excpecion
				system("pause");
				system("cls");
				break;
			}

		}
		break;

		case 2:
		{
			string titulo, id;
			Pelicula* peliculaAInsertar;

			cout << "2. Insertar Pelicula al sistema. \n";

			//Excepcion. 
			if (studioArt->getPersonal()->mostrarTodoElPersonal().empty())
			{
				cout << "Error: No hay personal que pueda trabajar en la pelicula. " << endl; //excepcion
				system("pause");
				system("cls");
				break;
			}

			cin.ignore();
			cout << "Digite el titulo de la pelicula: ";
			getline(cin, titulo);
			cout << "Digite el ID de la pelicula: ";
			getline(cin, id);

			peliculaAInsertar = new Pelicula(titulo, id);

			if (studioArt->registrarPelicula(peliculaAInsertar)) {
				cout << "Se ingreso correctamente la pelicula en el sistema. " << endl;
				system("pause");
				system("cls");

			}
			else {
				cout << "No se ingreso al sistema, ID repetido. " << endl; //excepcion
				system("pause");
				system("cls");
				delete peliculaAInsertar;
			}

		}
		break;

		case 3:
		{
			string idPelicula, idPersona, idTarea, descripcionTarea;

			cout << "		Asignar tareas a personas.\n";

			if (studioArt->getPeliculas()->mostrarPeliculasQueTienesPersonalAsignado().empty())
			{
				cout << "Error: No hay ninguna pelicula con personal asignado. " << endl; //excpecion
				system("pause");
				system("cls");
				break;
			}
			cin.ignore();

			cout << "		Lista de peliculas con algun trabajor asignado: " << endl;
			cout << studioArt->getPeliculas()->mostrarPeliculasQueTienesPersonalAsignado() << endl;
			cout << endl << "Digite el ID de la pelicula que asignara: ";
			getline(cin, idPelicula);
			Pelicula* peliSeleccionada = studioArt->getPeliculaPorID(idPelicula);

			system("pause");
			system("cls");

			if (!peliSeleccionada) {
				cout << "Error: No existe ninguna pelicula con ese ID. " << endl; //excpecion
				system("pause");
				system("cls");
				break;
			}

			cout << "		Lista de trabajadores que estan participando en la pelicula: " << endl;
			cout << peliSeleccionada->mostrarPersonal() << endl;

			cout << endl << "Digite el ID del trabajador que asignara: ";
			getline(cin, idPersona);
			Personal* personalSeleccionado = studioArt->getPersonalPorID(idPersona);

			if (!personalSeleccionado) {
				cout << "Error: No existe ninguna trabajador con ese ID. " << endl;//excpecion
				system("pause");
				system("cls");
				break;
			}
			system("pause");
			system("cls");
			//Si llego aca, logro agarrar una peli y un personal valido. 

			cout << "Digite el ID de la tarea: ";
			getline(cin, idTarea);
			cout << "Digite la descripcion de la tarea: ";
			getline(cin, descripcionTarea);

			TareaProduccion* tareaAsignada = new TareaProduccion(idTarea, peliSeleccionada, idPersona, descripcionTarea, false);
			tareaAsignada->asignarleTareaAlResponsable(idPersona);
			peliSeleccionada->agregarTarea(tareaAsignada);
			cout << "Se asigno la tarea correctamente. " << endl;
			system("pause");
		}
		break;

		case 4:
		{
			string idPelicula, idPersona, idTarea, descripcionTarea;

			cout << "		Asignar personal a una pelicula [IMPORTANTE].\n";

			if (studioArt->getPersonal()->mostrarTodoElPersonal().empty() || studioArt->getPeliculas()->mostrarTodasLasPeliculas().empty())
			{
				cout << "Error: No hay suficientes datos para registrar una tarea. " << endl;//excpecion
				system("pause");
				system("cls");
				break;
			}

			cin.ignore();

			cout << "			Lista de peliculas del Studio" << endl;
			cout << studioArt->getPeliculas()->mostrarTodasLasPeliculas() << endl;
			cout << endl << "Digite el ID de la pelicula que asignara: ";
			getline(cin, idPelicula);
			Pelicula* peliSeleccionada = studioArt->getPeliculaPorID(idPelicula);

			if (!peliSeleccionada) {
				cout << "Error: No existe ninguna pelicula con ese ID. " << endl; //excpecion
				system("pause");
				system("cls");
				break;
			}
			system("pause");
			system("cls");

			cout << "			Lista de trabajadores del Studio" << endl;
			cout << studioArt->getPersonal()->mostrarTodoElPersonal() << endl;
			cout << endl << "Digite el ID del trabajador que asignara: ";
			getline(cin, idPersona);
			Personal* personalSeleccionado = studioArt->getPersonalPorID(idPersona);

			if (!personalSeleccionado) {
				cout << "Error: No existe ninguna trabajador con ese ID. " << endl; //excpecion
				system("pause");
				system("cls");
				break;
			}

			peliSeleccionada->agregarPersonal(personalSeleccionado);
			cout << "Se asigno la tarea con exito. " << endl;
			system("pause");

		}
		break;

		case 5:
		{
			string idPelicula, idTarea;
			cout << "	Marcar tareas como completadas.\n";
			cin.ignore();
			if (studioArt->getPeliculas()->mostrarPeliculasConTareasAsignadas().empty())
			{
				cout << "Error: No hay peliculas que tengan tareas pendientes. " << endl; //excpecion
				system("pause");
				system("cls");
				break;
			}

			cout << "Lista de peliculas con tareas pendientes de completar. " << endl << endl;
			cout << studioArt->getPeliculas()->mostrarPeliculasConTareasAsignadas() << endl;

			cout << "Digite el ID de la pelicula que seleccionara: ";
			getline(cin, idPelicula);

			Pelicula* peliSeleccionada = studioArt->getPeliculaPorID(idPelicula);

			if (!peliSeleccionada) {
				cout << "Error: No existe ninguna pelicula con ese ID. " << endl; //excpecion 
				break;
			}
			system("pause");
			system("cls");

			cout << "Tareas pendientes para esa pelicula: " << endl;
			cout << peliSeleccionada->mostrarTareasPendientes() << endl;

			cout << "Digite el ID de la TAREA que desea completar: ";
			getline(cin, idTarea);

			TareaProduccion* tareaACompletar = peliSeleccionada->getTareaPorIDTarea(idTarea);

			if (tareaACompletar)
			{
				cout << tareaACompletar->completarTarea() << endl;
				peliSeleccionada->eliminarTarea(tareaACompletar);

				cout << "Tarea completada y eliminada correctamente." << endl;
				system("pause");
			}
			else {
				cout << "No se encontro la tarea con el ID: " << idTarea << endl; //excpecion
				system("pause");
			}
		}
		break;

		case 6:
		{
			cout << endl << "Planilla del Studio: " << endl;
			cout << studioArt->listadoPersonal() << endl;
			system("pause");
		}
		break;

		case 7:
		{
			cout << endl << "Peliculas del Studio: " << endl;
			cout << studioArt->listadoPeliculas() << endl;
			system("pause");
		}
		break;

		case 8:
		{
			cout << "8. Cargar datos desde archivos.\n";
			system("pause");
			system("cls");
		}
		break;

		default:
			cout << "opcionMenu invalida. Intente de nuevo.\n";
			system("pause");
			system("cls");
			break;
		}

	} while (opcionMenu != 9);

	return 0;
}

void funcionPruebaConStategys() {
	string idDeTarea;


	Personal* artista1 = new Artista("Ulises", "1111", "uliVillagram@gmail.com", "Arte Digital", "PhotoShop");
	Personal* artista2 = new Artista("Camilo", "2222", "uliVillagram@gmail.com", "Arte Digital", "PhotoShop");
	Personal* artista3 = new Artista("Anita", "3333", "uliVillagram@gmail.com", "Arte Digital", "PhotoShop");

	Personal* sonido1 = new IngenieroSonido("Marvin", "324334", "maerioeded", "Sonido especial", 4, "SDEstereo");
	Personal* productor1 = new Productor("Sebas", "4334412", "sebas4343", "Admin", 4500, "Lunes - Jueves");




	Pelicula* peli1 = new Pelicula("La Aventura", "342932");
	peli1->agregarPersonal(artista1);
	peli1->agregarPersonal(sonido1);
	peli1->agregarPersonal(productor1);


	TareaProduccion* tarea1 = new TareaProduccion("2424", peli1, "1111", "Pintar los personajes", false);
	TareaProduccion* tarea2 = new TareaProduccion("4345", peli1, "324334", "Bugs de sonido", false);
	TareaProduccion* tarea3 = new TareaProduccion("3455", peli1, "4334412", "Aceptar presupuesto de actores", false);

	peli1->agregarTarea(tarea1);
	peli1->agregarTarea(tarea2);
	peli1->agregarTarea(tarea3);



	tarea1->asignarleTareaAlResponsable(tarea1->getIdDelResponsable());
	tarea2->asignarleTareaAlResponsable(tarea2->getIdDelResponsable());
	tarea3->asignarleTareaAlResponsable(tarea3->getIdDelResponsable());

	cout << peli1->mostrarPelicula() << endl;
	cout << endl << "Por favor, digite el ID de la tarea que va a completar: "; cin >> idDeTarea;

	TareaProduccion* tareaACompletar = peli1->getTareaPorIDTarea(idDeTarea);

	if (tareaACompletar)
	{
		cout << tareaACompletar->completarTarea() << endl;
		peli1->eliminarTarea(tareaACompletar);

		cout << "Tarea completada y eliminada correctamente." << endl;
		cout << "Estas son las tareas activas para esta pelicula: " << endl;
		cout << endl << endl << peli1->mostrarPelicula() << endl;
	}
	else {
		cout << "No se encontro la tarea con el ID: " << idDeTarea << endl;
	}
}
void funcionPeliculasConYSinPersonal() {
	ListaPeliculas* gestorPelis = new ListaPeliculas();
	Pelicula* pelicula1 = new Pelicula("La vida e bella", "1111");
	Pelicula* pelicula2 = new Pelicula("La Blanca Viuda", "2222");
	Pelicula* pelicula3 = new Pelicula("Animal Farm", "3333");

	Personal* artista1 = new Artista("Ulises", "1111", "uliVillagram@gmail.com", "Arte Digital", "PhotoShop");
	Personal* productor1 = new Productor("Sebas", "4334412", "sebas4343", "Admin", 4500, "Lunes - Jueves");


	pelicula1->agregarPersonal(artista1);

	pelicula2->agregarPersonal(productor1);
	pelicula2->agregarPersonal(artista1);


	if (gestorPelis->insertarPelicula(pelicula1)) {
		cout << "Se pudo insertar peli1. " << endl;
	}

	if (gestorPelis->insertarPelicula(pelicula2)) {
		cout << "Se pudo insertar peli2. " << endl;
	}

	if (gestorPelis->insertarPelicula(pelicula3)) {
		cout << "Se pudo insertar peli3. " << endl;
	}
	else {
		cout << "NO se pudo insertar peli3 porque no tiene personal asignado. " << endl;
	}

	cout << gestorPelis->mostrarTodasLasPeliculas() << endl;



}