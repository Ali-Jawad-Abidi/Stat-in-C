#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// This demonstrates how to access command line arguments
int main(int argc, char* argv[]) {
  int i;
   if(argc == 1|| argc >2) {
		if (argc>2){
			puts("Incorrect Number of Arguments");
			exit(0);
		}
		else if(argc==1){
        printf("Usage: %s [directory]\n", *argv);
        exit(0);
		}
    }
	

	int result = access(argv[1],F_OK);
	if(result==0)
	printf("%s exists in %s\n",argv[1],get_current_dir_name());
	else
	printf("%s doesnot exists in current directory\n",argv[1]);

  //for (i=0; i<argc; i++) {
  //  printf("argv[%d] = %s\n", i, argv[i]);
  //}
  return 0;
}
