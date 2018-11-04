#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

void main (){

    pid_t pid, hijo_pid, abuelo_pid, pid2;
    pid = fork();

    if (pid == -1) //Error
    {
   	 printf("No se ha podido crear el proceso hijo");
   	 exit(-1);    
    }
    if (pid == 0) //Proceso hijo
    {
   	 printf("Soy el proceso hijo \n\t %d, Mi padre es %d. \n", getpid(), getppid() );
   	 pid2 = fork();
   	 if (pid2 == -1) //Error
   	 {
   		 printf("No se ha podido crear el proceso hijo");
   		 exit(-1);    
   	 }
   	 if (pid2 == 0) //Proceso hijo
   	 {
   		 printf("Soy el nieto \n\t %d; Mi padre es %d. \n", getpid(), getppid() );
   	 }
   	 else
   	 {
   		 hijo_pid = wait(NULL);
   		 printf("Mi hijo terminó %d. \n", pid2);
   	 }
    }
    else
    {
   	 abuelo_pid = wait(NULL);
   	 printf("Soy el proceso abuelo:\n\t %d", getpid());
    }
}

