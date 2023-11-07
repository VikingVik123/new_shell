#include "main.h"

void _exits(const char *message)
{
	perror(message);
	exit(1);
}
