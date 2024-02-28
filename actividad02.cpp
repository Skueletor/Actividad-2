#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <iomanip>

using namespace std;

//Función para limpiar la pantalla después de cada ejecución (estética)
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    cout << "\033[2J\033[1;1H"; // ANSI escape code para el clear de pantalla
#endif
}

struct Libro {
    string sTitulo;
    string sAutor;
    string sISBN;
    int nAnioPublicacion;
    int nNumeroPaginas;
    string sEditorial;
    string sIdioma;
};

struct Usuario {
    int nIDUsuario;
    string sNombre;
    string sApellido;
    string sEmail;
    string sTipoUsuario;
};

struct Bibliotecario {
    int nIDEmpleado;
    string sNombre;
    string sApellido;
    string sEmail;
    string sHorarioLaboral;
};

void MenuPrincipal(bool datosGenerados) {
	cout << endl << "+-----------------------------+" << endl;
    cout << "| Menu Principal" << endl;
    cout << "| 1. Llenado de datos" << endl;
    if (datosGenerados) {
        cout << "| 2. Listados" << endl;
        cout << "| 3. Busqueda" << endl;
    }
    cout << "| 0. Salir" << endl;
	cout << "+-----------------------------+" << endl;
}

void SubMenuListados() {
	cout << endl << "+-----------------------------+" << endl;
    cout << "| Submenu de Listados" << endl;
    cout << "| A) Listado de libros" << endl;
    cout << "| B) Listado de usuarios" << endl;
    cout << "| C) Listado de bibliotecarios" << endl;
    cout << "| X) Volver atras" << endl;
	cout << "+-----------------------------+" << endl;
}

void SubMenuBusqueda() {
	cout << endl << "+-----------------------------+" << endl;
    cout << "| Submenu de Busqueda" << endl;
    cout << "| A) Busqueda de libro (por titulo)" << endl;
    cout << "| B) Busqueda de usuario (por nombre y apellido)" << endl;
    cout << "| C) Busqueda de bibliotecario (por nombre y apellido)" << endl;
    cout << "| X) Volver atras" << endl;
	cout << "+-----------------------------+" << endl;
}

void generardatos(Libro* libros, int numLibros) {
	//Datos de los libros
    const string listaLibros[] = {"Aprende C", "Aprende PHP", "Aprende Linux", "Programacion", "Programacion POO", "Algoritmos de Datos", "Inteligencia Artificial", "Desarrollo Web", "Bases de Datos"};
    const string listaAutores[] = {"Adela Zamudio", "Jaime Mendoza Gonzales", "Armando Chirveches", "Manuel Vargas", "Emilio Martinez Cardona", "Isabel Mesa de Inchauste", "Enrique Finot", "Gladys Rivero de Jimenez", "Hugo Menacho"};
    const string listaEditoriales[] = {"EPDB", "La Hoguera", "El Pais", "3K", "Muela del Diablo", "El Cuervo", "Grito del Viento", "Nuevo Milenio", "Libros del Cardon", "Nuevo Mundo", "El Sol", "Monte Avila", "Los Amigos del Libro", "Punto de Lectura","El Quetzal"};
    const string listaIdiomas[] = {"Espanol", "Ingles", "Italiano"};
//Bucle para hacer los datos dependiendo de la cantidad que haya ingresado en el main (4 libros actualmente)
    for (int i = 0; i < numLibros; ++i) {
        (*(libros + i)).sTitulo = listaLibros[rand() % (sizeof(listaLibros) / sizeof(listaLibros[0]))];
        (*(libros + i)).sAutor = listaAutores[rand() % (sizeof(listaAutores) / sizeof(listaAutores[0]))];
        (*(libros + i)).sISBN = to_string(rand() % 900000000 + 100000000);
        (*(libros + i)).nAnioPublicacion = rand() % 24 + 2000;
        (*(libros + i)).nNumeroPaginas = rand() % 500 + 100;
        (*(libros + i)).sEditorial = listaEditoriales[rand() % (sizeof(listaEditoriales) / sizeof(listaEditoriales[0]))];
        (*(libros + i)).sIdioma = listaIdiomas[rand() % (sizeof(listaIdiomas) / sizeof(listaIdiomas[0]))];
    }
}


