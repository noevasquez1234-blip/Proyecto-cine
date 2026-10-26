#ifndef CONEXIONBD_H
#define CONEXIONBD_H

#define MYSQL_CLIENT  // <- Esto le ordena a MySQL que exponga las funciones de conexión de cliente
#include <winsock2.h>
#include <windows.h>
#include <mysql.h>

class coneccion_bd {
private:
    MYSQL* conector;
public:
    void abrirConexion();
    MYSQL* getConector();
    void cerrarConexion();
};

#endif