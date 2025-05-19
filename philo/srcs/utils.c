/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 05:50:56 by tuaydin           #+#    #+#             */
/*   Updated: 2025/05/19 20:48:57 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	printf("%zu %zu %s\n", get_current_millis() - p->start_time, philo->id + 1,
		msg);
	pthread_mutex_unlock(&p->print_mutex);
}
