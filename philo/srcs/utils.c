/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 05:50:56 by tuaydin           #+#    #+#             */
/*   Updated: 2025/05/20 21:27:26 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_current_millis(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (0);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_usleep(size_t mls)
{
	size_t	start;

	start = get_current_millis();
	while (get_current_millis() - start < mls)
		usleep(500);
}

void	set_program_free(t_program *program)
{
	size_t	i;

	i = 0;
	while (i < program->philo_count)
	{
		pthread_mutex_destroy(&program->forks[i]);
		i++;
	}
	free(program->forks);
	free(program->philos);
	free(program);
}

void	philo_print(t_philo *philo, char *msg)
{
	t_program	*p;
	bool		done;

	p = philo->prog;
	pthread_mutex_lock(&p->state_mutex);
	done = p->finished;
	pthread_mutex_unlock(&p->state_mutex);
	if (done)
		return ;
	pthread_mutex_lock(&p->print_mutex);
	printf("%zu %zu %s\n", get_current_millis() - p->start_time,
		philo->id + 1, msg);
	pthread_mutex_unlock(&p->print_mutex);
}
