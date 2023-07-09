#ifndef PERSISTENCIADOCTORES_H_INCLUDED
#define PERSISTENCIADOCTORES_H_INCLUDED
#include "operacionesDoctores.h"

int cargar_Doctores(struct doctor doctores[100]);
void guardarDoctores(struct doctor doctores[100], int num_doctores);

#endif
