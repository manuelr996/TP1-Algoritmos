#include "utils.h"
#include "constantes.h"

#include<iostream>

bool LeeTurnosDiaHora(std::ifstream &id, Turno turnos[])
{
    char linea[57];
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

        sscanf(dia, "%d", turnos[ultimoTurno].Dia);


        turnos[ultimoTurno];

        ultimoTurno++;
    }
    else
    {
        ultimoTurno = 0;
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

void IntercambiaTurnos(Turno &a, Turno &b)
{
    Turno aux = a;
    a = b;
    b = aux;
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

using namespace std;
bool mi_getline(std::istream &stream, char *salida, int max_lectura)
{
    char aux;
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
