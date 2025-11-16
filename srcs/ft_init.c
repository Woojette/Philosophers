#include "philosophers.h"

int ft_init_av(int ac, char **av, t_table *table)
{
	int	error;

	error = 0;
	table->nbr_philo = ft_atoi(av[1], &error);
	table->time_die = ft_atoi(av[2], &error);
	table->time_to_eat = ft_atoi(av[3], &error);
	table->time_to_sleep = ft_atoi(av[4], &error);
	table->nbr_time_eat = -1;
	if (ac == 6)
		table->nbr_time_eat = ft_atoi(av[5], &error);
	table->end = 0;
	table->nbr_thread = 0;
	table->all_full = 0;
	table->philo = malloc(sizeof(t_philo) * table->nbr_philo);
	if (!table->philo)
		return (-1);
	table->fork = malloc(sizeof(t_fork) * table->nbr_philo);
	if (!table->fork)
		return (free(table->philo), -1);
	ft_init_philo(table);
	return (0);
}

int	ft_init_philo(t_table *table)
{
	int	i;
	int	j;	

	i = 0;
	j = 1;
	while (i < table->nbr_philo)
	{
		table->philo[i].pos = j; //philo[0]
		table->philo[i].philo_mange = 0;
		table->philo[i].p_table = table;
		if (i % 2 == 0)
		{
			table->philo[i].first_fork = &table->fork[i];
			table->philo[i].seconde_fork = &table->fork[(i+1) % table->nbr_philo];
		}
		else if (i % 2 == 1)
		{
			table->philo[i].first_fork = &table->fork[(i+1) % table->nbr_philo];
			table->philo[i].seconde_fork = &table->fork[i];
		}
		i++;
		j++;
	}
	return (0);
}

int	ft_init_mutex(t_table *table)
{
	int	i;

	i = 0;
	pthread_mutex_init(&table->write, NULL);
	pthread_mutex_init(&table->m_end, NULL);
	while (i < table->nbr_philo)
	{
		pthread_mutex_init(&table->philo[i].p_mange, NULL);
		pthread_mutex_init(&table->fork[i].fork, NULL);
		i++;
	}
	return (0);
}
