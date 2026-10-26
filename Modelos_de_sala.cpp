#include "Modelos_de_sala.h"

int salaCine[5][4] = {0};

void inicializarSala() {
    for (int f = 0; f < 5; f++) {
        for (int c = 0; c < 4; c++) {
            salaCine[f][c] = 0;
        }
    }
}

bool estaDisponible(int numeroAsiento) {
    int indice = numeroAsiento - 1;
    int f = indice / 4;
    int c = indice % 4;
    return (salaCine[f][c] == 0);
}

bool cambiarEstadoAsiento(int numeroAsiento, int nuevoEstado) {
    if (numeroAsiento < 1 || numeroAsiento > 20) return false;
    int indice = numeroAsiento - 1;
    int f = indice / 4;
    int c = indice % 4;
    salaCine[f][c] = nuevoEstado;
    return true;
}

int obtenerEstadoAsiento(int numeroAsiento) {
    int indice = numeroAsiento - 1;
    int f = indice / 4;
    int c = indice % 4;
    return salaCine[f][c];
}