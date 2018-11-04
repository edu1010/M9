#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void main() {
	pid_t pid, hijo_pid;
	pid = fork();

	if (pid == -1) { //error
		printf ( "No se ha podido crear el proceso hijo" );
		exit(-1);
	}
	if (pid == 0){ //Proceso
		printf ("Soy el proceso hijo \n\t Mi PID es %d, El PID de mi padre es %d. \n", getpid(), getppid());	
	}
	else{
		hijo_pid = wait(NULL);
		printf( "Soy el proceso padre:\n\t Mi PID es %d, El PID de mi padre es: %d.\n\t Mi hijo: %d termino. \n", getpid(), getppid(), pid); 
	}
	exit(0);

	}
