#include "philo.h"

t_program	init_program(int ac, char **av)
{
	size_t		i;
	t_program	rtn;

	rtn.philo_count = ft_atoi(av[1]);
	rtn.start_time = get_current_millis();
	rtn.philos = malloc(sizeof(t_philo) * rtn.philo_count);
	if (!rtn.philos)
		handle_error(MEMORY_FAILURE, EXIT_FAILURE);
	i = 0;
	while (i < rtn.philo_count)
	{
		rtn.philos[i].id = i + 1;
		rtn.philos[i].eaten_meals = 0;
		rtn.philos[i].last_meal = rtn.start_time;
		rtn.philos[i].time_to_die = ft_atoi(av[2]);
		rtn.philos[i].time_to_eat = ft_atoi(av[3]);
		rtn.philos[i].time_to_sleep = ft_atoi(av[4]);
		rtn.philos[i].meals_to_finish = -1;
		if (ac == 6)
			rtn.philos[i].meals_to_finish = ft_atoi(av[5]);		
		if (pthread_create(&rtn.philos[i].thread,
			NULL, philo_routine, &rtn.philos[i]) != 0)
			handle_error(THREAD_FAILURE, EXIT_FAILURE);
		i++;
	}
	return (rtn);
}
