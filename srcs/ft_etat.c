#include "philosophers.h"

void	ft_write(t_philo *philo, int status)
{
	long	temps;

	temps = ft_get_time_ms(philo->p_table);
	pthread_mutex_lock(&philo->p_table->write);
	// if (philo->p_table->end == 1)
	if (ft_get_int(&philo->p_table->m_end, &philo->p_table->end) == 1)
	{
		pthread_mutex_unlock(&philo->p_table->write);
		return ;
	}
	if (status == FORK1 || status == FORK2)
		printf("%lu %d has taken a fork\n", temps, philo->pos);
	else if (status == SLEEP)
		printf("%lu %d is sleeping\n", temps, philo->pos);
	else if (status == EAT)
		printf("%lu %d is eating\n", temps, philo->pos);
	else if (status == THINK)
		printf("%lu %d is thinking\n", temps, philo->pos);
	else if (status == DEAD)
	{
		printf("%lu %d died\n", temps, philo->pos);
		ft_set_int(&philo->p_table->m_end, &philo->p_table->end, 1);
	}
	pthread_mutex_unlock(&philo->p_table->write);
}

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->first_fork->fork);
	ft_write(philo, FORK1);
	pthread_mutex_lock(&philo->seconde_fork->fork);
	ft_write(philo, FORK2);
	ft_write(philo, EAT);
	ft_incrementer_int(&philo->p_mange, &philo->philo_mange);
	// if (ft_get_int(&philo->p_mange, &philo->philo_mange) == philo->p_table->nbr_time_eat)
	// 	return ;
	ft_set_long(&philo->p_mange, &philo->last_meal, ft_get_time_ms(philo->p_table));
	ft_usleep((philo->p_table->time_to_eat * 1000), philo->p_table);
	pthread_mutex_unlock(&philo->first_fork->fork);
	pthread_mutex_unlock(&philo->seconde_fork->fork);
}

void	ft_sleep(t_philo *philo)
{
	ft_write(philo, SLEEP);
	ft_usleep((philo->p_table->time_to_sleep * 1000), philo->p_table);
}

void	ft_think(t_philo *philo)
{
	ft_write(philo, THINK);
}
