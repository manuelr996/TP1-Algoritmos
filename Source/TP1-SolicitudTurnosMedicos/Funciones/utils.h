#include "estructuras.h"
#include <fstream>

//Leer Un registro del ifstream y guardarlo en la estructura enviada como referencia
//retornar si se pudo leer exitosamente como true o false caso contrario
bool LeeEspecialidades(std::ifstream &id, Especialidad especialidades[]);
bool LeeMedicos(std::ifstream &id, Medico medicos[]);
bool LeeTurnosDiaHora(std::ifstream &id, Turno turnos[]);
bool LeeSolicitudTurnos(std::ifstream &id, SolicitudTurno solicitudesTurnos[]);

Especialidad BusquedaBinariaEsp(Especialidad especialidades[],int cantidadEspecialidades, char *nombreEspecialidad);
Medico BusquedaBinariaMed(Medico especialidades[],int cantMedicos, int matriculaABuscar);
Turno BusquedaBinariaTurno(Turno TurnosDiaHora[],int cantTurnos, int identificadorTurno);
SolicitudTurno BusquedaBinariaSolTurno(SolicitudTurno SolicitudTurnos[],int cantTurnos, int identificadorTurno);

//Graba en el archivo de salida los valores procesados.
void GrabaSolicitudTurnosDia(std::ofstream &id, Turno turnos[]);

void OrdMedicosPorBurbuja();

void TurnoToString(Turno turno, char *salida);