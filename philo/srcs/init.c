#include "philo.h"

t_program	init_program(int ac, char **av)
{
	int			i;
	t_program	rtn;

	rtn.philo_count = ft_atoi(av[1]);
	rtn.time_to_die = ft_atoi(av[2]);
	rtn.time_to_eat = ft_atoi(av[3]);
	rtn.time_to_sleep = ft_atoi(av[4]);
	rtn.meals_to_finish = -1;
	rtn.start_time = get_current_millis();
	if (ac == 6)
		rtn.meals_to_finish = ft_atoi(av[5]);
	i = 0;
	rtn.philos = malloc(sizeof(t_philo) * rtn.philo_count);
	if (!rtn.philos)
		handle_error(MEMORY_FAILURE, EXIT_FAILURE);
	while (i < rtn.philo_count)
	{
		rtn.philos[i].id = i + 1;
		rtn.philos[i].eaten_meals = 0;
		rtn.philos[i].last_meal = rtn.start_time;
		if (pthread_create(&rtn.philos[i].thread,
			NULL, philo_routine, &rtn) != 0)
			handle_error(MEMORY_FAILURE, EXIT_FAILURE);
	}
	return (rtn);
}
