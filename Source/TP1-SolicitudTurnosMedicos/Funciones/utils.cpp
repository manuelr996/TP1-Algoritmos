#include "utils.h"
#include <stdio.h>

void TurnoToString(Turno turno, char *salida)
{
    //"EEEEEEEEEEEEEEEEEEEE    DD  HH:MM XXXXXXXXXXXXXXX  CC.CC
    float credencialEnFormato = (float) turno.Credencial / 100;

    sprintf(salida, "%s\t%d\t%d:%d\t%s\t%.2f\n",
            turno.Especialidad.Nombre,
            turno.Dia,
            turno.Hora,
            turno.Minutos,
            turno.ObraSocial,
            credencialEnFormato);
}
