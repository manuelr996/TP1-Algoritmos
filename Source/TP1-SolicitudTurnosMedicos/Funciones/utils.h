#include "estructuras.h"


//Leer Un registro del ifstream y guardarlo en la estructura enviada como referencia
//retornar si se pudo leer exitosamente como true o false caso contrario
bool LeeEspecialidades(ifstream &id, Especialidad[] &id);
bool LeeMedicos(ifstream &id, Medico[] &id);
bool LeeTurnosDiaHora(ifstream &id, TurnoDiaHora[] &id);
bool LeeSolicitudTurnos(ifstream &id, SolicitudTurno[] &id);

Especialidad BusquedaBinaria(Especialidad[] especialidades, n cantidadEspecialidades, char *nombreEspecialidad);
Medico BusquedaBinaria(Medico[] especialidades, n cantMedicos, int matriculaABuscar);
TurnoDiaHora BusquedaBinaria(TurnoDiaHora[] TurnosDiaHora, n cantTurnos, int identificadorTurno);
SolicitudTurno BusquedaBinaria(SolcitudTurno[] SolicitudTurnos, n cantTurnos, int identificadorTurno);

//Graba en el archivo de salida los valores procesados.
void GrabaSolicitudTurnosDia(ofstream &id, SolicitudTurnoDia[] &id);

void OrdMedicosPorBurbuja();
