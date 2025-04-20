#include "philo.h"

void	handle_error(char *error_msg, int exit_code)
{
	printf("%s\n", error_msg);
	exit(exit_code);
}
