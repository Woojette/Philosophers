#ifndef	PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_fork
{
	pthread_mutex_t	fork;
	int				id;
}	t_fork;

typedef struct s_philo
{
	int pos;
}	t_philo;

typedef struct s_table
{
	int		nbr_philo;
	long	time_die;
	long	time_to_eat;
	long	time_to_sleep;
	t_philo	*philo;  // philo = malloc(sizeof(t_philo) * nbr_philo); philo[0]->pos != philo[1]->pos
	t_fork	*fork;
}	t_table;

long	ft_atoi(const char *str, int *error);
int	ft_isdigit(int c);
int	ft_int_check(char *av);
int	ft_check_limit(int ac, char **av);
int	ft_check_int_av(int ac, char **av);

#endif