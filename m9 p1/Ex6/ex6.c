#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
void main(){
	int fd1[2],fd2[2];
	char buffer[30],buffer2[30];

	pid_t pid;
	pipe(fd1);
	pipe(fd2);
	pid = fork();

	switch(pid){
		case -1://error
			printf("Ha habido un error\n");
			exit(-1);
		case 0://Fill
			close(fd1[1]);
			read(fd1[0],buffer,20);
			printf("Fill rep el missatge del pare: %s \n",buffer );
			printf("El fill envia el missatge al pare \n");
			write(fd2[1],"Salutacions del fill", 20);
			break;
		default://Pare
			printf("Pare envia un missatge al fill \n");
			write(fd1[1],"Salutacions del pare",20);
			close(fd2[1]);
			read(fd2[0],buffer,20);
			printf("Pare rep el missatge del fill: %s \n",buffer );
			break;
	}

}