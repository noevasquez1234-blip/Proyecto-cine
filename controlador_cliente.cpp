#include "controlador_cliente.h"
#include "Vista_mapa.h"
#include "Modelos_de_sala.h"
#include "Precios.h"
#include "Validaciones.h"
#include <iostream>
#include <iomanip>

using namespace std;

void ejecutarSesionCliente() {
    int opcion = 0;

    while (opcion != 4) {
        cout << "\n--- PANEL DE CLIENTE ---" << endl;
        cout << "1. Ver mapa de la sala" << endl;
        cout << "2. Reservar butaca" << endl;
        cout << "3. Pagar butaca" << endl;
        cout << "4. Regresar al menu principal" << endl;
        cout << "Seleccione una opcion: ";
        opcion = leerEnteroSeguro();

        if (opcion == 1) {
            renderizarMapaVisual();
        }
        else if (opcion == 2) {
            renderizarMapaVisual();
            cout << "Ingrese el numero de butaca a reservar (1 al 20): ";
            int num = leerEnteroSeguro();

            if (num < 1 || num > 20) {
                cout << " Error: Asiento invalido. Debe ser un numero entre 1 y 20." << endl;
            } else if (estaDisponible(num)) {
                cambiarEstadoAsiento(num, 1); // Estado 1 = Reservado
                cout << " Butaca " << num << " reservada correctamente." << endl;
            } else {
                cout << " Error: Asiento no disponible." << endl;
            }
        }
        else if (opcion == 3) {
            renderizarMapaVisual();
            cout << "Ingrese el numero de butaca a PAGAR (1 al 20): ";
            int num = leerEnteroSeguro();

            if (num < 1 || num > 20) {
                cout << " Error: Numero de asiento invalido." << endl;
            } else {
                int estado = obtenerEstadoAsiento(num);
                if (estado == 0 || estado == 1) { // Puede pagarse si está Libre o Reservado
                    cambiarEstadoAsiento(num, 2); // Estado 2 = Pagado
                    int fila = (num - 1) / 4;
                    cout << " Transaccion completada. Monto cancelado: $"
                         << fixed << setprecision(2) << obtenerPrecioFila(fila) << endl;
                } else {
                    cout << " Error: La butaca seleccionada ya habia sido pagada." << endl;
                }
            }
        }
        else if (opcion == 4) {
            cout << "Regresando al menu principal..." << endl;
        }
        else {
            cout << " Opcion invalida." << endl;
        }
    }
}