#include <iostream>
#include "Validaciones.h"
#include "controlador_cliente.h"    1
#include "Controlador_admin.h"
#include "Modelos_de_sala.h"

using namespace std;

int main() {
    inicializarSala();
    int rol = 0;

    while (rol != 3) {
        cout << "\n==========================================" << endl;
        cout << "     SISTEMA DE CINE - ACCESO PRINCIPAL" << endl;
        cout << "==========================================" << endl;
        cout << "1. Ingresar como Cliente" << endl;
        cout << "2. Ingresar como Administrador" << endl;
        cout << "3. Salir" << endl;
        cout << "Seleccione el tipo de perfil: ";

        rol = leerEnteroSeguro(); // Captura anti-tontos que impide bucles infinitos con caracteres

        if (rol == 1) {
            ejecutarSesionCliente();
        }
        else if (rol == 2) {
            ejecutarSesionAdmin();
        }
        else if (rol == 3) {
            cout << "Saliendo del programa..." << endl;
        }
        else {
            cout << " Opcion no valida." << endl;
        }
    }

    return 0;
}