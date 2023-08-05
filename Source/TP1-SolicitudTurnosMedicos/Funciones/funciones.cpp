#include "funciones.h"
#include "constantes.h"
#include <stdio.h>
#include "utils.h"
#include <stdlib.h>

void ProcMedicos()
{

} // Descarga archivo Medicos.

void ProcEspecialidad(Especialidad especialidades[])
{
    int cantEspecialidades;
    std::ifstream archivoEspecialidades;
    archivoEspecialidades.open("Especialidades.txt");

    if (archivoEspecialidades.is_open())
    {
        char linea[57];

        while (mi_getline(archivoEspecialidades, linea, 57) && cantEspecialidades < MAX_ESPECIALIDADES)
        {
            sscanf(linea, "%20s", especialidades[cantEspecialidades].Nombre);
            cantEspecialidades++;
        }
    }

    archivoEspecialidades.close();
    return;
} // Descarga archivo Especialidades.

void ProcTurnosDiaHora(Turno turnos[])
{
    printf("Abierto TurnosDiaHora\n");
    std::ifstream archivoTurnos;
    archivoTurnos.open("TurnosDiaHora.txt");

    if (archivoTurnos.is_open())
    {
        char linea[57];

        while (mi_getline(archivoTurnos, linea, 57))
        {
            printf(linea);
        }
    }
    return;
} // Descarga archivo TurnosDiaHora.

/**
 * Genera turnos aleatorios borrar luego
 */
void GenerarTurnos(Turno turnos[], int cantidadTurnos)
{
    srand(time(NULL));
    for (int i = 0; i < cantidadTurnos; i++)
    {
        int random = rand();
        switch (random % 5)
        {
        case 0:
            sprintf(turnos[i].Especialidad.Nombre, "General");
            break;
        case 1:
            sprintf(turnos[i].Especialidad.Nombre, "Pediatria");
            break;
        case 2:
            sprintf(turnos[i].Especialidad.Nombre, "Odontologia");
            break;
        case 4:
            sprintf(turnos[i].Especialidad.Nombre, "Otorrinolaringologia");
            break;
        default:
            sprintf(turnos[i].Especialidad.Nombre, "Cardiologia");
            break;
        }

        turnos[i].Dia = random % 31;
        turnos[i].Hora = random % 19;
        turnos[i].Minutos = random % 2 ? 0 : 30;
        sprintf(turnos[i].ObraSocial, "OSDE");
        turnos[i].Credencial = 3629 + i;
    }
}

void LstTurnos(std::ofstream &archivoSalida, Turno turnos[MAX_TURNOS], int cantidadTurnos = 0, bool modoFinal)
{
    GenerarTurnos(turnos, cantidadTurnos); // TODO: comentar cuando la lectura de archivos este lista

    OrdTurnosPorBurbuja(turnos, cantidadTurnos);

    char modoString[15] = {' '};
    modoFinal ? strcpy(modoString, "FINAL") : strcpy(modoString, "ACTUALIZADO");

    archivoSalida << "\n\n      Listado de Turnos " << modoString << " orden Espec. + Dia + Horario\n";
    archivoSalida << "Especialidad\t\tDia\tHorario\tObra Soc.\t\tNro. Credencial\n";

    for (int i = 0; i < cantidadTurnos; i++)
    {
        if (turnos[i].Credencial != 0)
        {
            char turnoString[SIZE_STRING_MAX];

            TurnoToString(turnos[i], turnoString);

            archivoSalida << turnoString << '\n';
        }
        else
        {
            break;
        }
    }
} // Lista ord. x Especialidades, D�as y Turnos del vuelco del archivo TurnosDiasHora.

void ProcSolTurnos()
{

} // Descarga archivo SolicitudesTurnos y lista l�neas de las solicitudes.
