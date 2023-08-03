#include "funciones.h"
#include <stdio.h>
#include "utils.h"

 void   ProcMedicos(       )
 {

 } // Descarga archivo Medicos.

 void   ProcEspecialidad(      )
 {

 }  // Descarga archivo Especialidades.

 void   ProcTurnosDiaHora(       )
 {

 }  // Descarga archivo TurnosDiaHora.

void LstTurnos(std::ofstream &archivoSalida, Turno turnos[744])
{
    Turno turnoTemplate;

    turnoTemplate.Id = 0;
    sprintf(turnoTemplate.Especialidad.Nombre, "General");
    turnoTemplate.Dia = 22;
    turnoTemplate.Hora = 10;
    turnoTemplate.Minutos = 30;
    sprintf(turnoTemplate.ObraSocial, "MEDICUS");
    turnoTemplate.Credencial = 2233;

    for(int i = 0; i < 200; i++)
    {
        turnos[i] = turnoTemplate;
    }

    for(int i = 0; i < 744; i++)
    {
        if(turnos[i].Credencial != 0)
        {
            char turnoString[52];

            TurnoToString(turnos[i], turnoString);
            archivoSalida << turnoString;
        }
        else
        {
            break;
        }
    }
} // Lista ord. x Especialidades, D�as y Turnos del vuelco del archivo TurnosDiasHora.

 void   ProcSolTurnos(       )
 {

 } // Descarga archivo SolicitudesTurnos y lista l�neas de las solicitudes.

