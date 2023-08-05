#ifndef FUNCIONES_H

#define FUNCIONES_H

#include <fstream>
#include "estructuras.h"

void   ProcMedicos(       ); // Descarga archivo Medicos.
void ProcEspecialidad(Especialidad especialidades[]);  // Descarga archivo Especialidades.
void ProcTurnosDiaHora(Turno turnos[]);  // Descarga archivo TurnosDiaHora.

void LstTurnos(std::ofstream &archivoSalida, Turno turnos[], int cantidadTurnos, bool modoFinal = false); // Lista ord. x Especialidades, D�as y Turnos del vuelco del archivo TurnosDiasHora.
 // Lista ord. x Especialidades, D�as y Turnos Actualizado con las SolicitudesTurnos.
void   ProcSolTurnos(       ); // Descarga archivo SolicitudesTurnos y lista l�neas de las solicitudes.


#endif