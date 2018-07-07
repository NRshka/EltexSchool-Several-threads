#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>



void print_pid(){
	int pid = getpid();
	int ppid = getppid();
	printf("I'm thread with %d PID. My parent with %d PID.\n", pid, ppid);
	pthread_exit(0);
}

int main(int argc, char **argv)
{
	char number[11];
	fgets(number, 11, stdin);
	int num = atoi(number);
	for(int i = 0; i < num; i++){
		pthread_t pid;
		pthread_create(&pid, NULL, print_pid, NULL);
		pthread_join(pid, NULL);
	}
	printf("give me a bottle of rum!\n");
	return 0;
}
