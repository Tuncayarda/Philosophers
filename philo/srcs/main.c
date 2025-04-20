#include "philo.h"

int main(int ac, char **av)
{
	t_program program;

	check_errors(ac, av);
	program = init_program(ac, av);

	
	printf("Program Values:\n");
	printf("  Philo count:     %zu\n", program.philo_count);
	printf("  Time to die:     %zu\n", program.time_to_die);
	printf("  Time to eat:     %zu\n", program.time_to_eat);
	printf("  Time to sleep:   %zu\n", program.time_to_sleep);
	printf("  Meals to finish: %zu\n", program.meals_to_finish);
	printf("  Start time:      %zu ms\n", program.start_time);

	return (0);
}
