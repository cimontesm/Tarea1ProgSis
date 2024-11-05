#include <stdio.h>
#include <time.h>
#include "logIn.h"

void registrar_bitacora(const char *usuario, const char *accion) {
    FILE *file = fopen("bitacora.txt", "a");
    if (!file) {
        perror("No se pudo abrir el archivo de bitácora");
        return;
    }

    // Obtener fecha actual
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    char fecha[20];
    strftime(fecha, sizeof(fecha), "%Y/%m/%d", tm_info);

    // Escribir en bitácora
    fprintf(file, "%s: %s – %s\n", fecha, usuario, accion);
    fclose(file);
}
