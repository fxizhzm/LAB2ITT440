#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/wait.h> 


char name[7];

void jobisFinish(){
	printf("Job Is Done\n");
}

int main(void) {
	for (int i = 5; i < 9; i++) {
		pid_t pid = fork();
		
		if(pid == 0){			
			printf("Enter Your Name: ");
			scanf("%s", name);
			printf("My Name Is %s\n", name);
		}
		
		else{
			wait(NULL);
			exit(0);
		}
	}
	jobisFinish();
	exit (0);
}