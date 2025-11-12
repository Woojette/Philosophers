#include "philosophers.h"

void	*routine(void *arg)
{
	t_philo	*philo = (t_philo *)arg;
	(void)philo;
	printf("routine | ");
	return (NULL);
}

int	ft_create_thread(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nbr_philo)
	{
		pthread_create(&table->philo[i].philo_id, NULL, routine, &table->philo[i]);
		i++;
	}
	return (0);
}

// void != void*

int	ft_join_thread(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nbr_philo)
	{
		pthread_join(table->philo[i].philo_id, NULL);
		i++;
	}
	return (0);
}

int	ft_destroy_mutex(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nbr_philo)
	{
		pthread_mutex_destroy(&table->fork[i].fork);
		i++;
	}
	return (0);
}
