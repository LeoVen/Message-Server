#include "macros.h"
#include "cfunctions.h"
#include "message_queue.h"

int main(int argc, char const *argv[])
{
	char *input = malloc(sizeof(char) * BUFF_SIZE);

	char c = ' ';

	int count;

	printf("Enter messages to sendo to the server\n");

	while (1)
	{
		count = 0;

		printf("> ");

		// Gets characters until it reaches a newline or a maximum of BUFF_SIZE
		while (c != '\n')
		{
			c = getchar();

			if (count < BUFF_SIZE && c != '\n')
				input[count++] = c;
		}

		c = ' ';

		input[count] = '\0';

		if (strcmp(input, "copyright") == 0)
		{
			cf_copyright();
		}
		else if (strcmp(input, "help") == 0)
		{
			cf_help();
		}
		else if (strcmp(input, "exit") == 0)
		{
			break;
		}
		// If it is not a client function, send to server
		else
		{
			// Send user input to message queue
			msg_send(input);

			if (strcmp(input, "shutdown") == 0)
				break;
		}

		// TODO
		// Get response

	}

	free(input);

	pid_t client_pid = getpid();

	printf("My PID: %d\n", client_pid);

	return 0;
}