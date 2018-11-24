#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/msg.h>
#include <unistd.h>

int shm_create(key_t key, size_t size);

int shm_delete(key_t key, int shmid);

int shm_getid(key_t key);