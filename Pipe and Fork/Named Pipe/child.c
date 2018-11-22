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
	
	char rec[128];
		fd = open(fifo,O_RDONLY);
		read(fd,rec,128);
		close(fd);			
	printf("MSG:: %s\n",rec);
	
	return 0;	
}
