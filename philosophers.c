#include "philosophers.h"

int	main(int ac, char **av)
{
	int	i;

	i = 1;
	if ((ac != 5) && (ac != 6))
		return (write(2, "Error\n", 6), 1);
	if ((ft_check_int_av(ac, av) == 1) || (ft_check_limit(ac, av) == 1))
		return (write(2, "Error\n", 6), 1);
	return (0);
}
//av[1][1]