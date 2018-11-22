#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>


int main(int argc, char** argv){
	int i =0;

	printf("\nHello I am  the program run by exec()\n");

	if(argc > 1)
	{
		while(i < argc)
		{
			printf("arguments:: %s\n",argv[i]);
			i++;
		}
		
	}

	
return 0;
}
