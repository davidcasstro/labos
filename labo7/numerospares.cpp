#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<int> leerArchivo(const string &nombreArchivo) {
    ifstream archivo(nombreArchivo);
    vector<int> numeros;
    int num;

    if (!archivo) {
        cout << "No se pudo abrir el archivo: " << nombreArchivo << endl;
        return numeros;
    }

    while (archivo >> num) {
        numeros.push_back(num);
    }

    return numeros;
}

void clasificarNumeros(const string &entrada, const string &pares, const string &impares) {
    vector<int> nums = leerArchivo(entrada);

    ofstream filePares(pares);
    ofstream fileImpares(impares);

    for (int n : nums) {
        if (n % 2 == 0)
            filePares << n << endl;
        else
            fileImpares << n << endl;
    }

    cout << "Clasificación completada.\n";
}

void ordenarArchivo(const string &nombreArchivo) {
    vector<int> nums = leerArchivo(nombreArchivo);

    
    for (int i = 0; i < nums.size() - 1; i++) {
        for (int j = 0; j < nums.size() - i - 1; j++) {
            if (nums[j] > nums[j + 1]) {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }

   
    ofstream archivo(nombreArchivo);
    for (int n : nums)
        archivo << n << endl;

    cout << "Archivo " << nombreArchivo << " ordenado correctamente.\n";
}


void mostrarArchivo(const string &nombreArchivo) {
    ifstream archivo(nombreArchivo);
    int num;

    if (!archivo) {
        cout << "No se pudo abrir el archivo: " << nombreArchivo << endl;
        return;
    }

    cout << "\nContenido de " << nombreArchivo << ":\n";
    while (archivo >> num)
        cout << num << " ";
    cout << "\n\n";
}

int main() {
    string original = "datos.txt";
    string pares = "pares.txt";
    string impares = "impares.txt";

    int opcion;

    do {
        cout << "========== MENU ==========\n";
        cout << "1. Clasificar numeros\n";
        cout << "2. Ordenar archivos (pares e impares)\n";
        cout << "3. Ver resultados\n";
        cout << "4. Salir\n";
        cout << "Elige una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                clasificarNumeros(original, pares, impares);
                break;

            case 2:
                ordenarArchivo(pares);
                ordenarArchivo(impares);
                break;

            case 3:
                mostrarArchivo(original);
                mostrarArchivo(pares);
                mostrarArchivo(impares);
                break;

            case 4:
                cout << "Saliendo...\n";
                break;

            default:
                cout << "Opción inválida.\n";
                break;
        }

    } while (opcion != 4);

    return 0;
}