void generardatos(Usuario* usuarios, int numUsuarios, const string* listaNombres, const string* listaApellidos) {
	//Datos de los usuarios para el tipo
    string listaTiposUsuarios[] = {"Estudiante", "Profesor", "Administrativo"};
//Bucle para hacer los datos dependiendo de la cantidad que haya ingresado en el main (5 usuarios actualmente)
    for (int i = 0; i < numUsuarios; ++i) {
        (*(usuarios + i)).nIDUsuario = i + 1;
        (*(usuarios + i)).sNombre = listaNombres[rand() % 8]; 
        (*(usuarios + i)).sApellido = listaApellidos[rand() % 8]; 
        (*(usuarios + i)).sEmail = (*(usuarios + i)).sNombre + (*(usuarios + i)).sApellido + "@gmail.com";
        (*(usuarios + i)).sTipoUsuario = listaTiposUsuarios[rand() % 3]; 
    }
}

void generardatos(Bibliotecario* bibliotecarios, int numBibliotecarios, const string* listaNombres, const string* listaApellidos) {
    string listaHorarios[] = {"8:00 - 16:00", "9:00 - 17:00", "10:00 - 18:00"};
//Bucle para hacer los datos dependiendo de la cantidad que haya ingresado en el main (5 bibliotecarios actualmente)
    for (int i = 0; i < numBibliotecarios; ++i) {
        (*(bibliotecarios + i)).nIDEmpleado = 1000 + i;
        (*(bibliotecarios + i)).sNombre = listaNombres[rand() % 8]; 
        (*(bibliotecarios + i)).sApellido = listaApellidos[rand() % 8]; 
        (*(bibliotecarios + i)).sEmail = (*(bibliotecarios + i)).sNombre + (*(bibliotecarios + i)).sApellido + "@library.com";
        (*(bibliotecarios + i)).sHorarioLaboral = listaHorarios[rand() % 3]; 
    }
}

// Funciones de imprimir en pantalla los libros, usuarios y bibliotecarios.
void mostrar(Libro* libros, int numLibros, int index = 0) {
    if (index >= numLibros) {
        return;
    }
//Para imprimir los textos en la parte superior
    if (index == 0) {
        cout << "+-----------------------------+" << endl;
        cout << "| " << setw(30) << left << "Titulo" << " | "
             << setw(30) << left << "Autor" << " | "
             << setw(15) << left << "ISBN" << " | "
             << setw(10) << left << "Anio" << " | "
             << setw(10) << left << "Paginas" << " | "
             << setw(20) << left << "Editorial" << " | "
             << setw(10) << left << "Idioma" << " |" << endl;
    }
//Para imprimir los datos abajo
    cout << "| " << setw(30) << left << (*(libros + index)).sTitulo << " | "
         << setw(30) << left << (*(libros + index)).sAutor << " | "
         << setw(15) << left << (*(libros + index)).sISBN << " | "
         << setw(10) << left << (*(libros + index)).nAnioPublicacion << " | "
         << setw(10) << left << (*(libros + index)).nNumeroPaginas << " | "
         << setw(20) << left << (*(libros + index)).sEditorial << " | "
         << setw(10) << left << (*(libros + index)).sIdioma << " |" << endl;

    mostrar(libros, numLibros, index + 1);
}

