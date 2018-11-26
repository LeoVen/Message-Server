#include "macros.h"
#include "message_queue.h"

int msg_create()
{
	key_t msg_key = ftok(FILE_NAME, PROJ_QUEUE);

	// Creating message queue
	int message_id = msgget(msg_key, 0600 | IPC_CREAT);

	// Failed
	if (message_id == -1)
		printf("Failed to create message queue\n");

	printf("Created message queue of id %d\n", message_id);

	return message_id;
}

void msg_delete()
{
	key_t msg_key = ftok(FILE_NAME, PROJ_QUEUE);

	// Getting message queue
	int message_id = msgget(msg_key, 0);

	if (message_id == -1)
		printf("Failed to locate message queue\n");
	else
	{
		// Removing queue
		int result = msgctl(message_id, IPC_RMID, 0);

		if (result == 0)
			printf("Removed message queue of id %d\n", message_id);
		else
			printf("Failed to remove message queue of id %d\n", message_id);
	}
}

// The size of content must be at most BUFF_SIZE
// This is treated in the client input
void msg_send(char *content)
{
	key_t msg_key = ftok(FILE_NAME, PROJ_QUEUE);

	// Getting message queue
	int message_id = msgget(msg_key, 0);

	if (message_id == -1)
		printf("Failed to locate message queue\n");
	else
	{
		// Writing to message queue
		int result = msgsnd(message_id, content, sizeof(char) * BUFF_SIZE, 0);

		if (result == -1)
			printf("Failed to write to message queue of id %d\n",
				message_id);
	}
}

// Parameter is the process id of the removed message
char *msg_read(pid_t *pid)
{
	key_t msg_key = ftok(FILE_NAME, PROJ_QUEUE);

	// Getting message queue
	int message_id = msgget(msg_key, 0);

	if (message_id == -1)
	{
		printf("Failed to locate message queue\n");

		return NULL;
	}
	else
	{
		char message[BUFF_SIZE];

		// Reading from queue
		int result = msgrcv(message_id, message, sizeof(char) * BUFF_SIZE,
			0, 0);

		if (result == -1)
		{
			printf("Failed to read message queue of id %d\n", message_id);

			return NULL;
		}
		else
		{
			struct msqid_ds info;

			// Getting info from message queue
			result = msgctl(message_id, IPC_STAT, &info);

			if (result == 0)
				printf("Read from PID %d from the message queue of id %d\n",
					info.msg_lspid, message_id);
			else
				printf("Read from the message queue of id %d\n", message_id);

			*pid = info.msg_lspid;

			return strdup(message);
		}
	}
}