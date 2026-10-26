#ifndef CINEMODEL_H
#define CINEMODEL_H

extern int salaCine[5][4]; // 0 = Libre, 1 = Reservado, 2 = Pagado

void inicializarSala();
bool estaDisponible(int numeroAsiento);
bool cambiarEstadoAsiento(int numeroAsiento, int nuevoEstado);
int obtenerEstadoAsiento(int numeroAsiento);

#endif
