#include "philosophers.h"

long	ft_get_time_ms(t_table *table)
{
	struct timeval	start, end;
	long	seconds;
	long	microseconds;
	double	elapse_milliseconds;

	gettimeofday(&start, NULL);
	usleep(1000000); /////
	gettimeofday(&end, NULL);
	seconds = end.tv_sec - start.tv_sec;
	microseconds = end.tv_usec - start.tv_usec;
	elapse_milliseconds = (seconds * 1000.0) + (microseconds / 1000.0);
}

void	*routine(void *arg)
{
	t_philo	*philo = (t_philo *)arg;
	(void)philo;
	printf("%d %d has taken a fork\n", philo->philo_id);
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
