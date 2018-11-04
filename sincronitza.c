#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
/*----------------------------------*/
/* gestió de senyals en proces FILL*/
void controlador (int segnal)
{
  printf("Fill rep senyal...%d\n", segnal);
}
/*------------------------------------------*/
int main()
{
  int pid_fill;
  pid_fill = fork(); 	//creació del fill

  switch (pid_fill)
  {
	case -1:
	  printf("Error al crear elproces fill,,,\n");
	  exit(-1);
	case 0:
	  signal (SIGUSR1, controlador);   //Controlador de senyal en fill
	  while(1){
	  };
	break;
	default:
	  sleep(1);
	  kill (pid_fill, SIGUSR1);  //Envia senyal al fill
	  sleep(1);
	  kill (pid_fill, SIGUSR1);  //Envia senyal al fill
	  sleep(1);
	break;
  }
  return 0;
}