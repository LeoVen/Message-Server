#include "macros.h"
#include "sfunctions.h"
#include "message_queue.h"
#include "shared_memory.h"

int main(int argc, char *argv[])
{
	printf("Initializing server\n");

	// Since there is only one message queue, the key will always be the same
	msg_create();

	char *command = NULL;
	char *result = NULL;

	// PID destination taken from the message queue
	pid_t mq_pid = 0;

	// if it is a valid command to be sent to the memory segment
	bool valid = false;

	key_t k_result   = ftok(FILE_NAME, PROJ_RESULT);
	key_t k_receiver = ftok(FILE_NAME, PROJ_RECEIVER);

	int shm_id_result   = shm_create(k_result, BUFF_SIZE);
	int shm_id_receiver = shm_create(k_receiver, sizeof(int));

	// Server can't work without all memory segments
	if (shm_id_receiver == -1 || shm_id_receiver == -1)
	{
		printf("Memory segment error\n");

		return -1;
	}

	char *memory_content = shmat(shm_id_result, 0, 0);
	pid_t *shm_pid = shmat(shm_id_receiver, 0, 0);

	while (1)
	{
		command = msg_read(&mq_pid);

		if (command != NULL)
		{
			// List of commands
			if (strcmp(command, "date") == 0)
			{
				result = sf_date();
				
				valid = true;
			}
			else if (strcmp(command, "time") == 0)
			{
				result = sf_time();

				valid = true;
			}
			else if (strcmp(command, "nodename") == 0)
			{
				result = sf_nodename();
				
				valid = true;
			}
			else if (strcmp(command, "sysname") == 0)
			{
				result = sf_sysname();
				
				valid = true;
			}
			else if (strcmp(command, "release") == 0)
			{
				result = sf_release();
				
				valid = true;
			}
			else if (strcmp(command, "version") == 0)
			{
				result = sf_version();
				
				valid = true;
			}
			else if (strcmp(command, "machine") == 0)
			{
				result = sf_machine();
				
				valid = true;
			}
			else if (strcmp(command, "process") == 0)
			{
				result = sf_process();
				
				valid = true;
			}
			else if (strcmp(command, "freeram") == 0)
			{
				result = sf_freeram();
				
				valid = true;
			}
			else if (strcmp(command, "totalram") == 0)
			{
				result = sf_totalram();
				
				valid = true;
			}
			else if (strcmp(command, "uptime") == 0)
			{
				result = sf_uptime();
				
				valid = true;
			}
			else if (strcmp(command, "processors") == 0)
			{
				result = sf_processors();
				
				valid = true;
			}
			else if (strcmp(command, "shutdown") == 0)
			{
				printf("Server shutdown\n");

				free(result);
				free(command);

				valid = false;

				break;
			}
			else 
			{
				printf("Invalid command\n");

				free(command);

				*shm_pid = INVALID_COMMAND;

				valid = false;
			}

			if (valid)
			{
				strcpy(memory_content, result);

				*shm_pid = mq_pid;

				free(result);
				result = NULL;

				free(command);
			}
		}
	}

	shmdt(shm_pid);
	shmdt(memory_content);

	msg_delete();

	shm_delete(k_result, shm_id_result);
	shm_delete(k_receiver, shm_id_receiver);

	printf("Exiting...\n");

	return 0;
}
