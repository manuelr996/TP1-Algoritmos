#include <iostream.h>
#include <fstream.h>

#define MAX_TURNOS 744
#define MAX_MEDICOS 100
#define MAX_ESPECIALIDADES 20
#define SIZE_STRING_MAX 52

using namespace std;

struct Especialidad
{
    char Nombre[21];
};

struct Medico
{
    char apellidoNombre[21];
    unsigned int nroMatricula;
    char nombreEspecialidad[21];
    char franjaHoraria;
};

struct Turno
{
    short Dia;
    short Hora;
    short Minutos;
    short Credencial;
    char ObraSocial[16];
    Especialidad Especialidad;
};

struct SolicitudTurno
{
    char ApellidoNombre[21];
    char Edad[3];
    char ObraSocial[16];
    int Matricula;
    Especialidad Especialidad;
    short dia;
//    Turno Turno; //Valores del Turno
    char Turno; //columna Turno en el archivo
    int Credencial;
};

void IntercambiaTurnos(Turno &a, Turno &b)
{
    Turno aux = a;
    a = b;
    b = aux;
}

/*
 * Ordena los turnos por credencial
*/
void OrdTurnosPorBurbuja(Turno turnos[], int cantidadTurnos)
{
    //burbuja por Hora y Minuto
    for(int i = 0; i < cantidadTurnos - 1; i++)
    {
        bool intercambiados = false;
        for(int j = 0; j < cantidadTurnos - 1; j++)
        {
            int diaHora1 = turnos[j].Hora * 100 + turnos[j].Minutos;
            int diaHora2 = turnos[j+1].Hora * 100 + turnos[j+1].Minutos;

            if(diaHora1 > diaHora2) // solo los intercambio si son de la misma especialidad
            {
                IntercambiaTurnos(turnos[j+1], turnos[j]);
                intercambiados = true;
            }
        }
        if (intercambiados == false)
            break;
    }

    //burbuja por Dia
    for(int i = 0; i < cantidadTurnos - 1; i++)
    {
        bool intercambiados = false;
        for(int j = 0; j < cantidadTurnos - 1; j++)
        {
            if(turnos[j].Dia > turnos[j+1].Dia) // solo los intercambio si son de la misma especialidad
            {
                IntercambiaTurnos(turnos[j], turnos[j+1]);
                intercambiados = true;
            }
        }
        if (intercambiados == false)
            break;
    }

    //burbuja por especialidad
    for(int i = 0; i < cantidadTurnos - 1; i++)
    {
        bool intercambiados = false;
        for(int j = 0; j < cantidadTurnos - 1; j++)
        {
            if(strcmp(turnos[j].Especialidad.Nombre, turnos[j+1].Especialidad.Nombre) > 0)
            {
                IntercambiaTurnos(turnos[j], turnos[j+1]);
                intercambiados = true;
            }
        }
        if (intercambiados == false)
            break;
    }
}

short convertirHHMMtoIndice(short HH, short mm)
{
    short valor = 0;

    //debe haber una formula matematica mistica que no estoy viendo ahora mismo que hace que este chequeo sea trivial
    //pero esta forma super ineficiente de hacerlo va a tener que ser suficiente
    for(short hora = 0 ; hora < (HH * 100 + mm) || hora >= 1930; hora+=30 )
    {
        valor++;
    }
    return valor;
}

bool mi_getline(std::fstream &stream, char *salida, int max_lectura)
{
    char aux = 0;
    int index = 0;

    while(stream.get(aux))
    {
        salida[index] = aux;
        index++;

        if(stream.tellg() == -1)
            break;
        if(aux == '\n' || index > max_lectura)
            return true;
    }

    return false;
}

