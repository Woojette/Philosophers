/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_etat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooyang <wooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 18:42:10 by wooyang           #+#    #+#             */
/*   Updated: 2025/11/16 18:42:11 by wooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_write(t_philo *philo, int status)
{
	long	temps;

	temps = ft_get_time_ms(philo->p_table);
	pthread_mutex_lock(&philo->p_table->write);
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
	pthread_mutex_lock(&philo->fork_le->fork);
	ft_write(philo, FORK1);
	pthread_mutex_lock(&philo->fork_2e->fork);
	ft_write(philo, FORK2);
	ft_write(philo, EAT);
	ft_incrementer_int(&philo->p_mange, &philo->philo_mange);
	ft_set_long(&philo->p_mange, &philo->last_meal,
		ft_get_time_ms(philo->p_table));
	ft_usleep((philo->p_table->time_to_eat * 1000), philo->p_table);
	pthread_mutex_unlock(&philo->fork_le->fork);
	pthread_mutex_unlock(&philo->fork_2e->fork);
	if (ft_get_int(&philo->p_mange, &philo->philo_mange)
		== philo->p_table->nbr_time_eat)
	{
		ft_incrementer_int(&philo->p_table->m_end,
			&philo->p_table->all_full);
	}
}

void	ft_sleep(t_philo *philo)
{
	ft_write(philo, SLEEP);
	ft_usleep((philo->p_table->time_to_sleep * 1000), philo->p_table);
}

void	ft_think(t_philo *philo)
{
	long	attente;

	ft_write(philo, THINK);
	attente = (philo->p_table->time_to_eat * 2)
		- (philo->p_table->time_to_sleep);
	if (philo->p_table->nbr_philo % 2 == 0)
		ft_usleep(1000, philo->p_table);
	else if (philo->p_table->nbr_philo % 2 == 1)
		ft_usleep(attente * 1000, philo->p_table);
}
