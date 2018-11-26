#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/sysinfo.h>
#include <sys/utsname.h>
#include <time.h>
#include <unistd.h>

// All server functions

char *sf_date();       // dd/mm/yyy

char *sf_time();       // hh/mm/ss

char *sf_nodename();   // nome do nó

char *sf_sysname();    // nome do sistema

char *sf_release();    // versao da release

char *sf_version();    // versao do sistema

char *sf_machine();    // nome da maquina

char *sf_process();    // quantidade de processos

char *sf_freeram();    // quantidade de ram livre

char *sf_totalram();   // quantidade de ram total

char *sf_uptime();     // tempo de functionamento

char *sf_processors(); // quantidade de processadores