#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char** argv){

	pid_t pid = fork();
	int p[2];
	pipe(p); // Pipe
	char rec[128]; // Recieve buffer
		// Parent Process
	if(pid != 0)
	{
		printf("Hello I am the Parent process:: Sending \"This is a message\" \n");
		close(p[0]);
		if (write(p[1],"This is a message\n",19) == -1)
		{
			printf("error writing to the pipe");
		}
		
	}
		// Child Process
	else
	{
		printf("\nHello I am the child process\n");
		close(p[1]);
		int count = read(p[0],&rec,18);
		//rec[count+1] = '\0';
		printf("count:: %d\n", count);
		printf("Recieved msg:: %s",rec); 
		execle("./proc2","./proc2","Hello I am Malinda",NULL,NULL);
	}

return 0;
}
