#include "macros.h"
#include "sfunctions.h"
#include "message_queue.h"
#include "shared_memory.h"

int main(int argc, char *argv[])
{
	printf("Initializing server\n");

	msg_create();

	char *command = NULL;
	char *result = NULL;

	// PID destination
	pid_t pid = 0;

	while (1)
	{
		command = msg_read(&pid);

		if (command != NULL)
		{
			// List of commands
			if (strcmp(command, "date") == 0)
			{
				result = sf_date();
				
				printf("%s\n", result);
				
				free(result);
				result = NULL;
			}
			else if (strcmp(command, "time") == 0)
			{
				result = sf_time();

				printf("%s\n", result);

				free(result);
				result = NULL;
			}
			else if (strcmp(command, "nodename") == 0)
			{
				result = sf_nodename();
				
				printf("%s\n", result);
				
				free(result);
				result = NULL;
			}
			else if (strcmp(command, "sysname") == 0)
			{
				result = sf_sysname();
				
				printf("%s\n", result);
				
				free(result);
				result = NULL;
			}
			else if (strcmp(command, "release") == 0)
			{
				result = sf_release();
				
				printf("%s\n", result);
				
				free(result);
				result = NULL;
			}
			else if (strcmp(command, "version") == 0)
			{
				result = sf_version();
				
				printf("%s\n", result);
				
				free(result);
				result = NULL;
			}
			else if (strcmp(command, "machine") == 0)
			{
				result = sf_machine();
				
				printf("%s\n", result);
				
				free(result);
				result = NULL;
			}
			else if (strcmp(command, "process") == 0)
			{
				result = sf_process();
				
				printf("%s\n", result);
				
				free(result);
				result = NULL;
			}
			else if (strcmp(command, "freeram") == 0)
			{
				result = sf_freeram();
				
				printf("%s\n", result);
				
				free(result);
				result = NULL;
			}
			else if (strcmp(command, "totalram") == 0)
			{
				result = sf_totalram();
				
				printf("%s\n", result);
				
				free(result);
				result = NULL;
			}
			else if (strcmp(command, "uptime") == 0)
			{
				result = sf_uptime();
				
				printf("%s\n", result);
				
				free(result);
				result = NULL;
			}
			else if (strcmp(command, "processors") == 0)
			{
				result = sf_processors();
				
				printf("%s\n", result);
				
				free(result);
				result = NULL;
			}
			else if (strcmp(command, "shutdown") == 0)
			{
				printf("Server shutdown\n");

				free(result);
				free(command);

				break;
			}
			else 
			{
				printf("Invalid command\n");
			}

			free(command);
		}
	}

	msg_delete();

	printf("Exiting...\n");

	return 0;
}
