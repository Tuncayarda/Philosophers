#include "philo.h"

void	handle_error(char *error_msg, int exit_code)
{
	printf("%s\n", error_msg);
	exit(exit_code);
}

void	philo_print(t_philo *philo, char *msg)
{
	printf("%zu %zu %s\n", get_current_millis() - philo->prog->start_time, philo->id, msg);
}