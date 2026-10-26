#include "Vista_mapa.h"
#include "Modelos_de_sala.h"
#include "Precios.h"
#include <iostream>
#include <iomanip>

using namespace std;

void renderizarMapaVisual() {
    cout << "\n========================================================" << endl;
    cout << "                 P A N T A L L A   C I N E               " << endl;
    cout << "========================================================" << endl;

    int contador = 1;
    for (int f = 0; f < 5; f++) {
        cout << "Fila " << (f + 1) << " (" << setw(8) << left << obtenerNombreZona(f)
             << " Q" << fixed << setprecision(2) << obtenerPrecioFila(f) << "): ";

        for (int c = 0; c < 4; c++) {
            if (salaCine[f][c] == 0) {
                cout << "[ " << setw(2) << contador << " L ] "; // Libre
            } else if (salaCine[f][c] == 1) {
                cout << "[  R   ] "; // Reservado
            } else {
                cout << "[  P   ] "; // Pagado
            }
            contador++;
        }
        cout << endl;
    }
    cout << "========================================================" << endl;
    cout << "Simbologia: [ No. L ] = Libre | [  R   ] = Reservado | [  P   ] = Pagado" << endl;
    cout << "========================================================\n" << endl;
}