#ifndef ESTRUCTURAS_H

#define ESTRUCTURAS_H

struct Especialidad
{
    char Nombre[20];
};

struct Medico
{
    char ApellidoNombre[20];
    int Matricula;
    Especialidad Especialidad;
    //Tuve que renombrar esto porque el profesor ya usa "Turno" para hablar de
    //los turnos que saca la gente no de las franjas horarias
    char FranjaHoraria; //columna Turno en el archivo lo
};

struct Turno
{
    short Dia;
    short Hora;
    short Minutos;
    short Credencial;
    char ObraSocial[15];
    Especialidad Especialidad;
};

struct SolicitudTurno
{
    char ApellidoNombre[20];
    short Edad;
    short Matricula;
    Turno Turno; //Valores del Turno
    char FranjaHoraria; //columna Turno en el archivo
};

#endif
