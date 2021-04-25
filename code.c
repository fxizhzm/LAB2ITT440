#include <stdio.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <sys/wait.h> 
#include <unistd.h>

char name[8];

void jobDone(){
	printf("Job is done\n");
}

int main(void) {
	for (int i = 0; i < 4; i++) {
		pid_t pid = fork();
		
		if(pid == 0){			
			printf("Enter your name: ");
			scanf("%s", name);
			printf("Your name is %s\n", name);
		}
		
		else{
			wait(NULL);
			exit(0);
		}
	}
	jobDone();
	exit (0);
}