#include <stdio.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <sys/wait.h> 
#include <unistd.h>

char name[8];

void jobisDone(){
	printf("Job Is Done\n");
}

int main(void) {
	for (int i = 0; i < 4; i++) {
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
	jobisDone();
	exit (0);
}