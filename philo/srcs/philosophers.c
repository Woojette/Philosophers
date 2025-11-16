/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooyang <wooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 18:41:57 by wooyang           #+#    #+#             */
/*   Updated: 2025/11/16 18:41:59 by wooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	int		i;
	t_table	table;

	i = 1;
	if ((ac != 5) && (ac != 6))
		return (write(2, "Error\n", 6), 1);
	if ((ft_check_int_av(ac, av) == 1) || (ft_check_limit(ac, av) == 1))
		return (write(2, "Error\n", 6), 1);
	if (ft_init_av(ac, av, &table) == -1)
		return (write(2, "Error\n", 6), 1);
	table.time_debut = ft_init_time(&table);
	if (table.nbr_philo == 1)
	{
		printf("%lu %d has taken a fork\n",
			ft_get_time_ms(&table), table.philo->pos);
		usleep(table.time_die * 1000);
		printf("%lu %d died\n", ft_get_time_ms(&table), table.philo->pos);
		return (free(table.philo), free(table.fork), 0);
	}
	ft_init_mutex(&table);
	ft_create_thread(&table);
	ft_join_thread(&table);
	ft_destroy_mutex(&table);
	return (free(table.philo), free(table.fork), 0);
}