bool LeeTurnosDiaHora(std::fstream &id, Turno turnos[])
{
    char linea[57] = {' '};
    static int ultimoTurno = 0;

    if(mi_getline(id, linea, 57))
    {
        char dia[2];
        char hora[2];
        char minutos[2];
        char credencial[6];


        //si alguien en algun futuro lejano lee esto
        //perdon...
        //si por algun motivo del mundo,
        //el archivo leyese menos de 57 caracteres esto va a volar a la mierda
        for(int i = 0; i < 57 ; i++)
        {
            if(i >= 0 && i < 20)
                turnos[ultimoTurno].Especialidad.Nombre[i] = linea[i];
            if(i >= 20 && i < 22)
                dia[i-20] = linea[i];
            if(i >= 22 && i < 24)
                hora[i-24] = linea[i];
            if(i >= 24 && i < 26)
                minutos[i-26] = linea[i];
            if(i >= 26 && i < 41 )
                turnos[ultimoTurno].Especialidad.Nombre[i-26] = linea[i];
            if(i >= 41 && i < 47 )
                credencial[i-41] = linea[i];
        }

        turnos[ultimoTurno].Dia = (short)atoi(dia);
        turnos[ultimoTurno].Hora = (short)atoi(hora);
        turnos[ultimoTurno].Minutos = (short)atoi(minutos);
        turnos[ultimoTurno].Credencial = atoi(credencial);

        turnos[ultimoTurno];

        ultimoTurno++;
        return true;
    }
    else
    {
        ultimoTurno = 0;
        return false;
    }
}
//======================================================================

bool LeeSolTurnos(std::fstream &id, SolicitudTurno solicitudTurno[])
{
    char linea[72] = {' '};
    char aux[6];
    char aux2[2];
    char aux3[6];
    static int ultimaSolicitud = 0;


    if(mi_getline(id, linea, 72))
    {
        for(int i = 0; i < 72; i++)
        {
            if(i >= 0 && i <20)
            {
                solicitudTurno[ultimaSolicitud].ApellidoNombre[i] = linea[i];
            }
            else if(i >= 20 && i <22)
            {
                solicitudTurno[ultimaSolicitud].Edad[i - 20] = linea[i];
            }
            else if(i >= 22 && i <37)
            {
                solicitudTurno[ultimaSolicitud].ObraSocial[i - 22] = linea[i];
            }
            else if(i >= 37 && i <43)
            {
                aux[i - 37] = linea[i];
            }
            else if(i >= 43 && i <63)
            {
                solicitudTurno[ultimaSolicitud].Especialidad.Nombre[i - 43] = linea[i];
            }
            else if(i >= 63 && i <65)
            {
                aux2[i - 63] = linea[i];
            }
            else if(i >= 65 && i <66)
            {
                solicitudTurno[ultimaSolicitud].Turno = linea[i];
            }
            else if(i >= 66 && i <72)
            {
                aux[i - 66] = linea[i];
            }
        }

        solicitudTurno[ultimaSolicitud].Matricula = atoi(aux);
        solicitudTurno[ultimaSolicitud].dia = (short)atoi(aux2);
        solicitudTurno[ultimaSolicitud].Credencial = atoi(aux3);

        ultimaSolicitud++;
        return true;
    }
    else
    {
        ultimaSolicitud = 0;
        return false;
    }
}

void TurnoToString(Turno turno, char *salida)
{
    //"EEEEEEEEEEEEEEEEEEEE    DD  HH:MM XXXXXXXXXXXXXXX  CC.CC
    float credencialEnFormato = (float) turno.Credencial / 100;

    sprintf(salida, "%-20s\t%02d\t%02d:%02d\t\t%-15s\t%.2f",
            turno.Especialidad.Nombre,
            turno.Dia,
            turno.Hora,
            turno.Minutos,
            turno.ObraSocial,
            credencialEnFormato);
}

void ProcMedicos(Medico medicos[], int &cantMedicos)
{
    std::ifstream archivo;
    archivo.open("Medicos.txt", ios::in);

    while(!archivo.eof()){
        archivo.get(medicos[cantMedicos].apellidoNombre,20);
        archivo>>medicos[cantMedicos].nroMatricula;
        archivo.get(medicos[cantMedicos].nombreEspecialidad,20);
        archivo>>medicos[cantMedicos].franjaHoraria;
        cantMedicos++;
        archivo.ignore();
    }

    archivo.close();
} // Descarga archivo Medicos.

void ProcEspecialidad(std::fstream &archivoEspecialidades, Especialidad especialidades[], int &cantEspecialidades)
{
    if (archivoEspecialidades.is_open())
    {
        char linea[57] = {' '};

        while (mi_getline(archivoEspecialidades, linea, 57) && cantEspecialidades < MAX_ESPECIALIDADES)
        {
            sscanf(linea, "%20s", especialidades[cantEspecialidades].Nombre);
            cantEspecialidades++;
        }
    }

} // Descarga archivo Especialidades.

