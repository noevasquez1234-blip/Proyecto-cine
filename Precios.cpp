#include "Precios.h"

std::string obtenerNombreZona(int fila) {
    if (fila < 2) return "VIP";
    return "Estandar";
}

double obtenerPrecioFila(int fila) {
    if (fila < 2) return PRECIO_VIP;
    return PRECIO_ESTANDAR;
}