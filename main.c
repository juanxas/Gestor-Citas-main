#include <stdio.h>
#include <stdlib.h>
#include "operacionesPacientes.h"
#include "persistenciaPacientes.h"
#include "operacionesDoctores.h"
#include "persistenciaDoctores.h"


int main()
{
    int opcion = 0;
    int opc = 0;
    int opc2 = 0;
    int numPac = 0;
    int num_doctores = 0;
    

    struct doctor doctores[100];
    struct pacientes pacientes[100];

    //numPac = cargarPacientes(pacientes);
    
    printf("    BIENVENIDO AL GESTOR DE CITAS MEDICAS\n");
    do{
        printf("       MENU GENERAL\n");
        printf("\n  Introduce la opcion que desee realizar:\n");
        printf("  1- Pacientes\n");
        printf("  2- Doctores\n");
        printf("  3- Creditos\n");
        printf("  4- Salir\n");
        scanf("  %d", &opc);
        system("cls");
        switch (opc){
        case 1:
            numPac = cargarPacientes(pacientes);
            
            while(opcion != 8){
            mostrarMenuPacientes();
            scanf("%d",&opcion);
            system("cls");
            if(opcion == 1){
            int creado = altaPacientes(pacientes,numPac);
            if (creado == 1){
                numPac++;
            }
            system("pause");
            }
            else if(opcion == 2){
            int eliminado = eliminarCita(pacientes,numPac);
            if (eliminado == 1){
                numPac--;
            }
            system("pause");
            }
            else if(opcion == 3){
            listaPacientes(pacientes,numPac);
            system("pause");
            }
            else if(opcion == 4){
            consultarDatosPaciente(pacientes,numPac);
            system("pause");
            }
            else if(opcion ==5){     
            modificarHora(pacientes,numPac);
            system("pause");
            }
            else if(opcion == 6){
            modificarFecha(pacientes,numPac);
            system("pause");
            }
            else if(opcion == 7){
            modificarNcontacto(pacientes,numPac);
            system("pause");
            }
            else if(opcion > 8 || opcion < 1){
            printf("  Por favor solo opciones entre 1-7");
            system("pause");
            }
            system("cls");
            }
            guardarPacientes(pacientes,numPac);
            break;
        case 2:
            num_doctores = cargar_Doctores(doctores);

            while(opc2 != 8){
            mostrarMenu();
            scanf("  %d",&opc2);
            system("cls");
            if(opc2 == 1){
                int creado = altaDoctores(doctores, num_doctores);
                if (creado == 1){
                    num_doctores++;
                }
                system("pause");
            }
            else if(opc2 == 2){
                int eliminado = bajaDoctores(doctores, num_doctores);
                if (eliminado == 1){
                    num_doctores--;
                }
                system("pause");
            }
            else if(opc2 == 3){
                listar_Doctores(doctores, num_doctores);
                system("pause");
            }
            else if(opc2 == 4){
                consultar_Datos_Doctor(doctores, num_doctores);
                system("pause");
            }
            else if(opc2 == 5){
                modificar_Cedula(doctores, num_doctores);
                system("pause");
            }
            else if(opc2 == 6){
                modificar_Horario(doctores, num_doctores);
                system("pause");
            }
            else if(opc2 == 7){
                modificar_Celular(doctores, num_doctores);
                system("pause");
            }
            else if(opc2 > 8 || opc2 < 1){
                printf("  Por favor solo opciones entre 1-8");
            }
            system("cls");
        }
        guardarDoctores(doctores, num_doctores);
        break;
        case 3:
            printf("Gestor de citas realizado por\nChristopher Cuesta\nSteve Torres\nJuan David Calle");
            system("pause");
            system("cls");
            break;
        case 4:
            printf("    GRACIAS POR USAR EL GESTOR DE CITAS\n\n");
            break;
        default:
            printf("  Opcion invalida");
            break;
        }
    }while (opc != 4 );
    
    // guardarPacientes(pacientes,numPac);
    
    
}
