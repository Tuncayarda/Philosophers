#include "philo.h"

size_t	get_current_millis(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		handle_error("GET TIME OF DAY ERROR" , 1);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_usleep(size_t mls)
{
	size_t	start;

	start = get_current_millis();
	while (get_current_millis() - start < mls)
		usleep(500);
}
