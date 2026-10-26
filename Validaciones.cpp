#include "Validaciones.h"
#include <iostream>
#include <limits>

using namespace std;

int leerEnteroSeguro(const char* mensajeError) {
    int valor;
    while (!(cin >> valor)) {
        cin.clear(); // Limpia la bandera de error de cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta el texto invalido introducido
        cout << mensajeError;
    }
    return valor;
}