void mostrar(Usuario* usuarios, int numUsuarios, int index = 0) {
    if (index >= numUsuarios) {
        return;
    }

    if (index == 0) {
        cout << "+-----------------------------+" << endl;
        cout << "| " << setw(10) << left << "ID" << " | "
             << setw(25) << left << "Nombre" << " | "
             << setw(30) << left << "Email" << " | "
             << setw(15) << left << "Tipo de usuario" << " |" << endl;
    }

    cout << "| " << setw(10) << left << (*(usuarios + index)).nIDUsuario << " | "
         << setw(25) << left << (*(usuarios + index)).sNombre + " " + (*(usuarios + index)).sApellido << " | "
         << setw(30) << left << (*(usuarios + index)).sEmail << " | "
         << setw(15) << left << (*(usuarios + index)).sTipoUsuario << " |" << endl;

    mostrar(usuarios, numUsuarios, index + 1);
}

void mostrar(Bibliotecario* bibliotecarios, int numBibliotecarios, int index = 0) {
    if (index >= numBibliotecarios) {
        return;
    }

    if (index == 0) {
        cout << "+-----------------------------+" << endl;
        cout << "| " << setw(10) << left << "ID" << " | "
             << setw(25) << left << "Nombre" << " | "
             << setw(30) << left << "Email" << " | "
             << setw(20) << left << "Horario de trabajo" << " |" << endl;
    }

    cout << "| " << setw(10) << left << (*(bibliotecarios + index)).nIDEmpleado << " | "
         << setw(25) << left << (*(bibliotecarios + index)).sNombre + " " + (*(bibliotecarios + index)).sApellido << " | "
         << setw(30) << left << (*(bibliotecarios + index)).sEmail << " | "
         << setw(20) << left << (*(bibliotecarios + index)).sHorarioLaboral << " |" << endl;

    mostrar(bibliotecarios, numBibliotecarios, index + 1);
}

// Funciones de búsqueda para libros, usuarios y bibliotecarios.
void buscar(Libro* libros, int numLibros, const string& textoBusqueda, int indice = 0, bool encontrado = false) {
    if (indice >= numLibros) {
        if (!encontrado) {
            cout << "No se encontraron libros que coincidan con '" << textoBusqueda << "'." << endl;
        }
        return;
    }
//Función para convertir texto ingresado por el usuario en minúscula
    string textoMinusculas = textoBusqueda;
    for (char& c : textoMinusculas) {
        c = tolower(c);
    }
//Función para convertir título del libro en minúscula
    string tituloMinusculas = (*(libros + indice)).sTitulo;
    for (char& c : tituloMinusculas) {
        c = tolower(c);
    }

    if (tituloMinusculas.find(textoMinusculas) != string::npos) {
        if (!encontrado) {
            cout << "+-----------------------------+" << endl;
            cout << "| " << setw(30) << left << "Titulo" << " | "
                 << setw(30) << left << "Autor" << " | "
                 << setw(15) << left << "ISBN" << " | "
                 << setw(10) << left << "Anio" << " | "
                 << setw(10) << left << "Paginas" << " | "
                 << setw(20) << left << "Editorial" << " | "
                 << setw(10) << left << "Idioma" << " |" << endl;
            encontrado = true;
        }
        // Imprimir los detalles del libro encontrado en forma de tabla
        cout << "| " << setw(30) << left << (*(libros + indice)).sTitulo << " | "
             << setw(30) << left << (*(libros + indice)).sAutor << " | "
             << setw(15) << left << (*(libros + indice)).sISBN << " | "
             << setw(10) << left << (*(libros + indice)).nAnioPublicacion << " | "
             << setw(10) << left << (*(libros + indice)).nNumeroPaginas << " | "
             << setw(20) << left << (*(libros + indice)).sEditorial << " | "
             << setw(10) << left << (*(libros + indice)).sIdioma << " |" << endl;
    }

    buscar(libros, numLibros, textoBusqueda, indice + 1, encontrado);
}

