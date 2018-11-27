#include "cfunctions.h"

void cf_copyright()
{
	printf("╔══════════════════════════════════════════════════════════╗\n");
	printf("║ Copyright                                                ║\n");
	printf("║                                                          ║\n");
	printf("║                                                          ║\n");
	printf("║     Eduardo Vencovsky       201710281                    ║\n");
	printf("║     Guilherme Pinazza       201710351                    ║\n");
	printf("║     Leonardo Vencovsky      201710276                    ║\n");
	printf("║                                                          ║\n");
	printf("╚══════════════════════════════════════════════════════════╝\n");
}

void cf_help()
{
	printf("╔══════════════════════════════════════════════════════════╗\n");
	printf("║ Available Commands                                       ║\n");
	printf("║                                                          ║\n");
	printf("║ # Server                                                 ║\n");
	printf("║                                                          ║\n");
	printf("║     Command Name    Description                          ║\n");
	printf("║     ------------    -----------                          ║\n");
	printf("║     - date          Returns current date (dd/mm/yy)      ║\n");
	printf("║     - time          Returns current time (hh/mm/ss)      ║\n");
	printf("║     - nodename      Returns the node name                ║\n");
	printf("║     - sysname       Operating system name                ║\n");
	printf("║     - release       Operating system release version     ║\n");
	printf("║     - version       The operating system version         ║\n");
	printf("║     - machine       Hardware identifier                  ║\n");
	printf("║     - process       How many processes are running       ║\n");
	printf("║     - freeram       Total free ram in kilobytes          ║\n");
	printf("║     - totalram      Total RAM in kilobytes               ║\n");
	printf("║     - uptime        How long the machine is running      ║\n");
	printf("║     - processors    Amount of physical cores             ║\n");
	printf("║                                                          ║\n");
	printf("║ # Client                                                 ║\n");
	printf("║                                                          ║\n");
	printf("║     Command Name    Description                          ║\n");
	printf("║     ------------    -----------                          ║\n");
	printf("║     - copyright     Shows copyright                      ║\n");
	printf("║     - help          Shows this help menu                 ║\n");
	printf("║     - exit          Closes client program                ║\n");
	printf("║                                                          ║\n");
	printf("║ # ServerClient                                           ║\n");
	printf("║                                                          ║\n");
	printf("║     Command Name    Description                          ║\n");
	printf("║     ------------    -----------                          ║\n");
	printf("║     - shutdown      Closes both this client and server   ║\n");
	printf("║                                                          ║\n");
	printf("╚══════════════════════════════════════════════════════════╝\n");
}