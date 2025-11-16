/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooyang <wooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 18:41:10 by wooyang           #+#    #+#             */
/*   Updated: 2025/11/16 18:41:12 by wooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_incrementer_int(pthread_mutex_t *mutex, int *val)
{
	pthread_mutex_lock(mutex);
	(*val)++;
	pthread_mutex_unlock(mutex);
}

void	ft_set_int(pthread_mutex_t *mutex, int *val, int new)
{
	pthread_mutex_lock(mutex);
	*val = new;
	pthread_mutex_unlock(mutex);
}

void	ft_set_long(pthread_mutex_t *mutex, long *val, long new)
{
	pthread_mutex_lock(mutex);
	*val = new;
	pthread_mutex_unlock(mutex);
}

int	ft_get_int(pthread_mutex_t *mutex, int *val)
{
	int	temp;

	pthread_mutex_lock(mutex);
	temp = *val;
	pthread_mutex_unlock(mutex);
	return (temp);
}

long	ft_get_long(pthread_mutex_t *mutex, long *val)
{
	long	temp;

	pthread_mutex_lock(mutex);
	temp = *val;
	pthread_mutex_unlock(mutex);
	return (temp);
}
