#ifndef UTILS_H

#define UTILS_H

#include "estructuras.h"
#include <stdio.h>
#include <string.h>
#include <fstream>

//Leer Un registro del ifstream y guardarlo en la estructura enviada como referencia
//retornar si se pudo leer exitosamente como true o false caso contrario
bool LeeEspecialidades(std::ifstream &id, Especialidad especialidades[]);
bool LeeMedicos(std::ifstream &id, Medico medicos[]);
bool LeeTurnosDiaHora(std::fstream &id, Turno turnos[]);
bool LeeSolTurnos(std::ifstream &id, SolicitudTurno solicitudTurno[]);

Especialidad BusquedaBinariaEsp(Especialidad especialidades[],int cantidadEspecialidades, char *nombreEspecialidad);
Medico BusquedaBinariaMed(Medico especialidades[],int cantMedicos, int matriculaABuscar);
Turno BusquedaBinariaTurno(Turno TurnosDiaHora[],int cantTurnos, int identificadorTurno);
SolicitudTurno BusquedaBinariaSolTurno(SolicitudTurno SolicitudTurnos[],int cantTurnos, int identificadorTurno);

//Graba en el archivo de salida los valores procesados.
void GrabaSolicitudTurnosDia(std::ofstream &id, Turno turnos[]);

void OrdMedicosPorBurbuja();
void OrdTurnosPorBurbuja(Turno turnos[], int cantidadTurnos);
void IntercambiaTurnos(Turno &a, Turno &b);

void TurnoToString(Turno turno, char *salida);
bool mi_getline(std::fstream &stream, char *salida, int max_lectura);


#endif
