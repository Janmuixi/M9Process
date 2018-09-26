#include <unistd.h>
#include <stdio.h>

void main() {

	printf ("Ejemplo de uso de execl() :");
	printf ("La ejecucion produce: \n");
	execl("/bin/ls","ls","-l", (char *) NULL);
}
