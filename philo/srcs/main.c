#include "philo.h"

int main(int ac, char **av)
{
    for (int i = 0; i < ac; i++)
        printf("arg[%d]: %s\n", i, av[i]);

    check_errors(ac, av);
}
