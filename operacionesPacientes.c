#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operacionesPacientes.h"

int comprobarTurno(struct pacientes pacientes[100], int numPac, int turno);

void mostrarMenuPacientes(){
    printf("        MENU DE PACIENTES");
    printf("\n  Introduce la opcion que desee realizar:\n");
    printf("  1- Agendar nueva cita\n");
    printf("  2- Cancelar cita\n");
    printf("  3- Lista de la citas\n");
    printf("  4- Buscar datos de la cita\n");
    printf("  5- Modificar hora de la cita\n");
    printf("  6- Modificar fecha de la cita\n");
    printf("  7- Modificar numero de contacto\n");
    printf("  8- Salir\n");
}

void listaPacientes(struct pacientes pacientes[100], int numPac){
    printf("        Lista de las citas: \n");
    for (int i=0; i<numPac; i++){
        printf("-----------------------------------------------");
        printf("\n  Nombre: %s\n", pacientes[i].nombre);
        printf("  Turno del paciente: %d\n", pacientes[i].turno);
        printf("  Cedula: %d\n", pacientes[i].cedula);
        printf("  Horario de la cita: %.2f\n",pacientes[i].horas);
        printf("  Fecha de la cita: %d/%d/%d\n",pacientes[i].dia, pacientes[i].mes, pacientes[i].año);
        printf("  Numero de contacto: %d\n",pacientes[i].nContacto);
        printf("-----------------------------------------------");
        printf("\n");
    }
}

int altaPacientes(struct pacientes pacientes[100], int numPac){
    int creado = 0;
    struct pacientes pac;

    fflush(stdin);
    printf("  Introduce nombre y apellidos del paciente\n");
    gets(pac.nombre);

    printf("  Introduce numero de cita del paciente\n");
    scanf("  %d",&pac.turno);

    printf("Introduce la cedula\n");
    scanf("  %d",&pac.cedula);

    printf("  Introduce hora de la cita (punto para separar los minutos de las horas)\n");
    scanf("  %f",&pac.horas);
    
    printf("  Introduce la dia de la cita\n");
    scanf("  %d,",&pac.dia);

    printf("  Introduce la mes de la cita\n");
    scanf("  %d,",&pac.mes);

    printf("  Introduce la año de la cita\n");
    scanf("  %d,",&pac.año);

    printf("  Introduce el numero de telefono\n");
    scanf("  %d,",&pac.nContacto);
    
    int existe = comprobarTurno(pacientes,numPac,pac.turno);

    if (numPac < 100){
        if(existe == 0){
            pacientes[numPac] = pac;
            creado = 1;
        }
        else{
            printf("  No se puede crear nueva cita. Turno duplicado\n");
        }
    }
    else{
        printf("  No se puede dar mas turnos. Cupo alcanzado");
    }

    return creado;

}

int eliminarCita(struct pacientes pacientes[100], int numPac){
    int eliminado = 0;
    int turno, indice;

    printf("  Introduce el turno de la cita a eliminar\n");
    scanf("  %d",&turno);

    int existe = comprobarTurno(pacientes,numPac,turno);

    if (existe == 1){
        for (int i=0; i<numPac; i++){
            if (pacientes[i].turno == turno){
                indice = i;
            }
        }

        for (int j=indice; j<numPac-1; j++){
            pacientes[j] = pacientes[j+1];
            struct pacientes aux;
            pacientes[j+1] = aux;
        }
        eliminado = 1;
        printf("  Eliminado con exito\n");
    }
    else{
        printf("  No se puede eliminar la cita. Turno no existente\n");
    }

    return eliminado;

}

void consultarDatosPaciente(struct pacientes pacientes[100], int numPac){
    int turno;
    printf("  Introduce turno de la cita de la que quieres los datos\n");
    scanf("  %d",&turno);

    int existe = comprobarTurno(pacientes,numPac,turno);
    if (existe == 1){
        for (int i=0; i<numPac; i++){
            if (pacientes[i].turno == turno){
                printf("  Listando datos del paciente con turno: %d\n", pacientes[i].turno);
                printf("  Nombre: %s\n",pacientes[i].nombre);
                printf("  Cedula: %d\n", pacientes[i].cedula);
                printf("  Hora de la cita: %.2f\n",pacientes[i].horas);
                printf("  Fecha de la cita: %d/%d/%d",pacientes[i].dia,pacientes[i].mes,pacientes[i].año);
                printf("  Numero de contacto: %d\n",pacientes[i].nContacto);
            }
        }
    }
    else{
        printf("  No se puede consultar los datos del paciente. Turno no existente\n");
    }

}

void modificarHora(struct pacientes pacientes[100], int numPac){

    int turno;

    printf("  Introduce el turno del paciente cuyo horario quieres modificar\n");
    scanf("  %d",&turno);

    int existe = comprobarTurno(pacientes,numPac,turno);

    if (existe == 1){
        float nuevohorario;
        printf("  Introduce el nuevo horario del turno del paciente(separar minutos con horas con un punto)\n");
        scanf("  %f",&nuevohorario);
        for(int i=0; i<numPac; i++){
            if (pacientes[i].turno == turno){
                pacientes[i].horas = nuevohorario;
                printf("  Horario actualizado\n");
            }
        }
    }
    else{
        printf("  No se puede modificar el horario del paciente. Turno no existente\n");
    }
}

void modificarFecha(struct pacientes pacientes[100], int numPac){

    int turno;

    printf("  Introduce el numero de turno cuya fecha quieres modificar\n");
    scanf("  %d",&turno);

    int existe = comprobarTurno(pacientes,numPac,turno);

    if (existe == 1){
        int nuevodia;
        int nuevomes;
        int nuevoaño;
        printf("  Introduce la nuevo dia de la nueva cita del paciente\n");
        scanf("  %d",&nuevodia);
        printf("  Introduce la nuevo mes de la nueva cita del paciente\n");
        scanf("  %d",&nuevomes);
        printf("  Introduce la nuevo año de la nueva cita del paciente\n");
        scanf("  %d",&nuevoaño);

        for(int i=0; i<numPac; i++){
            if (pacientes[i].turno == turno){
                pacientes[i].dia = nuevodia;
                pacientes[i].mes = nuevomes;
                pacientes[i].año = nuevoaño;
                printf("  Fecha actualizada\n");
            }
        }

    }
    else{
        printf("  No se pueden modificar la fecha del paciente. Turno no existente\n");
    }
}

void modificarNcontacto(struct pacientes pacientes[100], int numPac){

    int turno;

    printf("  Introduce el turno del paciente cuyo numero de contacto quieres modificar\n");
    scanf("  %d",&turno);

    int existe = comprobarTurno(pacientes,numPac,turno);

    if (existe == 1){
        int nuevocontacto;
        printf("  Introduce el nuevo numero de contacto del turno del paciente\n");
        scanf("  %d",&nuevocontacto);
        for(int i=0; i<numPac; i++){
            if (pacientes[i].turno == turno){
                pacientes[i].nContacto = nuevocontacto;
                printf("  Horario actualizado\n");
            }
        }
    }
    else{
        printf("  No se puede modificar el horario del paciente. Turno no existente\n");
    }
}
int comprobarTurno(struct pacientes pacientes[100], int numPac, int turno){

    int resultado = 0;

    for (int i=0; i<numPac; i++){
        if (pacientes[i].turno == turno){
            resultado = 1;
        }
    }

    return resultado;

}


