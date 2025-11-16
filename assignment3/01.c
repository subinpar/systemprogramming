#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
	int n;
	pid_t *child;
	pid_t pid;
	
	printf("Input the number of child processes: ");
	scanf("%d", &n);	
	
	if(n<=0){
		printf("Wrong input. Input a number greater than 0.\n");
		return 1;
	}
	
	child=(pid_t *)malloc(sizeof(pid_t)*n);
	if(child==NULL){
		perror("malloc error");
		return 1;
	}	
	
	for (int i=0; i<n; i++){
		pid=fork();
		
		if(pid<0){
			perror("fork error");
			free(child);
			return 1;
		}
		else if(pid==0){
			printf("I am %dth child. PID=%d, Parent PID=%d\n", i+1, (int)getpid(), (int)getppid());
			exit(0);
		}
		else{
			child[i]=pid;
		}
	}
	
	for(int i=0; i<n; i++){
		wait(NULL);
	}
	
	printf("[Parent %d] All children have terminated\n", (int)getpid());
	printf("Childs pid: ");
	for(int i=0; i<n; i++){
		printf("%d ", (int)child[i]);
	}
	printf("\n");
	
	free(child);
	return 0;
}						
			
				
