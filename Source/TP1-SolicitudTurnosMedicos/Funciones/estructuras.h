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
    int Id;
    int Dia;
    int Hora;
    int Minutos;
    int Credencial;
    char ObraSocial[15];
    Especialidad Especialidad;
};

struct SolicitudTurno
{
    int Id;
    char ApellidoNombre[20];
    int Edad;
    int Matricula;
    Turno Turno; //Valores del Turno
    char FranjaHoraria; //columna Turno en el archivo
};

struct SolicitudTurnoDia
{
    Turno Turno;
};

#endif
