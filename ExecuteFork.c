//Preprocessor Directives
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{

        printf("Child: Executing \"program2b\" with arguments. %s starting to execute.\n", argv[0]);
        printf("\n%s My PID is %d and My parent's PID is %d\n\n", argv[0], getpid(), getppid());

	//Display the output of each Arguments
        printf("\tArgument 1 is: %s\n", argv[0]);
        printf("\tArgument 2 is: %s\n", argv[1]);
        printf("\tArgument 3 is: %s\n", argv[2]);

        printf("\n%s I'm ending execution.\n", argv[0]);

	return 0;

}

/******************************************  The End of Program2b  ***************************************************/