#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void main() {
	pid_t pid, hijo_pid;
	
	int i;
	for(i=0;i<3;i++){
		pid=fork(); 
	  if(pid == 0){
		   printf("soy el hijo[%d] %d, mi padre es %d\n",i+1,getpid(),getppid());
		   exit(0);
		  }
	}
	printf("Soy el proceso padre %d\n",getpid());
}