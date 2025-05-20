/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:17:37 by tuaydin           #+#    #+#             */
/*   Updated: 2025/05/20 21:41:07 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*live(void *arg)
{
	t_philo	*philo;
	bool	alive;
	bool	must_eat;

	philo = (t_philo *)arg;
	if (philo->id % 2 != 0)
		ft_usleep(10);
	while (1)
	{
		pthread_mutex_lock(&philo->prog->state_mutex);
		alive = philo->alive;
		must_eat = philo->must_eat;
		pthread_mutex_unlock(&philo->prog->state_mutex);
		if (!alive || !must_eat)
			break ;
		philo_eat(philo);
		if (philo->prog->philo_count == 1)
			return (NULL);
		philo_sleep(philo);
	}
	return (NULL);
}

void	*try_to_live_alone(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(philo->l_fork);
	philo_print(philo, "has taken a fork");
	pthread_mutex_unlock(philo->l_fork);
	return (NULL);
}

char	*born_philos(t_program *prog)
{
	size_t	i;

	i = 0;
	prog->start_time = get_current_millis();
	prog->thread_count = 0;
	if (prog->philo_count == 1)
	{
		pthread_create(&prog->philos[prog->thread_count].thread, NULL,
			try_to_live_alone, &prog->philos[prog->thread_count]);
		prog->thread_count++;
	}
	while (prog->thread_count < prog->philo_count)
	{
		pthread_create(&prog->philos[prog->thread_count].thread, NULL, live,
			&prog->philos[prog->thread_count]);
		prog->thread_count++;
	}
	routine_check(prog);
	while (i < prog->philo_count)
	{
		pthread_join(prog->philos[i].thread, NULL);
		i++;
	}
	return (NULL);
}