void buscar(Usuario* usuarios, int numUsuarios, const string& texto, int indice = 0, bool encontrado = false) {
    if (indice >= numUsuarios) {
        if (!encontrado) {
            cout << "No se encontraron usuarios con '" << texto << "' en el nombre o apellido." << endl;
        }
        return;
    }
//Función para convertir texto ingresado por el usuario en minúscula
    string textoMinusculas = texto;
    for (char& c : textoMinusculas) {
        c = tolower(c);
    }
//Función para convertir el nombre y apellido en minúscula
    string nombreMinusculas = (*(usuarios + indice)).sNombre;
    string apellidoMinusculas = (*(usuarios + indice)).sApellido;
    for (char& c : nombreMinusculas) {
        c = tolower(c);
    }
    for (char& c : apellidoMinusculas) {
        c = tolower(c);
    }

    if (nombreMinusculas.find(textoMinusculas) != string::npos || apellidoMinusculas.find(textoMinusculas) != string::npos) {
        if (!encontrado) {
            cout << "+-----------------------------+" << endl;
            cout << "| " << setw(10) << left << "ID" << " | "
                 << setw(25) << left << "Nombre" << " | "
                 << setw(30) << left << "Email" << " | "
                 << setw(15) << left << "Tipo de usuario" << " |" << endl;
            encontrado = true;
        }
        // Imprimir los detalles del usuario encontrado en forma de tabla
        cout << "| " << setw(10) << left << (*(usuarios + indice)).nIDUsuario << " | "
             << setw(25) << left << (*(usuarios + indice)).sNombre + " " + (*(usuarios + indice)).sApellido << " | "
             << setw(30) << left << (*(usuarios + indice)).sEmail << " | "
             << setw(15) << left << (*(usuarios + indice)).sTipoUsuario << " |" << endl;
    }

    buscar(usuarios, numUsuarios, texto, indice + 1, encontrado);
}

void buscar(Bibliotecario* bibliotecarios, int numBibliotecarios, const string& texto, int indice = 0, bool encontrado = false) {
    if (indice >= numBibliotecarios) {
        if (!encontrado) {
            cout << "No se encontraron bibliotecarios con '" << texto << "' en el nombre o apellido." << endl;
        }
        return;
    }
//Función para convertir texto ingresado por el usuario en minúscula
    string textoMinusculas = texto;
    for (char& c : textoMinusculas) {
        c = tolower(c);
    }
//Función para convertir el nombre y apellido en minúscula
    string nombreMinusculas = (*(bibliotecarios + indice)).sNombre;
    string apellidoMinusculas = (*(bibliotecarios + indice)).sApellido;
    for (char& c : nombreMinusculas) {
        c = tolower(c);
    }
    for (char& c : apellidoMinusculas) {
        c = tolower(c);
    }

    if (nombreMinusculas.find(textoMinusculas) != string::npos || apellidoMinusculas.find(textoMinusculas) != string::npos) {
        if (!encontrado) {
            cout << "+-----------------------------+" << endl;
            cout << "| " << setw(10) << left << "ID" << " | "
                 << setw(25) << left << "Nombre" << " | "
                 << setw(30) << left << "Email" << " | "
                 << setw(20) << left << "Horario de trabajo" << " |" << endl;
            encontrado = true;
        }
        // Imprimir los detalles del bibliotecario encontrado en forma de tabla
        cout << "| " << setw(10) << left << (*(bibliotecarios + indice)).nIDEmpleado << " | "
             << setw(25) << left << (*(bibliotecarios + indice)).sNombre + " " + (*(bibliotecarios + indice)).sApellido << " | "
             << setw(30) << left << (*(bibliotecarios + indice)).sEmail << " | "
             << setw(20) << left << (*(bibliotecarios + indice)).sHorarioLaboral << " |" << endl;
    }

    buscar(bibliotecarios, numBibliotecarios, texto, indice + 1, encontrado);
}

