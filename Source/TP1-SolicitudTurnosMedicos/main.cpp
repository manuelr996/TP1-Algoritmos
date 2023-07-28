#include <iostream>
#include "main.h"

using namespace std;

int main()
{

    //Declarar las variables utilizadas en el bloque main().

    //TODO: Abrir todos los archivos
    ProcMedicos(       ); // Descarga archivo Medicos.
    ProcEspecialidad(      );  // Descarga archivo Especialidades.
    ProcTurnos(       );  // Descarga archivo TurnosDiaHora.
    LstTurnos(        ); // Lista ord. x Especialidades, Días y Turnos del vuelco del archivo TurnosDiasHora.
    ProcTurnos(       ); // Descarga archivo SolicitudesTurnos y lista líneas de las solicitudes.
    LstTurnos(        ); // Lista ord. x Especialidades, Días y Turnos Actualizado con las SolicitudesTurnos.

    //TODO: Cerrar todos los archivos

    return 0;
}
