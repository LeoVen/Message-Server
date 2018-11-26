#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/msg.h>

// Not required, but older versions of POSIX might need it
#include <sys/types.h>
#include <sys/ipc.h>

int msg_create();

void msg_delete();

void msg_send(char *content);

char *msg_read(pid_t *pid);