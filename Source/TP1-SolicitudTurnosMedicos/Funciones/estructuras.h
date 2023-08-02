
struct Medico
{
    char ApellidoNombre[20];
    int Matricula;
    Especialidad Especialidad;
    char FranjaHoraria; //columna Turno en el archivo
}

struct Especialidad
{
    char Nombre[20];
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
