#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(){
	int fd;

	char *fifo = "./fifo";
	mkfifo(fifo,0666);
	
	char msg[] = "Hello this is my message";
	char rec[128];
	if(fork() != 0)
	{
		printf("Parent Process.....\n");
		fd = open(fifo,O_WRONLY);
		write(fd,msg,strlen(msg)+1);
		close(fd);			
	}
	else
	{	
		printf("Child Process.....\n");
		execl("./app","./app",NULL);
	}
	
	return 0;
}
