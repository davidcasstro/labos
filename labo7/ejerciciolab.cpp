#include <iostream>
#include <string>
using namespace std;

const int NUM_CALIFICACIONES = 5;


struct Direccion {
    string calle;
    int numero;
    string ciudad;
};

struct Estudiante {
    string nombre;
    int edad;
    float calificaciones[NUM_CALIFICACIONES];
    Direccion direccion;
};

void ingresarEstudiantes(Estudiante *&estudiantes, int &cantidad);
void mostrarEstudiantes(Estudiante *estudiantes, int cantidad);
void buscarEstudiante(Estudiante *estudiantes, int cantidad);
void modificarEstudiante(Estudiante *estudiantes, int cantidad);

int main() {
    Estudiante *estudiantes = nullptr;
    int cantidad = 0;
    int opcion;

    do {
        cout << "\n===== MENU DE GESTION DE ESTUDIANTES =====\n";
        cout << "1. Ingresar estudiantes\n";
        cout << "2. Mostrar estudiantes\n";
        cout << "3. Buscar estudiante\n";
        cout << "4. Modificar estudiante\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                ingresarEstudiantes(estudiantes, cantidad);
                break;
            case 2:
                mostrarEstudiantes(estudiantes, cantidad);
                break;
            case 3:
                buscarEstudiante(estudiantes, cantidad);
                break;
            case 4:
                modificarEstudiante(estudiantes, cantidad);
                break;
            case 5:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opcion invalida, intente nuevamente.\n";
        }
    } while (opcion != 5);

    delete[] estudiantes; 
    return 0;
}


void ingresarEstudiantes(Estudiante *&estudiantes, int &cantidad) {
    int n;
    cout << "Ingrese el numero de estudiantes a registrar: ";
    cin >> n;

    Estudiante *nuevoArray = new Estudiante[cantidad + n]; 

    
    for (int i = 0; i < cantidad; i++) {
        nuevoArray[i] = estudiantes[i];
    }

    
    for (int i = cantidad; i < cantidad + n; i++) {
        cout << "\n--- Estudiante " << i + 1 << " ---\n";
        cin.ignore();
        cout << "Nombre: ";
        getline(cin, nuevoArray[i].nombre);

        cout << "Edad: ";
        cin >> nuevoArray[i].edad;

        cout << "Ingrese las " << NUM_CALIFICACIONES << " calificaciones:\n";
        for (int j = 0; j < NUM_CALIFICACIONES; j++) {
            cout << "Calificacion " << j + 1 << ": ";
            cin >> nuevoArray[i].calificaciones[j];
        }

        cin.ignore();
        cout << "Calle: ";
        getline(cin, nuevoArray[i].direccion.calle);
        cout << "Numero: ";
        cin >> nuevoArray[i].direccion.numero;
        cin.ignore();
        cout << "Ciudad: ";
        getline(cin, nuevoArray[i].direccion.ciudad);
    }

    delete[] estudiantes; 
    estudiantes = nuevoArray;
    cantidad += n;

    cout << "\n✅ " << n << " estudiante(s) registrado(s) correctamente.\n";
}

void mostrarEstudiantes(Estudiante *estudiantes, int cantidad) {
    if (cantidad == 0) {
        cout << "No hay estudiantes registrados.\n";
        return;
    }

    cout << "\n--- LISTA DE ESTUDIANTES ---\n";
    for (int i = 0; i < cantidad; i++) {
        cout << "\nEstudiante " << i + 1 << ":\n";
        cout << "Nombre: " << estudiantes[i].nombre << endl;
        cout << "Edad: " << estudiantes[i].edad << endl;
        cout << "Calificaciones: ";
        for (int j = 0; j < NUM_CALIFICACIONES; j++) {
            cout << estudiantes[i].calificaciones[j] << " ";
        }
        cout << "\nDireccion: " << estudiantes[i].direccion.calle << " #" 
             << estudiantes[i].direccion.numero << ", " 
             << estudiantes[i].direccion.ciudad << endl;
    }
}

void buscarEstudiante(Estudiante *estudiantes, int cantidad) {
    if (cantidad == 0) {
        cout << "No hay estudiantes registrados.\n";
        return;
    }

    string nombre;
    cin.ignore();
    cout << "Ingrese el nombre del estudiante a buscar: ";
    getline(cin, nombre);

    for (int i = 0; i < cantidad; i++) {
        if (estudiantes[i].nombre == nombre) {
            cout << "\n--- Estudiante encontrado ---\n";
            cout << "Nombre: " << estudiantes[i].nombre << endl;
            cout << "Edad: " << estudiantes[i].edad << endl;
            cout << "Calificaciones: ";
            for (int j = 0; j < NUM_CALIFICACIONES; j++) {
                cout << estudiantes[i].calificaciones[j] << " ";
            }
            cout << "\nDireccion: " << estudiantes[i].direccion.calle << " #" 
                 << estudiantes[i].direccion.numero << ", " 
                 << estudiantes[i].direccion.ciudad << endl;
            return;
        }
    }

    cout << "❌ Estudiante no encontrado.\n";
}

void modificarEstudiante(Estudiante *estudiantes, int cantidad) {
    if (cantidad == 0) {
        cout << "No hay estudiantes registrados.\n";
        return;
    }

    string nombre;
    cin.ignore();
    cout << "Ingrese el nombre del estudiante a modificar: ";
    getline(cin, nombre);

    for (int i = 0; i < cantidad; i++) {
        if (estudiantes[i].nombre == nombre) {
            cout << "\n--- Modificando datos de " << estudiantes[i].nombre << " ---\n";
            cout << "Nueva edad: ";
            cin >> estudiantes[i].edad;

            cout << "Nuevas calificaciones:\n";
            for (int j = 0; j < NUM_CALIFICACIONES; j++) {
                cout << "Calificacion " << j + 1 << ": ";
                cin >> estudiantes[i].calificaciones[j];
            }

            cin.ignore();
            cout << "Nueva calle: ";
            getline(cin, estudiantes[i].direccion.calle);
            cout << "Nuevo numero: ";
            cin >> estudiantes[i].direccion.numero;
            cin.ignore();
            cout << "Nueva ciudad: ";
            getline(cin, estudiantes[i].direccion.ciudad);

            cout << "✅ Datos actualizados correctamente.\n";
            return;
        }
    }

    cout << "❌ Estudiante no encontrado.\n";
}
