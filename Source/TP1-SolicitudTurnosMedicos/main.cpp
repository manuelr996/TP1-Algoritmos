#include <iostream>
#include "main.h"

int main()
{

    //Declarar las variables utilizadas en el bloque main().
    Especialidad especialidades[20];
    Medico medicos[100];
    Turno turnosPrevios[744]; //TurnoDiaHora va aca
    SolicitudTurno turnosRequeridos[744]; // SolicitudTurno va aca
    Turno turnosFinales[744]; //valores de salida


    ProcMedicos(       ); // Descarga archivo Medicos.
    ProcEspecialidad(      );  // Descarga archivo Especialidades.
    ProcTurnosDiaHora(       );  // Descarga archivo TurnosDiaHora.

    LstTurnos(        ); // Lista ord. x Especialidades, Días y Turnos del vuelco del archivo TurnosDiasHora.

    ProcSolTurnos(       ); // Descarga archivo SolicitudesTurnos y lista líneas de las solicitudes.
    LstTurnos(        ); // Lista ord. x Especialidades, Días y Turnos Actualizado con las SolicitudesTurnos.

    //TODO: Cerrar todos los archivos

    return 0;
}
