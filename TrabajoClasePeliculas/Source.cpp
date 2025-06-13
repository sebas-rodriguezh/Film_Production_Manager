#include <iostream>
#include <Windows.h>
#include "ListaPeliculas.h"
#include "Studio.h"
#include "Artista.h"
#include "IngenieroSonido.h"
#include "Productor.h"
#include "Excepciones.h" 
#include "ExcepcionStudio.h"
#include "PersistenciaDeDatos.h"
using namespace std;                    



int main()
{
	try {
		Studio* studioArt = new Studio();
		PersistenciaDeDatos* persistencia = new PersistenciaDeDatos(); 

		int opcionMenu = 0;

		do {
			try{
				system("cls");

				cout << "\n		MENU DE PRODUCCION		\n" << endl;
				cout << "1. Insertar Personal al sistema. \n";
				cout << "2. Insertar Pelicula al sistema. \n";
				cout << "3. Asignar tareas a personas.\n";
				cout << "4. Asignar personal a una pelicula [IMPORTANTE].\n";
				cout << "5. Marcar tareas como completadas.\n";
				cout << "6. Mostrar TODO el personal del sistema.\n";
				cout << "7. Mostrar TODAS las peliculas del sistema.\n";
				cout << "8. Guardar datos desde archivos.\n";
				cout << "9  Cargar datos desde archivos.\n";
				cout << "10. Salir.\n" << endl;
				cout << "Seleccione una opcion: ";
				cin >> opcionMenu;

				system("cls");

				while (cin.fail()) {
					cin.clear();
					cin.ignore(1000, '\n');
					throw ExcepcionEntradaInvalida();
					//cout << "Entrada invalida. Intente de nuevo: "; //excepcion
					cin >> opcionMenu;
				} //Esto valida por si meten strings en lugar de numeros. 

				system("cls");



				switch (opcionMenu) {
				case 1: {
					string nombre, id, email, especialidad;
					int opcSubMenu = 0;
					Personal* personalAInsertar;

					cout << "1). Insertar artista en el sistema. " << endl;
					cout << "2). Insertar Ingeniero en sonido en el sistema. " << endl;
					cout << "3). Insertar Productor en el sistema. " << endl;
					cout << endl << "Digite la opcion: "; cin >> opcSubMenu;

					system("pause");
					system("cls");




					system("cls");

					switch (opcSubMenu) {
					case 1: {

						string herramientas;

						cout << "		Insertando Artista: " << endl;
						cout << "Digite el nombre: "; cin >> nombre;
						cout << "Digite el ID: "; cin >> id;
						cout << "Digite el email: "; cin >> email;
						cout << "Digite la especialidad: "; cin >> especialidad;
						cout << "Digite la herramienta de dibujo que usa: "; cin >> herramientas;

						personalAInsertar = new Artista(nombre, id, email, especialidad, herramientas);

						try {
							if (studioArt->registrarPersonal(personalAInsertar)) {
								cout << "Se ingresó correctamente al artista en el sistema." << endl;
								system("pause");
								system("cls");
							}
							else {
								throw IdReptido();
							}
						}
						catch (const ExcepcionStudio& e) {
							cout << e.mensaje() << endl;
							system("pause");
							system("cls");
							delete personalAInsertar;
						}
						break;
					}
					case 2: {
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
						try {
							//Aca van los trys. 
							if (studioArt->registrarPersonal(personalAInsertar)) {
								cout << "Se ingreso correctamente al Ing.Sonido en el sistema. " << endl;
								system("pause");
								system("cls");
							}
							else {

								throw IdReptido();//excepcion r
								system("pause");
								system("cls");
								delete personalAInsertar;
							}
						}
						catch (const ExcepcionStudio& e) {
							cout << e.mensaje() << endl;
							system("pause");
							system("cls");
						}
						break;
					}

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
						try {
							//Aca van los trys. 
							if (studioArt->registrarPersonal(personalAInsertar)) {
								cout << "Se ingreso correctamente al Productor en el sistema. " << endl;
								system("pause");
								system("cls");
							}
							else {

								throw IdReptido();
								system("pause");
								system("cls");
								delete personalAInsertar;
							}
						}
						catch (const ExcepcionStudio& e) {
							cout << e.mensaje() << endl;
							system("pause");
							system("cls");
						}

						break;
					}
					default:

						throw ExcepcionEntradaInvalida();
						system("pause");
						system("cls");
						break;
					}


					break;
				}
				case 2:
				{
					string titulo, id;
					Pelicula* peliculaAInsertar;

					cout << "2. Insertar Pelicula al sistema. \n";
					try {
						//Excepcion. 
						if (studioArt->getPersonal()->mostrarTodoElPersonal().empty())
						{

							throw  NoHayPeliculaConPersonal();
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

							throw IdReptido();
							system("pause");
							system("cls");
							delete peliculaAInsertar;
						}
					}
					catch (const ExcepcionStudio& e) {
						cout << e.mensaje() << endl;
						system("pause");
						system("cls");
					}
					break;
				}
				case 3:
				{
					string idPelicula, idPersona, idTarea, descripcionTarea;

					cout << "		Asignar tareas a personas.\n";
					try {
						if (studioArt->getPeliculas()->mostrarPeliculasQueTienesPersonalAsignado().empty())
						{

							throw NoHayPersonalParaLaPeli();
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

							throw PeliculaSinId();
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

							throw NoExistePersonalConEseId();
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
					catch (const ExcepcionStudio& e) {
						cout << e.mensaje() << endl;
						system("pause");
						system("cls");
					}
				}
				break;

				case 4:
				{
					string idPelicula, idPersona, idTarea, descripcionTarea;

					cout << "		Asignar personal a una pelicula [IMPORTANTE].\n";
					try {
						if (studioArt->getPersonal()->mostrarTodoElPersonal().empty() || studioArt->getPeliculas()->mostrarTodasLasPeliculas().empty())
						{

							throw SinDatosParaRegistroTarea();
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

							throw PeliculaSinId();
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

							throw NoExistePersonalConEseId();
							system("pause");
							system("cls");
							break;
						}

						peliSeleccionada->agregarPersonal(personalSeleccionado);
						cout << "Se asigno la tarea con exito. " << endl;
						system("pause");
					}
					catch (const ExcepcionStudio& e) {
						cout << e.mensaje() << endl;
						system("pause");
						system("cls");
					}
				}
				break;

				case 5:
				{
					try {
						string idPelicula, idTarea;
						cout << "	Marcar tareas como completadas.\n";
						cin.ignore();
						if (studioArt->getPeliculas()->mostrarPeliculasConTareasAsignadas().empty())
						{

							throw NoHayPeliConTareaPendiente();
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

							throw PeliculaSinId();
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

							throw NoSeEncontroLaTareaConEseId();
							system("pause");
						}
					}
					catch (const ExcepcionStudio& e) {
						cout << e.mensaje() << endl;
						system("pause");
						system("cls");
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
					cout << "8. Guardar datos desde archivos.\n";
					persistencia->guardarPersonal(studioArt->getPersonal());
					persistencia->guardarPeliculas(studioArt->getPeliculas());
					persistencia->guardarPersonalPorPelicula(studioArt->getPeliculas());
					persistencia->guardarTareas(studioArt->getPeliculas());
					cout << "Datos guardados existosamente. " << endl;

					system("pause");
					system("cls");

				}
				break;
				case 9:
				{
					cout << "9. Cargar datos desde archivos.\n";
					studioArt->setPersonal(persistencia->cargarPersonal());
					studioArt->setPeliculas(persistencia->cargarPeliculas());
					persistencia->cargarPersonalPorPelicula(studioArt->getPeliculas(), studioArt->getPersonal());
					persistencia->cargarTareas(studioArt->getPeliculas());

					cout << "Datos cargados exitosamente." << endl;

					system("pause");
					system("cls");
				}
				break;
				case 10:
				{
					cout << "Saliendo del programa!!!" << endl;

				}
				break;
				default:

					throw OpcionMenuInvalida();
					system("pause");
					system("cls");
					break;
				}
			}
			catch (const ExcepcionStudio& e) {
				cout << "Error: " << e.mensaje() << endl;
				system("pause");
				system("cls");
			}
			
		} while (opcionMenu != 10);


	}catch (const ExcepcionStudio& ex) { 
			cout  << ex.mensaje() << endl; 
			system("pause"); 
	}

	return 0;
}

	
