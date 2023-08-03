#include <fstream>
#include <iostream>
#include "Funciones/funciones.h"

using namespace std;

int main()
{

    cout << "----EMPEZANDO----\n";

    //Declarar las variables utilizadas en el bloque main().
    Especialidad especialidades[20];
    Medico medicos[100];
    Turno turnosPrevios[744]; //TurnoDiaHora va aca
    SolicitudTurno turnosRequeridos[744]; // SolicitudTurno va aca
    Turno turnosFinales[744]; //valores de salida
    ofstream salidaDatos;

    cout << "----Estructuras Declaradas----\n";

    ProcMedicos(       ); // Descarga archivo Medicos.
    ProcEspecialidad(      );  // Descarga archivo Especialidades.
    ProcTurnosDiaHora(       );  // Descarga archivo TurnosDiaHora.

    cout << "----Estructuras Cargadas----\n";

    salidaDatos.open("./Archivox3.txt", std::fstream::out);
    cout << "archivo abierto\n";

    LstTurnos(salidaDatos, turnosPrevios); // Lista ord. x Especialidades, D�as y Turnos del vuelco del archivo TurnosDiasHora.

    ProcSolTurnos(       ); // Descarga archivo SolicitudesTurnos y lista l�neas de las solicitudes.
    LstTurnos(salidaDatos, turnosFinales); // Lista ord. x Especialidades, D�as y Turnos Actualizado con las SolicitudesTurnos.

    salidaDatos.close();
    cout << "----Procesado----\n";
    //TODO: Cerrar todos los archivos

    return '0';
}
