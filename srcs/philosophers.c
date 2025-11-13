#include "philosophers.h"

int	main(int ac, char **av)
{
	int		i;
	t_table table;

	i = 1;
	if ((ac != 5) && (ac != 6))
		return (write(2, "Error\n", 6), 1);
	if ((ft_check_int_av(ac, av) == 1) || (ft_check_limit(ac, av) == 1))
		return (write(2, "Error\n", 6), 1);
	if (ft_init_av(ac, av, &table) == -1)
		return (write(2, "Error\n", 6), 1);
	ft_init_mutex(&table);
	ft_create_thread(&table);
	ft_join_thread(&table);
	ft_destroy_mutex(&table);
	return (0);
}
//av[1][1]0