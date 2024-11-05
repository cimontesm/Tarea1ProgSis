#include <stdio.h>
#include "menu.h"
#include "datos.h"
#include "auth.h"
#include "logIn.h"

int main() {
    int opcion;
    char repetir;
    char usuario[50];
    char clave[50];
    int autenticado = 0;

    printf("Ingrese usuario: ");
    scanf("%s", usuario);
    printf("Ingrese clave: ");
    scanf("%s", clave);

    
    autenticado = validar_usuario(usuario, clave);
    if (!autenticado) {
        registrar_bitacora(usuario, "Ingreso fallido usuario/clave erróneo");
        printf("Acceso denegado. Usuario o clave incorrectos.\n");
        return 1; 
    }
    registrar_bitacora(usuario, "Ingreso exitoso al sistema");

    do {
        printf("\nSeleccione una opción:\n");
        printf("1. Cálculo de área y perímetro (Figuras 2D)\n");
        printf("2. Cálculo de superficie y volumen (Figuras 3D)\n");
        printf("3. Salir\n");
        printf("Opción: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1: registrar_bitacora(usuario, "Acceso a cálculos de área y perímetro (Figuras 2D)"); menu2D(); break;
            case 2: registrar_bitacora(usuario, "Acceso a cálculos de superficie y volumen (Figuras 3D)"); menu3D(); break;
            case 3: registrar_bitacora(usuario, "Salida del sistema"); printf("Saliendo del programa...\n"); return 0;
            default: printf("Opción no válida. Intente nuevamente.\n");
        }
        
        printf("\n¿Desea realizar el análisis de otra figura geométrica? (s/n): ");
        scanf(" %c", &repetir);

    } while(repetir == 's' || repetir == 'S');

    registrar_bitacora(usuario, "Salida del sistema");

    return 0;
}
