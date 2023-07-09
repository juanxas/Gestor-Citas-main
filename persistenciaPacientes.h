#ifndef PERSISTENCIAPACIENTES_H_INCLUDED
#define PERSISTENCIAPACIENTES_H_INCLUDED
#include "operacionesPacientes.h"

int cargarPacientes(struct pacientes pacientes[100]);
void guardarPacientes(struct pacientes pacientes[100], int num_pac);

#endif // PERSISTENCIA_H_INCLUDED
