/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 02:18:42 by tuaydin           #+#    #+#             */
/*   Updated: 2025/05/16 12:26:18 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
	t_program	*program;

	size_t		i;

	check_errors(ac, av);
	program = init_program(ac, av);
	born_philos(program);

	i = 0;
	/*
	while (i < program.philo_count)
	{
		printf("Philosopher %zu:\n", i + 1);
		printf("  ID: %zu\n", program.philos[i].id);
		printf("  Time to die: %zu\n", program.philos[i].time_to_die);
		printf("  Time to eat: %zu\n", program.philos[i].time_to_eat);
		printf("  Time to sleep: %zu\n", program.philos[i].time_to_sleep);
		printf("  Meals to finish: %zi\n", program.philos[i].meals_to_finish);
		printf("  Last meal timestamp: %zu\n\n", program.philos[i].last_meal);
		i++;
	}*/
}
