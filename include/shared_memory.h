#include <stdio.h>
#include <sys/shm.h>

int shm_create(key_t key, size_t size);

int shm_delete(key_t key, int shmid);

int shm_getid(key_t key);