void ProcTurnosDiaHora(std::fstream &archivoTurnos, Turno turnos[], int &cantTurnos)
{

    if (archivoTurnos.is_open())
    {
        while (LeeTurnosDiaHora(archivoTurnos, turnos))
        {
            cantTurnos++;
        }
    }
} // Descarga archivo TurnosDiaHora.

void LstTurnos(std::ofstream &archivoSalida, Turno turnos[MAX_TURNOS], int cantidadTurnos, bool modoFinal)
{
    //GenerarTurnos(turnos, cantidadTurnos); // TODO: comentar cuando la lectura de archivos este lista

    OrdTurnosPorBurbuja(turnos, cantidadTurnos);

    char modoString[15] = {' '};
    modoFinal ? strcpy(modoString, "FINAL") : strcpy(modoString, "INICIAL");

    archivoSalida << "\n\n      Listado de Turnos " << modoString << " orden Espec. + Dia + Horario\n";
    archivoSalida << "Especialidad\t\tDia\tHorario\tObra Soc.\t\tNro. Credencial\n";

    for (int i = 0; i < cantidadTurnos; i++)
    {
        if (turnos[i].Credencial != 0)
        {
            char turnoString[SIZE_STRING_MAX];

            TurnoToString(turnos[i], turnoString);

            archivoSalida << turnoString << '\n';
        }
        else
        {
            break;
        }
    }
} // Lista ord. x Especialidades, D�as y Turnos del vuelco del archivo TurnosDiasHora.

void ProcSolTurnos(SolicitudTurno solicitudTurno[])
{
    std::fstream archivoSolicitud;
    archivoSolicitud.open("SolicitudTurnos.txt");

    if (archivoSolicitud.is_open())
    {
        char linea[72];

        while (LeeSolTurnos(archivoSolicitud, solicitudTurno))
        {
        }
    }
} // Descarga archivo SolicitudesTurnos y lista lineas de las solicitudes.

int main()
{

    // Declarar las variables utilizadas en el bloque main().
    Especialidad especialidades[MAX_ESPECIALIDADES];
    Medico medicos[MAX_MEDICOS];
    Turno turnosPrevios[MAX_TURNOS];             // TurnoDiaHora va aca
    SolicitudTurno turnosRequeridos[MAX_TURNOS]; // SolicitudTurno va aca
    Turno turnosFinales[MAX_TURNOS];             // valores de salida


    int cantMedicos = 0;
    int cantEspecialidades = 0;
    int cantTurnos = 0;

    fstream entradaMedicos("Medicos.txt", ifstream::in);
    fstream entradaEspecialidades("Especialidades.txt", ifstream::in);
    fstream entradaTurnos("TurnosDiaHora.txt", ios::in);
    ofstream salidaDatos("Archivox3.txt", std::fstream::out);


    // entradaMedicos.open("Medicos.txt", ifstream::in);
    // entradaEspecialidades.open("Especialidades.txt", ifstream::in);
    //entradaTurnos.open("./TurnosDiaHora.txt", ifstream::out);
    char salida[57];

    ProcMedicos(medicos, cantMedicos);       // Descarga archivo Medicos.
    ProcEspecialidad(entradaEspecialidades, especialidades, cantEspecialidades);  // Descarga archivo Especialidades.
    ProcTurnosDiaHora(entradaTurnos, turnosPrevios, cantTurnos); // Descarga archivo TurnosDiaHora.

    LstTurnos(salidaDatos, turnosPrevios, cantTurnos, false); // Lista ord. x Especialidades, D�as y Turnos del vuelco del archivo TurnosDiasHora.

    ProcSolTurnos(turnosRequeridos);      // Descarga archivo SolicitudesTurnos y lista l�neas de las solicitudes.
    LstTurnos(salidaDatos, turnosFinales, cantTurnos, true); // Lista ord. x Especialidades, D�as y Turnos Actualizado con las SolicitudesTurnos.


    //entradaMedicos.close();
    //entradaEspecialidades.close();
    entradaTurnos.close();
    salidaDatos.close();
    // TODO: Cerrar todos los archivos

    return '0';
}
