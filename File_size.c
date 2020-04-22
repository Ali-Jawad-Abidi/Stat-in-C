#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
int main(int argc, char **argv) {
    if(argc == 1 || argc > 2) {
		if(argc>2){
		puts("error, must have one directory path");
		return 1;		
			}		
        printf("Usage: %s [directory]\n", *argv);
        exit(0);
    }
    





	struct dirent *dp;
	struct stat stats;
	int count=0;
	char * dir=(char*)calloc(100,sizeof(char));
    DIR *dirp = opendir(argv[1]);


	if(dirp==NULL){

	printf("%s doesnot exists\n",argv[1]);
	return 1;
	}
    while ((dp = readdir(dirp)) != NULL) {
		strcpy(dir,argv[1]);
		stat(strcat(dir,dp->d_name),&stats);
		//printf ("%s\n\n",);
        printf("Getting info for %s%s\n",argv[1],dp->d_name);
		printf("Size of this file is %ld\n",stats.st_size);
		if(stats.st_size>1000)
			count++;
    }

	printf("%d files have size greater than 1000\n",count);
    closedir(dirp);
    return 0;
}
