#ifndef OPERACIONESDOCTORES_H_INCLUDED
#define OPERACIONESDOCTORES_H_INCLUDED

struct doctor{
    char nombre[255];
    int id;
    int cedula;
    int celular;
    char horas[50];
};

void mostrarMenu();
void listar_Doctores(struct doctor doctores[100], int num_doctores);
int altaDoctores(struct doctor doctores[100], int num_doctores);
int bajaDoctores(struct doctor doctores[100], int num_doctores);
void consultar_Datos_Doctor(struct doctor doctores[100], int num_doctores);
void modificar_Cedula(struct doctor doctores[100], int num_doctores);
void modificar_Celular(struct doctor doctores[100], int num_doctores);
void modificar_Horario(struct doctor doctores[100], int num_doctores);

#endif
