/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooyang <wooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 18:41:43 by wooyang           #+#    #+#             */
/*   Updated: 2025/11/16 18:41:46 by wooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	(void)philo;
	while (ft_get_int(&philo->p_table->m_end, &philo->p_table->end) != 1)
	{
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
		if (ft_get_int(&philo->p_mange, &philo->philo_mange)
			== philo->p_table->nbr_time_eat)
		{
			ft_incrementer_int(&philo->p_table->m_end,
				&philo->p_table->all_full);
			return (NULL);
		}
	}
	return (NULL);
}

void	*routine_manager(void *arg)
{
	int		i;
	long	now;
	t_table	*table;

	table = (t_table *)arg;
	i = 0;
	now = ft_get_time_ms(table);
	while (i < table->nbr_philo)
	{
		now = ft_get_time_ms(table);
		if (ft_get_int(&table->m_end, &table->all_full) == table->nbr_philo)
			return (NULL);
		if (table->time_die < (now - (ft_get_long(&table->philo[i].p_mange,
						&table->philo[i].last_meal))))
		{
			ft_write(table->philo, DEAD);
			break ;
		}
		i++;
		if (i == table->nbr_philo)
			i = 0;
	}
	return (NULL);
}

int	ft_create_thread(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nbr_philo)
	{
		pthread_create(&table->philo[i].philo_id, NULL,
			routine, &table->philo[i]);
		i++;
	}
	pthread_create(&table->manager, NULL, routine_manager, table);
	return (0);
}

int	ft_join_thread(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nbr_philo)
	{
		pthread_join(table->philo[i].philo_id, NULL);
		i++;
	}
	pthread_join(table->manager, NULL);
	return (0);
}

int	ft_destroy_mutex(t_table *table)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&table->m_end);
	pthread_mutex_destroy(&table->write);
	while (i < table->nbr_philo)
	{
		pthread_mutex_destroy(&table->philo[i].p_mange);
		pthread_mutex_destroy(&table->fork[i].fork);
		i++;
	}
	return (0);
}
