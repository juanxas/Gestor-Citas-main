#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operacionesDoctores.h"

int comprobarID(struct doctor doctores[100], int num_doctores, int id);

void mostrarMenu(){
    printf("        MENU DE DOCTORES\n");
    printf("\n  Introduce la opcion que desee realizar:\n");
    printf("  1- Alta Doctor\n");
    printf("  2- Baja Doctor\n");
    printf("  3- Listar Doctores\n");
    printf("  4- Consultar Datos de Doctor\n");
    printf("  5- Modificar Cedula\n");
    printf("  6- Modificar N.Celular\n");
    printf("  7- Modificar Horario\n");
    printf("  8- Salir\n");
}

void listar_Doctores(struct doctor doctores[100], int num_doctores){
    printf("  Listando los datos de los doctores: \n");
    for (int i=0; i < num_doctores; i++){
        printf("  Nombre: %s\n", doctores[i].nombre);
        printf("  ID del Doctor: %d\n", doctores[i].id);
        printf("  Cedula: %d\n", doctores[i].cedula);
        printf("  N.Celular: %d\n", doctores[i].celular);
        printf("  Horario: %s\n", doctores[i].horas);
        printf("\n");
    }
}

int altaDoctores(struct doctor doctores[100], int num_doctores){
    int creado = 0;
    struct doctor doc;

    fflush(stdin);
    printf("  Introduce nombre y apellidos\n");
    gets(doc.nombre);

    printf("  Introduce ID del Doctor\n");
    scanf("  %d",&doc.id);

    printf("  Introduce la Cedula\n");
    scanf("  %d",&doc.cedula);

    printf("  Introduce el N.Celular\n");
    scanf("  %d",&doc.celular);

    fflush(stdin);
    printf("  Introduce el horario (Ex: Lun-Vie/00:00-00:00)\n");
    gets(doc.horas);

    int existe = comprobarID(doctores, num_doctores, doc.id);

    if (num_doctores < 100){
        if(existe == 0){
            doctores[num_doctores] = doc;
            creado = 1;
        }
        else{
            printf("  No se puede crear Doctor. ID duplicado\n");
        }
    }
    else{
        printf("  No se puede dar de alta al Doctor. Cupo alcanzado");
    }

    return creado;

}

int bajaDoctores(struct doctor doctores[100], int num_doctores){
    int eliminado = 0;
    int id, indice;

    printf("  Introduce el ID del Doctor a dar de baja\n");
    scanf("  %d", &id);

    int existe = comprobarID(doctores, num_doctores, id);

    if (existe == 1){
        for (int i=0; i < num_doctores; i++){
            if (doctores[i].id == id){
                indice = i;
            }
        }

        for (int j=indice; j< num_doctores -1; j++){
            doctores[j] = doctores[j+1];
            struct doctor aux;
            doctores[j+1] = aux;
        }
        eliminado = 1;
    }
    else{
        printf("  No se puede dar de baja al Doctor. ID no existe\n");
    }

    return eliminado;

}

void consultar_Datos_Doctor(struct doctor doctores[100], int num_doctores){
    int id;
    printf("  Introduce el ID del Doctor cuyos datos quieres consultar\n");
    scanf("  %d", &id);

    int existe = comprobarID(doctores, num_doctores, id);
    if (existe == 1){
        for (int i=0; i< num_doctores; i++){
            if (doctores[i].id == id){
                printf("  Listando datos del Doctor con ID: %d\n", doctores[i].id);
                printf("  Nombre: %s\n", doctores[i].nombre);
                printf("  Cedula: %d\n", doctores[i].cedula);
                printf("  N.Celular: %d\n", doctores[i].celular);
                printf("  Horario: %s\n", doctores[i].horas);

            }
        }
    }
    else{
        printf("  No se puede consultar los datos del Doctor. ID no existe\n");
    }

}

void modificar_Cedula(struct doctor doctores[100], int num_doctores){

    int id;

    printf("  Introduce el ID del Doctor cuya Cedula quieres modificar\n");
    scanf("  %d", &id);

    int existe = comprobarID(doctores, num_doctores, id);

    if (existe == 1){
        float nuevo_doctor;
        
        printf("  Introduce la nueva Cedula del Doctor\n");
        scanf("  %f", &nuevo_doctor);
        for(int i=0; i < num_doctores; i++){
            if (doctores[i].id == id){
                doctores[i].cedula = nuevo_doctor;
                printf("  Cedula actualizada\n");
            }
        }
    }
    else{
        printf("  No se puede modificar la Cedula del Doctor. ID no existe\n");
    }
}

void modificar_Celular(struct doctor doctores[100], int num_doctores){

    int id;

    printf("  Introduce el ID del Doctor cuyo N.Celular quieres modificar\n");
    scanf("  %d", &id);

    int existe = comprobarID(doctores, num_doctores, id);

    if (existe == 1){
        float nuevo_doctor;
        
        printf("  Introduce el nuevo N.Celular del Doctor\n");
        scanf("  %f", &nuevo_doctor);
        for(int i=0; i < num_doctores; i++){
            if (doctores[i].id == id){
                doctores[i].celular = nuevo_doctor;
                printf("  N.Celular actualizado\n");
            }
        }
    }
    else{
        printf("No se puede modificar el N.Celular del Doctor. ID no existe\n");
    }
}

void modificar_Horario(struct doctor doctores[100], int num_doctores){

    int id;

    printf("  Introduce el ID del Doctor cuyo horario quieres modificar\n");
    scanf("  %d",&id);

    int existe = comprobarID(doctores, num_doctores, id);

    if (existe == 1){
        char nuevas_horas[50];
        fflush(stdin);
        printf("  Introduce el nuevo horario del Doctor (Ex: Lun-Vie/00:00-00:00)\n");
        gets(nuevas_horas);
        
        for (int i = 0; i < num_doctores; i++) {
            if (doctores[i].id == id) {
                if (strlen(nuevas_horas) == strlen(doctores[i].horas) && strcmp(nuevas_horas, doctores[i].horas) == 0) {
                    printf("  El horario ya está actualizado\n");
                } else {
                    strcpy(doctores[i].horas, nuevas_horas);
                    printf("  Horario actualizado\n");
                }
            }
        }
        
    } else{
        printf("  No se puede modificar el horario del Doctor. ID no existe\n");
    }
}

int comprobarID(struct doctor doctores[100], int num_doctores, int id){

    int resultado = 0;

    for (int i=0; i < num_doctores; i++){
        if (doctores[i].id == id){
            resultado = 1;
        }
    }

    return resultado;

}
