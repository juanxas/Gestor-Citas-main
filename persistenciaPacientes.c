#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operacionesPacientes.h"


int cargarPacientes(struct pacientes pacientes[100]){
    int n_pac = 0;
    FILE *f;
    f = fopen("pacientes.txt","r");
    char cadena[255];
    char delimitador[] = ";";

    while (feof(f) == 0){

        struct pacientes e;
        fgets(cadena,255,f);
        char *token = strtok(cadena,delimitador);

        if(token != NULL){
            int campo = 1;
            while (token != NULL){
                if (campo == 1){
                    strcpy(e.nombre,token);
                }
                else if(campo == 2){
                    e.turno = atoi(token);
                }
                else if(campo == 3){
                    e.cedula = atoi(token);
                }
                else if(campo == 4){
                    e.horas = atof(token);
                }
                else if(campo == 5){
                    e.dia = atoi(token);
                }
                else if(campo == 6){
                    e.mes = atoi(token);
                }
                else if(campo == 7){
                    e.año = atoi(token);
                }
                else if(campo == 8){
                    e.nContacto = atoi(token);
                }
                campo++;
                token = strtok(NULL, delimitador);
            }
        }
        pacientes[n_pac] = e;
        n_pac++;

    }
    fclose(f);
    return n_pac;
}

void guardarPacientes(struct pacientes pacientes[100], int num_pac){
    FILE *f;
    f = fopen("pacientes.txt","w");

    for (int i=0; i<num_pac-1; i++){
        fprintf(f, "%s;%d;%d;%f;%d;%d;%d;%d \n",pacientes[i].nombre,pacientes[i].turno,pacientes[i].cedula,pacientes[i].horas,pacientes[i].dia,pacientes[i].mes,pacientes[i].año, pacientes[i].nContacto);
    }
    fprintf(f, "%s;%d;%d;%f;%d;%d;%d;%d",pacientes[num_pac-1].nombre,pacientes[num_pac-1].turno,pacientes[num_pac-1].cedula,pacientes[num_pac-1].horas,pacientes[num_pac-1].dia,pacientes[num_pac-1].mes,pacientes[num_pac-1].año,pacientes[num_pac-1].nContacto);

    fclose(f);
}
