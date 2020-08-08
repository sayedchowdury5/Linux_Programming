/* preprocessor directives */
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

//main function
int main()
{
	/*Variable declaration */
        char c[1];
        int in, out;
	int total, position, nread;

	/*Open a file with read mode */
	in = open("1MB.txt", O_RDONLY);

	/* Create a file for writing only with user permission */
        out = open("copyfileRandom 100.txt", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);

	/* manipulate total size of the file */
	total = (long long)lseek(in, 0, SEEK_END);

	/* display the file size */
	printf("Total file size is: %11d\n", total);

	/* move the file pointer */
	position = lseek(in, 100, SEEK_SET);

	/* calculate the number of bytes are copying */
	nread = total-position;


	/* while loop-for copying the content of the file using parameter size */

        while(read(in, c , 1) == 1)         //read data from a file into a buffer

                write(out, c , 1);         //write data from a buffer into a file

	
	/* display the number of bytes are copied */
	printf("Total%11d bytes are copied.\n", nread);    


        exit(0);                          //exit the program while executed

}

