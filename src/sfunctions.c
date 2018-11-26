// server functions
#include "sfunctions.h"
#include "macros.h"

char *sf_date()
{
	time_t now;

	time(&now);

	struct tm *ct = localtime(&now);

	char *str = malloc(sizeof(char) * BUFF_SIZE);

	strftime(str, BUFF_SIZE, "%d/%m/%Y", ct);

	return str;
}

char *sf_time()
{
	time_t now;

	time(&now);

	struct tm *ct = localtime(&now);

	char *str = malloc(sizeof(char) * BUFF_SIZE);

	strftime(str, BUFF_SIZE, "%X", ct);

	return str;
}

char *sf_nodename()
{
	struct utsname uts;

	uname(&uts);

	char *str = malloc(sizeof(char) * BUFF_SIZE);

	sprintf(str, "%s", uts.nodename);

	return str;
}

char *sf_sysname()
{
	struct utsname uts;

	uname(&uts);

	char *str = malloc(sizeof(char) * BUFF_SIZE);

	sprintf(str, "%s", uts.sysname);

	return str;
}

char *sf_release()
{
	struct utsname uts;

	uname(&uts);

	char *str = malloc(sizeof(char) * BUFF_SIZE);

	sprintf(str, "%s", uts.release);

	return str;
}

char *sf_version()
{
	struct utsname uts;

	uname(&uts);

	char *str = malloc(sizeof(char) * BUFF_SIZE);

	sprintf(str, "%s", uts.version);

	return str;
}

char *sf_machine()
{
	struct utsname uts;

	uname(&uts);

	char *str = malloc(sizeof(char) * BUFF_SIZE);

	sprintf(str, "%s", uts.machine);

	return str;
}

char *sf_process()
{
	struct sysinfo info;

	sysinfo(&info);

	char *str = malloc(sizeof(char) * BUFF_SIZE);

	sprintf(str, "%d", info.procs);

	return str;
}

char *sf_freeram()
{
	struct sysinfo info;

	sysinfo(&info);

	char *str = malloc(sizeof(char) * BUFF_SIZE);

	sprintf(str, "%ld Kb", info.freeram * info.mem_unit / 1024);

	return str;
}

char *sf_totalram()
{
	struct sysinfo info;

	sysinfo(&info);

	char *str = malloc(sizeof(char) * BUFF_SIZE);

	sprintf(str, "%ld Kb", info.totalram * info.mem_unit / 1024);

	return str;
}

char *sf_uptime()
{
	struct sysinfo info;

	sysinfo(&info);

	char *str = malloc(sizeof(char) * BUFF_SIZE);

	int days, hours, mins;
	long int  seconds = info.uptime % 60;

	days = info.uptime / 86400;
    hours = (info.uptime / 3600) - (days * 24);
	mins = (info.uptime / 60) - (days * 1440) - (hours * 60);

	char *h = (hours < 10) ? "0" : "";
	char *m = (mins < 10) ? "0" : "";
	char *s = (seconds < 10) ? "0" : "";

	sprintf(str, "%d - %s%d:%s%d:%s%ld", days, h, hours, m, mins, s, seconds);

	return str;
}

char *sf_processors()
{
	char *str = malloc(sizeof(char) * BUFF_SIZE);

	sprintf(str, "%d", get_nprocs());

	return str;
}