#include <sys/msg.h>
#include "sfunctions.h"
#include "shared_memory.h"

int main(int argc, char *argv[])
{
	char *date = sf_date();
	printf("%s\n", date);
	free(date);

	char *time = sf_time();
	printf("%s\n", time);
	free(time);

	char *nodename = sf_nodename();
	printf("%s\n", nodename);
	free(nodename);

	char *sysname = sf_sysname();
	printf("%s\n", sysname);
	free(sysname);

	char *release = sf_release();
	printf("%s\n", release);
	free(release);

	char *version = sf_version();
	printf("%s\n", version);
	free(version);

	char *machine = sf_machine();
	printf("%s\n", machine);
	free(machine);

	char *process = sf_process();
	printf("%s\n", process);
	free(process);

	char *freeram = sf_freeram();
	printf("%s\n", freeram);
	free(freeram);

	char *totalram = sf_totalram();
	printf("%s\n", totalram);
	free(totalram);

	char *uptime = sf_uptime();
	printf("%s\n", uptime);
	free(uptime);

	char *processors = sf_processors();
	printf("%s\n", processors);
	free(processors);

	msg_create();

	sleep(10);

	msg_delete();

	printf("Exiting...\n");
	return 0;
}
