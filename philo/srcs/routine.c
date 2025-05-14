/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:17:37 by tuaydin           #+#    #+#             */
/*   Updated: 2025/05/14 17:09:04 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	born_check(t_program *prog)
{
	while (1)
	{ 
		if (prog->philo_count == prog->thread_count)
			break;
	}
}

void	*live(void *arg)
{
	t_program	*prog;

	prog = (t_program *)arg;
	born_check(prog);
	printf("%s", "slm\n");
	
	
	return (NULL);
}

void	born_philos(t_program *prog)
{
	size_t	i;

	i = 0;
	while (prog->thread_count < prog->philo_count)
	{
		pthread_create(&prog->philos[prog->thread_count].thread, NULL, live, prog);
		prog->thread_count++;
	}

	while (i < prog->philo_count)
	{
		pthread_join(prog->philos[i].thread, NULL);
		i++;
	}
}
