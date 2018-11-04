#include <stdio.h>
#include <stdlib.h>
void main (){
	printf("Ejemplo de uso system");
	printf("\n\tListado del directoria actual y envio a un fichero");
	printf("%d", system ("ls > fiscsalida"));
	printf("\n\tAbrimos con el gedit el fitchero");
	printf("%d", system ("gedit fiscsalida"));
	printf("\n\tEste comando es erroneo: %d", system ("ged"));
	printf("\nFin de programa.......\n");
}

