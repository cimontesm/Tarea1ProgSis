#include <stdio.h>
#include <string.h>
#include "auth.h"

int validar_usuario(const char *usuario, const char *clave){
	FILE *file = fopen("usuarios.txt", "r");
	if(!file){
		perror("No se pudo abrir el archivo de usuarios");
		return 0;
	}
	char linea[100];
	char usuario_archivo[50], clave_archivo[50];
	while(fgets(linea, sizeof(linea), file)){
		sscanf(linea, "%s %s", usuario_archivo, clave_archivo);
		if(strcmp(usuario, usuario_archivo) == 0 && strcmp(clave,clave_archivo) == 0){
			fclose(file);
			return 1;
		}
	}
	fclose(file);
	return 0;
}
