#include "philo.h"

void	terminate_prog(char *msg, int exit_code)
{
	printf("%s\n", msg);
	//Something to clear memory
	exit(exit_code);
}

void	handle_error(size_t error_code)
{
	if (error_code == PHILO_COUNT_UNDERFLOW)
		terminate_prog("PHILO COUNT UNDERFLOW", 1);
	if (error_code == PHILO_COUNT_OVERFLOW)
		terminate_prog("PHILO COUNT OVERFLOW", 1);
	if (error_code == INT_OVERFLOW)
		terminate_prog("INT OVERFLOW", 1);
	if (error_code == ARGUMENT_ERROR)
		terminate_prog("ARGUMENT ERROR", 1);
}
