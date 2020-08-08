/*
  *********TMN3053/TMN4133-System Programming**********
  *                                                   *
  *              *******************                  *
  *              *  Group Project  *                  *
  *              *******************                  *
  *                                                   *
  *   Abu Sayed                      59395            *
  *   Nur Addina binti Baslan        50738            *
  *   Mohamad Faridzuan bin Roslan   42107            *
  *   Izham Wahidan bin Kamal        41491            *
  *****************************************************
*/


//Preprocessor Directives
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <wait.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{

	int pid, childpid, status, exec;

	//Display the Current Working Directory

	char cwd[1024];

        if (getcwd(cwd, sizeof(cwd)) == NULL)

		perror("getcwd() error()");

        else
                printf("\nDirectory: %s\n", cwd);


	//Original or Parent Process
        printf("\n%s I'm a process\n", argv[0]);
	printf("\n%s My PID is %d and My parent's PID is %d. \n", argv[0], getpid(), getppid() );
	printf("\n%s Forking a child off.\n", argv[0]);

	//Create Child Process with fork() system call
	pid = fork();

	//Error handling for fork() system call	
	if(pid < 0)

        {
	
		perror("Fork Failed");
		exit(1);
		return -1;
	
	}

 

	//This is The child process	
        if(pid == 0)
        {

		printf("\nChild: I have been created!\n");
		printf("\nChild: My PID is %d and my parent's PID is %d. \n\n", getpid(), getppid() );

		sleep(5); //sleep for 5 seconds
		
		/*----------- Child Exec now with program2b----------*/
	   	
		char* args[] ={"./program2b", "Arg1", "Arg2", (char *)0};
		exec = execvp("./program2b", args);

		//Error handling for execvp() system call
		if(exec < 0)
			
                   {
                       perror("Exec Failed");
			exit(1);
			return -2;
                   }
			
	}
                      
                sleep(1); //sleep for 1 seconds

		//Display the system process chart
		printf("\n%s Printing System Process chart using \"ps -al\"\n\n\n", argv[0]);
		system ("ps -al");

		printf("\n%s Waiting for my child to die\n\n\n", argv[0]);
		
		//Declare the wait() system call
		childpid = wait(&status);

		//Child terminate and display the status code
	        printf("\n%s Child exited with status code %d\n", argv[0], status >> 8);

		//Process terminate
	        printf("%s I am going to die.\n\n", argv[0]);
                return 0;
	}
	
/********************************************  The End of Project  ***********************************************/
