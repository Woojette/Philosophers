/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooyang <wooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 18:42:37 by wooyang           #+#    #+#             */
/*   Updated: 2025/11/16 18:42:38 by wooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	ft_init_time(t_table *table)
{
	struct timeval	start;
	long			seconds;
	long			microseconds;
	double			elapse_milliseconds;

	(void)table;
	gettimeofday(&start, NULL);
	seconds = start.tv_sec;
	microseconds = start.tv_usec;
	elapse_milliseconds = (seconds * 1000000.0) + microseconds;
	return (elapse_milliseconds);
}

long	ft_get_time_micro(t_table *table)
{
	struct timeval	end;
	long			seconds;
	long			microseconds;
	double			elapse_milliseconds;

	gettimeofday(&end, NULL);
	seconds = end.tv_sec;
	microseconds = end.tv_usec;
	elapse_milliseconds
		= (seconds * 1000000.0) + microseconds - table->time_debut;
	return (elapse_milliseconds);
}

long	ft_get_time_ms(t_table *table)
{
	long	milliseconds;

	milliseconds = ft_get_time_micro(table) / 1000;
	return (milliseconds);
}

void	ft_usleep(long msec, t_table *table)
{
	long	start;
	long	temps_ecoule;

	start = ft_get_time_micro(table);
	temps_ecoule = start;
	while (msec > temps_ecoule - start)
	{
		usleep(msec / 1000);
		temps_ecoule = ft_get_time_micro(table);
		if (ft_get_int(&table->m_end, &table->end) == 1)
			return ;
	}
}
