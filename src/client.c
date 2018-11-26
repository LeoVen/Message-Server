#include "macros.h"
#include "cfunctions.h"
#include "message_queue.h"
#include "shared_memory.h"

int main(int argc, char const *argv[])
{
	char *input = malloc(sizeof(char) * BUFF_SIZE);

	pid_t client_pid = getpid();

	// Locating memory segments
	key_t k_result   = ftok(FILE_NAME, PROJ_RESULT);
	key_t k_receiver = ftok(FILE_NAME, PROJ_RECEIVER);

	int shm_id_result   = shm_getid(k_result);
	int shm_id_receiver = shm_getid(k_receiver);

	if (shm_id_receiver == -1 || shm_id_receiver == -1)
	{
		printf("Memory segment error\n");

		return -1;
	}

	char *memory_content = shmat(shm_id_result, 0, 0);
	pid_t *shm_pid = shmat(shm_id_receiver, 0, 0);

	if (memory_content == (char*)-1 || shm_pid == (pid_t*)-1)
	{
		printf("Memory segment error\n");

		return -1;
	}

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

			if (count < BUFF_SIZE - 1 && c != '\n')
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

			clock_t begin = clock();
			clock_t end;

			// This will prevent from the same client from reading its message
			// too soon if the last message was from the same client
			*shm_pid = 0;

			// Wait for response
			while (1)
			{
				if (*shm_pid == client_pid)
				{
					printf("%s\n", memory_content);

					break;
				}

				if (*shm_pid == -1)
				{
					printf("Invalid command\n");

					break;
				}

				end = clock();

				if ((double)(end - begin)/CLOCKS_PER_SEC > TIMEOUT_LIMIT)
				{
					printf("Response timeout\n");

					break;
				}
			}
		}
	}

	shmdt(shm_pid);
	shmdt(memory_content);

	free(input);

	return 0;
}