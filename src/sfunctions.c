// server functions

#include "sfunctions.h"
#include <time.h>

char *sf_date()
{
	time_t now;

	time(&now);

	struct tm *ct = localtime(&now);

	char *str = malloc(sizeof(char) * 40);

	strftime(str, 20, "%d/%m/%Y", ct);

	return str;
}

char *sf_time()
{
	time_t now;

	time(&now);

	struct tm *ct = localtime(&now);

	char *str = malloc(sizeof(char) * 40);

	strftime(str, 20, "%X", ct);

	return str;
}

char *sf_nodename()
{

	return NULL;
}

char *sf_sysname()
{

	return NULL;
}

char *sf_release()
{

	return NULL;
}

char *sf_version()
{

	return NULL;
}

char *sf_machine()
{

	return NULL;
}

char *sf_process()
{

	return NULL;
}

char *sf_freeram()
{

	return NULL;
}

char *sf_totalram()
{

	return NULL;
}

char *sf_uptime()
{

	return NULL;
}

char *sf_processors()
{

	return NULL;
}