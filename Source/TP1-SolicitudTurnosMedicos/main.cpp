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


    cout << "----Estructuras Declaradas----\n";


    int cantMedicos = 0;
    int cantEspecialidades = 0;
    int cantTurnos = 0;

    //ifstream entradaMedicos("Medicos.txt", ifstream::in);
    //ifstream entradaEspecialidades("Especialidades.txt", ifstream::in);
    fstream entradaTurnos("TurnosDiaHora.txt", ios::in);
    ofstream salidaDatos("Archivox3.txt", std::fstream::out);


    // entradaMedicos.open("Medicos.txt", ifstream::in);
    // entradaEspecialidades.open("Especialidades.txt", ifstream::in);
    // entradaTurnos.open("./TurnosDiaHora.txt", ifstream::out);
    char salida[57];

    cout << "Archivos declarados\n";
    //entradaTurnos >> salida;
    mi_getline(entradaTurnos, salida, 57);
    cout << salida;


    //ProcMedicos(entradaMedicos, medicos, cantMedicos);       // Descarga archivo Medicos.
    //ProcEspecialidad(entradaEspecialidades, especialidades, cantEspecialidades);  // Descarga archivo Especialidades.
    ProcTurnosDiaHora(entradaTurnos, turnosPrevios, cantTurnos); // Descarga archivo TurnosDiaHora.
    cout << "----Estructuras Cargadas----\n";

    LstTurnos(salidaDatos, turnosPrevios, cantTurnos); // Lista ord. x Especialidades, D�as y Turnos del vuelco del archivo TurnosDiasHora.

    ProcSolTurnos();                                 // Descarga archivo SolicitudesTurnos y lista l�neas de las solicitudes.
    LstTurnos(salidaDatos, turnosFinales, cantTurnos, true); // Lista ord. x Especialidades, D�as y Turnos Actualizado con las SolicitudesTurnos.


    //entradaMedicos.close();
    //entradaEspecialidades.close();
    entradaTurnos.close();
    salidaDatos.close();
    cout << "----Procesado----\n";
    // TODO: Cerrar todos los archivos

    return '0';
}
