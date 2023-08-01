#include <iostream>
#include "main.h"

int main()
{

    //Declarar las variables utilizadas en el bloque main().
    //TODO: Abrir todos los archivos
    //Parsear archivos de entrada

    ProcMedicos(       ); // Descarga archivo Medicos.
    ProcEspecialidad(      );  // Descarga archivo Especialidades.
    ProcTurnosDiaHora(       );  // Descarga archivo TurnosDiaHora.

    //Generar Archivos de Salida
    LstTurnos(        ); // Lista ord. x Especialidades, Días y Turnos del vuelco del archivo TurnosDiasHora.
    ProcSolTurnos(       ); // Descarga archivo SolicitudesTurnos y lista líneas de las solicitudes.
    LstTurnos(        ); // Lista ord. x Especialidades, Días y Turnos Actualizado con las SolicitudesTurnos.

    //TODO: Cerrar todos los archivos

    return 0;
}
