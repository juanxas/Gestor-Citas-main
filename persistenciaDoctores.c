#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operacionesDoctores.h"


int cargar_Doctores(struct doctor doctores[100]){
    int n_doc = 0;  
    FILE *f;
    f = fopen("Doctores.txt","r");
    char cadena[255];
    char delimitador[] = " ;";

    while (feof(f) == 0){

        struct doctor d;
        fgets(cadena,255,f);
        char *token = strtok(cadena, delimitador);

        if(token != NULL){
            int campo = 1;
            while (token != NULL){
                if (campo == 1){
                    strcpy(d.nombre,token);
                }
                else if(campo == 2){
                    d.id = atoi(token);
                }
                else if(campo == 3){
                    d.cedula = atoi(token);
                }
                else if(campo == 3){
                    d.celular == atoi(token);
                }else if(campo == 5){
                    strcpy(d.horas,token);
                }
                campo++;
                token = strtok(NULL, delimitador);
            }
        }
        doctores[n_doc] = d;
        n_doc++;

    }
    fclose(f);
    return n_doc;
}

void guardarDoctores(struct doctor doctores[100], int num_doctores){
    FILE *f;
    f = fopen("Doctores.txt","w");

    for (int i=0; i < num_doctores -1; i++){
        fprintf(f, "%s;%d;%d;%d;%s\n", doctores[i].nombre, doctores[i].id, doctores[i].cedula, doctores[i].celular, doctores[i].horas);
    }
    fprintf(f, "%s;%d;%d;%d;%s", doctores[num_doctores-1].nombre, doctores[num_doctores-1].id, doctores[num_doctores-1].cedula, doctores[num_doctores-1].celular, doctores[num_doctores-1].horas);

    fclose(f);
}
