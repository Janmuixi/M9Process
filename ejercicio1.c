#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

void main() {

	pid_t pid, hijo_pid;
	pid = fork();

	if (pid == -1)//ERROR
	{
		printf ("No se ha podido crear el proceso hijo");
		exit(-1);
	}
	else if (pid == 0)//Proceso hijo
	{
		printf ("Soy el proceso hijo \n\t Mi PID es %d, El PID de mi padre es %d. \n", getpid(), getppid() );
		hijo_pid = fork();
		if (hijo_pid == -1)//ERROR
		{
			printf ("No se ha podido crear el proceso hijo");
			exit(-1);
		}
		else if (hijo_pid == 0)//Proceso hijo
		{
			printf ("Soy el proceso nieto \n\t Mi PID es %d, El PID de mi padre es %d. \n", getpid(), getppid() );
		}
		else {
			printf ("Mi hijo: %d termino.\n",hijo_pid);
		}
	}
	else
	{
		printf("Soy el proceso abuelo:\n\t Mi PID es %d, El PID de mi padre es: %d.\n\t Mi hijo: %d termino. \n", getpid(), getppid(), pid);
	}
	exit(0);
}
