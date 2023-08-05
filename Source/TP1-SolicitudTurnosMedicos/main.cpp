#include "main.h"

using namespace std;

int main()
{

    cout << "----EMPEZANDO----\n";

    // Declarar las variables utilizadas en el bloque main().
    Especialidad especialidades[MAX_ESPECIALIDADES];
    Medico medicos[MAX_MEDICOS];
    Turno turnosPrevios[MAX_TURNOS];             // TurnoDiaHora va aca
    SolicitudTurno turnosRequeridos[MAX_TURNOS]; // SolicitudTurno va aca
    Turno turnosFinales[MAX_TURNOS];             // valores de salida

    int cantTurnos = 0;

    ofstream salidaDatos;

    cout << "----Estructuras Declaradas----\n";

    ProcMedicos();       // Descarga archivo Medicos.
    ProcEspecialidad(especialidades);  // Descarga archivo Especialidades.
    printf("Abierto TurnosDiaHora\n");
    ProcTurnosDiaHora(turnosPrevios); // Descarga archivo TurnosDiaHora.

    cout << "----Estructuras Cargadas----\n";

    salidaDatos.open("./Archivox3.txt", std::fstream::out);

    LstTurnos(salidaDatos, turnosPrevios, cantTurnos); // Lista ord. x Especialidades, D�as y Turnos del vuelco del archivo TurnosDiasHora.

    ProcSolTurnos();                                 // Descarga archivo SolicitudesTurnos y lista l�neas de las solicitudes.
    LstTurnos(salidaDatos, turnosFinales, 50, true); // Lista ord. x Especialidades, D�as y Turnos Actualizado con las SolicitudesTurnos.

    salidaDatos.close();
    cout << "----Procesado----\n";
    // TODO: Cerrar todos los archivos

    return '0';
}
