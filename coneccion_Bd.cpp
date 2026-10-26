#include "coneccion_Bd.h"
#include <iostream>
#include <windows.h>

// Definición de los tipos de funciones para cargarlas dinámicamente desde la DLL
typedef MYSQL* (__stdcall *pfn_mysql_init)(MYSQL*);
typedef MYSQL* (__stdcall *pfn_mysql_real_connection)(MYSQL*, const char*, const char*, const char*, const char*, unsigned int, const char*, unsigned long);
typedef void (__stdcall *pfn_mysql_close)(MYSQL*);
typedef const char* (__stdcall *pfn_mysql_error)(MYSQL*);

void coneccion_bd::abrirConexion() {
    // Cargar la DLL de MySQL directamente del sistema
    HMODULE hDll = LoadLibrary("libmysql.dll");
    if (!hDll) {
        std::cout << "Error: No se pudo encontrar 'libmysql.dll'. Asegurate de copiarla en la carpeta de compilacion." << std::endl;
        return;
    }

    // Obtener las direcciones de las funciones de la base de datos
    pfn_mysql_init fn_mysql_init = (pfn_mysql_init)GetProcAddress(hDll, "mysql_init");
    pfn_mysql_real_connection fn_mysql_real_connection = (pfn_mysql_real_connection)GetProcAddress(hDll, "mysql_real_connection");
    pfn_mysql_close fn_mysql_close = (pfn_mysql_close)GetProcAddress(hDll, "mysql_close");
    pfn_mysql_error fn_mysql_error = (pfn_mysql_error)GetProcAddress(hDll, "mysql_error");

    if (!fn_mysql_init || !fn_mysql_real_connection) {
        std::cout << "Error al enlazar las funciones internas de la DLL de MySQL." << std::endl;
        FreeLibrary(hDll);
        return;
    }

    conector = fn_mysql_init(NULL);
    if (conector == NULL) {
        std::cout << "Error al inicializar el conector de MySQL." << std::endl;
        FreeLibrary(hDll);
        return;
    }

    // Realizar la conexión con tus credenciales
    conector = fn_mysql_real_connection(conector, "localhost", "root", "Nexuus1234#=fer", "db_cine", 3306, NULL, 0);

    if (conector) {
        std::cout << "¡Conexion exitosa a la base de datos db_cine!" << std::endl;
    } else {
        std::cout << "Error de conexion: " << fn_mysql_error(conector) << std::endl;
    }
}

MYSQL* coneccion_bd::getConector() {
    return conector;
}

void coneccion_bd::cerrarConexion() {
    if (conector) {
        // Buscamos dinámicamente para cerrar de forma segura
        HMODULE hDll = LoadLibrary("libmysql.dll");
        if (hDll) {
            pfn_mysql_close fn_mysql_close = (pfn_mysql_close)GetProcAddress(hDll, "mysql_close");
            if (fn_mysql_close) {
                fn_mysql_close(conector);
            }
            FreeLibrary(hDll);
        }
    }
}