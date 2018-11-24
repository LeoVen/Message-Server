#include "message_queue.h"

int msg_create()
{
	key_t msg_key = ftok("/home", 'a');

	// Creating message queue
	int message_id = msgget(msg_key, 0600 | IPC_CREAT);

	// Failed
	if (message_id == -1)
		printf("Failed to create message queue\n");

	return message_id;
}

void msg_delete()
{
	key_t msg_key = ftok("/home", 'a');

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

void msg_send(char *content);

char *msg_read();