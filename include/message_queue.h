#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/msg.h>

int msg_create();

void msg_delete();

void msg_send(char *content);

char *msg_read();