#include "funciones.h"
#include "constantes.h"
#include <stdio.h>
#include "utils.h"
#include <stdlib.h>

void ProcMedicos(std::ifstream &archivoMedicos, Medico medicos[], int &cantMedicos)
{

} // Descarga archivo Medicos.

void ProcEspecialidad(std::fstream &archivoEspecialidades, Especialidad especialidades[], int &cantEspecialidades)
{
    if (archivoEspecialidades.is_open())
    {
        char linea[57];


        while (mi_getline(archivoEspecialidades, linea, 57) && cantEspecialidades < MAX_ESPECIALIDADES)
        {
            sscanf(linea, "%20s", especialidades[cantEspecialidades].Nombre);
            cantEspecialidades++;
        }
    }

} // Descarga archivo Especialidades.

void ProcTurnosDiaHora(std::fstream &archivoTurnos, Turno turnos[], int &cantTurnos)
{

    if (archivoTurnos.is_open())
    {
        while (LeeTurnosDiaHora(archivoTurnos, turnos))
        {
            cantTurnos++;

        }
    }
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
    modoFinal ? strcpy(modoString, "FINAL") : strcpy(modoString, "INICIAL");

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

void ProcSolTurnos(SolicitudTurno solicitudTurno[])
{
    std::ifstream archivoSolicitud;
    archivoSolicitud.open("SolicitudTurnos.txt");

    if (archivoSolicitud.is_open())
    {
        char linea[72];

        while (LeeSolTurnos(archivoSolicitud, solicitudTurno))
        {
        }
    }
} // Descarga archivo SolicitudesTurnos y lista lineas de las solicitudes.
