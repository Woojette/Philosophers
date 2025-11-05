#include "philosophers.h"

long	ft_atoi(const char *str, int *error)
{
	int		i;
	int		signe;
	long	nb;

	i = 0;
	signe = 1;
	nb = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (signe == 1 && (nb > (INT_MAX - (str[i] - '0')) / 10))
			return (*error = 1, LONG_MAX);
		if (signe == -1 && (-nb < (INT_MIN + (str[i] - '0')) / 10))
			return (*error = 1, LONG_MIN);
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	return (nb * signe);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (0);
	return (1);
}

int	ft_int_check(char *av)
{
	int	i;

	i = 0;
	if (!av || av[0] == '\0')
		return (1);
	if (av[0] == '+')
	{
		if (av[1] == '\0')
			return (1);
		i++;
	}
	while (av[i] != '\0')
	{
		if (ft_isdigit(av[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_int_av(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_int_check(av[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_limit(int ac, char **av)
{
	int	i;
	int	error;

	i = 1;
	error = 0;
	while (i < ac)
	{
		ft_atoi(av[i], &error);
		if (error == 1)
			return (1);
		i++;
	}
	return (0);
}
