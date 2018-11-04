#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
void main(){
	pid_t pid,hijo_pid;
	pid = fork();
	if(pid == -1){
		printf("No se ha podido crear el proceso hijo \n" );
		exit(-1);
	}else if (pid == 0){
		printf("Soy el hijo = 3, Mi padre es: %d , mi pid es: %d\n",getppid(),getpid() );
	}else{
		hijo_pid =wait(NULL);
		pid = fork();
		if(pid == -1){
			printf("No se ha podido crear el proceso hijo \n" );
			exit(-1);
		}else if (pid == 0){
			printf("Soy el hijo = 2, Mi padre es %d, mi pid es %d\n",getppid(),getpid() );
		}else{
			hijo_pid = wait(NULL);
			pid =fork();
			if(pid == -1){
				printf("No se ha podido crear el hijo 2\n");
				exit(-1);
			}else if(pid == 0){
				printf("Soy el hijo = 1, Mi padre es %d, mi pid es: %d\n",getppid(),getpid() );
			}else{
				hijo_pid = wait(NULL);
			}
		}
	}
exit(0);
}