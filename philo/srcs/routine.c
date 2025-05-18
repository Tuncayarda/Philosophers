/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:17:37 by tuaydin           #+#    #+#             */
/*   Updated: 2025/05/18 07:50:31 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	born_check(t_program *prog)
{
	pthread_mutex_lock(&prog->prog_mutex);
	while (1)
	{ 
		if (prog->philo_count == prog->thread_count)
			break;
	}
	pthread_mutex_unlock(&prog->prog_mutex);
}

void	*live(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	born_check(philo->prog);
	philo->prog->start_time = get_current_millis();
	if (philo->id % 2 != 0)
		ft_usleep(10);
	while (1)
	{
		philo_eat(philo);
		philo_sleep(philo);
	}
	return (NULL);
}

void	born_philos(t_program *prog)
{
	size_t	i;

	i = 0;
	prog->thread_count = 0;
	while (prog->thread_count < prog->philo_count)
	{
		pthread_create(
			&prog->philos[prog->thread_count].thread, 
			NULL, live, &prog->philos[prog->thread_count]);
		prog->thread_count++;
	}
	routine_check(prog);
}