int main() {
    srand(time(nullptr));

    const int numLibros = 4;
    const int numUsuarios = 5;
    const int numBibliotecarios = 5;

    Libro* libros = new Libro[numLibros];
    Usuario* usuarios = new Usuario[numUsuarios];
    Bibliotecario* bibliotecarios = new Bibliotecario[numBibliotecarios];

	//Nombres en una constante
    const string LISTANOMBRES[] = {"Juan", "Maria", "Luis", "Ana", "Carlos", "Antonio", "Ricardo", "Noelia"};
    const string LISTAAPELLIDOS[] = {"Gomez", "Perez", "Martinez", "Ramirez", "Rodriguez", "Fernandez", "Leon", "Flores"};

    bool datosGenerados = false;

    int opcion;
    char subOpcion;

    do {
		
        MenuPrincipal(datosGenerados);
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                // Llenado de datos
                clearScreen();
                generardatos(libros, numLibros);
                generardatos(usuarios, numUsuarios, LISTANOMBRES, LISTAAPELLIDOS);
                generardatos(bibliotecarios, numBibliotecarios, LISTANOMBRES, LISTAAPELLIDOS);
                // cout << "Datos generados aleatoriamente." << endl;
                datosGenerados = true; // Actualizar el estado de los datos
                break;
            case 2:
                // Listados
                if (datosGenerados) {
                    clearScreen();
                    do {
                        SubMenuListados();
                        cout << "Ingrese una opcion (X para volver atras): ";
                        cin >> subOpcion;
                        subOpcion = tolower(subOpcion);

                        switch (tolower(subOpcion)) {
                            case 'a':
                                // Listado de libros
                                clearScreen();
                                cout << "Listado de libros:\n";
                                mostrar(libros, numLibros);
                                break;
                            case 'b':
                                // Listado de usuarios
                                clearScreen();
                                cout << "Listado de usuarios:\n";
                                mostrar(usuarios, numUsuarios);
                                break;
                            case 'c':
                                // Listado de bibliotecarios
                                clearScreen();
                                cout << "Listado de bibliotecarios:\n";
                                mostrar(bibliotecarios, numBibliotecarios);
                                break;
                            case 'x':
                                // Volver atrás
                                break;
                            default:
                                cout << "Opcion invalida." << endl;
                        }
                    } while (tolower(subOpcion) != 'x');
                } else {
                    cout << "Primero debe generar los datos (Opcion 1)." << endl;
                }
                break;
            case 3:
                // Búsqueda
                if (datosGenerados) {
                    clearScreen();
                    do {
                        SubMenuBusqueda();
                        cout << "Ingrese una opcion (X para volver atras): ";
                        cin >> subOpcion;

                        switch (tolower(subOpcion)) {
                            case 'a': {
                                // Busqueda de libro por titulo
                                clearScreen();
                                string titulo;
                                cout << "Ingrese el titulo del libro a buscar: ";
                                cin.ignore(); // Limpiar el buffer del teclado
                                getline(cin, titulo);
                                buscar(libros, numLibros, titulo);
                                break;
                            }
                            case 'b': {
                                // Busqueda de usuario por nombre o apellido
                                clearScreen();
                                string texto;
                                cout << "Ingrese el nombre o apellido del usuario a buscar: ";
                                cin >> texto;
                                buscar(usuarios, numUsuarios, texto);
                                break;
                            }
                            case 'c': {
                                // Busqueda de bibliotecario por nombre o apellido
                                clearScreen();
                                string texto;
                                cout << "Ingrese el nombre o apellido del bibliotecario a buscar: ";
                                cin >> texto;
                                buscar(bibliotecarios, numBibliotecarios, texto);
                                break;
                            }
                            case 'x':
                                // Volver atrás
                                break;
                            default:
                                cout << "Opcion invalida." << endl;
                        }
                    } while (tolower(subOpcion) != 'x');
                } else {
                    cout << "Primero debe generar los datos (Opcion 1)." << endl;
                }
                break;
            case 0:
                // Salir
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida." << endl;
        }
        clearScreen();
    } while (opcion != 0);

    delete[] libros;
    delete[] usuarios;
    delete[] bibliotecarios;

    return 0;
}
