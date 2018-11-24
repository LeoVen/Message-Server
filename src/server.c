#include "shared_memory.h"
#include "sfunctions.h"

int main(int argc, char *argv[])
{
	char *date = sf_date();

	printf("%s\n", date);

	free(date);

	char *time = sf_time();

	printf("%s\n", time);

	free(time);

	printf("Exiting...\n");
	return 0;
}
