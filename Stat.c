#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>


void printFileProperties(struct stat stats);


int main(int argc, char *argv[]){
    struct stat stats;


	if(argc < 2){
	printf("Usage: %s [directory]....\nExiting....\n",argv[0]);
	return 1;
	}

	printf("There are %d arguments\n",argc);

	for(int t=1;t<argc;t++){


		if (stat(argv[t], &stats) == 0) {
		
	
			printf("File name is: %s\n",argv[t]); 
			printf("File size: %d\n", stats.st_size);
			printf("User ID is : %d\n", stats.st_uid);
			printf("Total allocated blocks are : %d\n", stats.st_blocks);
			if(S_ISREG(stats.st_mode)==1)
				puts("Type of file is : Regular\n\n");
			else
				puts("Type of file is : Directory\n\n");
		}
		else
		{
			printf("Unable to get file properties.\n");
			printf("Please check whether '%s' file exists.\n", argv[1]);
		}
	}
    return 0;
}

