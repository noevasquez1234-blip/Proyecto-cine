#include "Controlador_admin.h"
#include "Vista_mapa.h"
#include "Modelos_de_sala.h"
#include "Reporte_finan.h"
#include "Validaciones.h"
#include <iostream>

using namespace std;

void ejecutarSesionAdmin() {
    int opcion = 0;

    while (opcion != 4) {
        cout << "\n--- PANEL DE ADMINISTRADOR ---" << endl;
        cout << "1. Mostrar mapa completo de la sala" << endl;
        cout << "2. Generar informe general de ventas" << endl;
        cout << "3. Cancelar reserva o liberar asiento pagado" << endl;
        cout << "4. Regresar al menu principal" << endl;
        cout << "Seleccione una opcion: ";
        opcion = leerEnteroSeguro();

        if (opcion == 1) {
            renderizarMapaVisual();
        }
        else if (opcion == 2) {
            imprimirReporteGeneral();
        }
        else if (opcion == 3) {
            renderizarMapaVisual();
            cout << "Ingrese el numero de butaca a LIBERAR (1 al 20): ";
            int num = leerEnteroSeguro();

            if (num < 1 || num > 20) {
                cout << " Error: Numero de asiento fuera de rango." << endl;
            } else if (obtenerEstadoAsiento(num) != 0) {
                cambiarEstadoAsiento(num, 0); // Regresa a estado Libre (0)
                cout << " Butaca " << num << " liberada con exito." << endl;
            } else {
                cout << " Error: La butaca ya esta libre." << endl;
            }
        }
        else if (opcion == 4) {
            cout << "Cerrando modulo administrativo..." << endl;
        }
        else {
            cout << " Opcion invalida." << endl;
        }
    }
}