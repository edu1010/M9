#include <stdio.h>
#include <stdlib.h>
void main (){
	printf("Ejemplo de uso execl():");
	printf("La ejecucion produce:\n");
	printf("/bin/ls", "ls", "-l", (char *) NULL);
}

