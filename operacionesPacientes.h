#ifndef OPERACIONESPACIENTES_H_INCLUDED
#define OPERACIONESPACIENTES_H_INCLUDED

struct pacientes{
    char nombre[255];
    int turno;
    int cedula;
    float horas;
    int dia;
    int mes;
    int año;
    int nContacto;
};

void mostrarMenuPacientes();
void listaPacientes(struct pacientes pacientes[100], int numPac);
int altaPacientes(struct pacientes pacientes[100], int numPac);
int eliminarCita(struct pacientes pacientes[100], int numPac);
void consultarDatosPaciente(struct pacientes pacientes[100], int numPac);
void modificarHora(struct pacientes pacientes[100], int numPac);
void modificarFecha(struct pacientes pacientes[100], int numPac);
void modificarNcontacto(struct pacientes pacientes[100], int numPac);

#endif // OPERACIONES_H_INCLUDED
