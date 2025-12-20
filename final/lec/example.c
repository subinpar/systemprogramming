#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

static void sigusr1_handler(int signo){
	printf("SIGUSR1 received signal number: %d\n", signo);
	fflush(stdout);
}
int main(void){
	pid_t pid=fork();
	
	if(pid<0){
		perror("fork");
		return 1;
	}
	
	if(pid==0){
		struct sigaction sa;
		sa.sa_handler=sigusr1_handler;
		sigemptyset(&sa.sa_mask);
		sa.sa_flags=0;
		
		if(sigaction(SIGUSR1, &sa, NULL)==-1){
			perror("sigaction");
			exit(1);
		}
		
		printf("Child PID: %d - waiting for parent's signal...\n", getpid());
		fflush(stdout);
		
		while(1) pause();
		
		return 0;
	}
	printf("Parent PID: %d, child PID: %d\n", getpid(), pid);
	fflush(stdout);
	
	sleep(1);
	printf("Parent: sending SIGUSR1 signal to child\n");
	fflush(stdout);
	kill(pid, SIGUSR1);
	
	sleep(1);
	printf("Parent: terminating child process (SIGTERM)\n");
	fflush(stdout);
	kill(pid, SIGTERM);
	
	waitpid(pid,NULL,0);
	return 0;
}					
