/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 02:18:42 by tuaydin           #+#    #+#             */
/*   Updated: 2025/05/18 08:29:34 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
	t_program	*program;
	char		*error_msg;

	error_msg = NULL;
	error_msg = check_errors(ac, av);
	if (error_msg != NULL)
	{
		printf("ERROR: %s\n", error_msg);
		return (1);
	}
	error_msg = init_program(&program ,ac, av);
	if (error_msg != NULL)
	{
		printf("ERROR: %s\n", error_msg);
		return (1);
	}
	born_philos(program);

	return (0);
}
