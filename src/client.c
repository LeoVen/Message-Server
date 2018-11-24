#include "cfunctions.h"

int main(int argc, char const *argv[])
{
	printf("Hello World!\n");
	printf("I'm the client and I'll be sending commands to the server\n");
	
	cf_help();
	
	cf_copyright();

	pid_t client_pid = getpid();

	printf("My PID: %d\n", client_pid);

	return 0;
}