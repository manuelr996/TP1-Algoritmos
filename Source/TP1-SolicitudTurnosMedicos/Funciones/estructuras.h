
struct Medico
{
    char ApellidoNombre[20] = {' '};
    int Matricula;
    Especialidad Especialidad[20];
    char Turno;
};

struct Especialidad
{
    char Nombre[20];
};

struct TurnoDiaHora
{
};

struct SolicitudTurno
{
};

struct SolicitudTurnoDia
{
};
