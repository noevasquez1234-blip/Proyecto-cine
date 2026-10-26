#ifndef PRECIOS_H
#define PRECIOS_H

#include <string>

const double PRECIO_VIP = 50.00; //Q.50.00    // Filas 0 y 1 (Variante B)
const double PRECIO_ESTANDAR = 35.00; //Q.35.00 // Filas 2, 3 y 4 (Variante B)

std::string obtenerNombreZona(int fila);
double obtenerPrecioFila(int fila);

#endif