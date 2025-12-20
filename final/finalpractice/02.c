#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

static volatile sig_atomic_t alarm_fired=0;

void sigalrm_handler(int signo){
	(void)signo;
	alarm_fired=1;
}

int main(void){
	pid_t pid=fork();
	
	if(pid<0){
		perror("fork");
		return 1;
	}
	
	if(pid==0){
		int cnt=0;
		while(1){
			cnt++;
			printf("[Child] Counter: %d\n", cnt);
			fflush(stdout);
			sleep(1);
		}
		return 0;
	}
	
	struct sigaction sa;
	sa.sa_handler=sigalrm_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags=0;
	
	if(sigaction(SIGALRM, &sa, NULL)==-1){
		perror("sigaction");
		kill(pid, SIGKILL);
		return 1;
	}
	
	printf("[Parent] Child starts for 7 seconds\n");
	fflush(stdout);
	
	alarm(7);
	
	while(!alarm_fired){
		pause();
	}
	
	kill(pid, SIGTERM);
	waitpid(pid, NULL, 0);
	printf("[Parent] Child terminated\n");
	fflush(stdout);
	
	return 0;
}							
