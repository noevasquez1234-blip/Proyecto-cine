#include "Reporte_finan.h"
#include "Modelos_de_sala.h"
#include "Precios.h"
#include <iostream>
#include <iomanip>

#include "Modelos_de_sala.h"

using namespace std;

int contarDisponiblesGlobal() {
    int libres = 0;
    for (int f = 0; f < 5; f++) {
        for (int c = 0; c < 4; c++) {
            if (salaCine[f][c] == 0) libres++;
        }
    }
    return libres;
}

double calcularTotalRecaudado() {
    double total = 0.0;
    for (int f = 0; f < 5; f++) {
        for (int c = 0; c < 4; c++) {
            if (salaCine[f][c] == 2) { // Únicamente las butacas PAGADAS acumulan ingresos
                total += obtenerPrecioFila(f);
            }
        }
    }
    return total;
}

void imprimirReporteGeneral() {
    int libres = contarDisponiblesGlobal();
    int ocupados = 20 - libres;
    double recaudado = calcularTotalRecaudado();

    cout << "\n----------------------------------------" << endl;
    cout << "     INFORME AUDITADO DE VENTAS         " << endl;
    cout << "----------------------------------------" << endl;
    cout << "• Asientos disponibles: " << libres << " / 20" << endl;
    cout << "• Asientos comprometidos (Res/Pag): " << ocupados << " / 20" << endl;
    cout << "• Recaudacion liquida (Pagados): $" << fixed << setprecision(2) << recaudado << endl;
    cout << "----------------------------------------\n" << endl;
}