#ifndef	PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <sys/time.h>
# include <pthread.h>

// struct t_table;

typedef struct s_fork
{
	pthread_mutex_t	fork;
	int				id;
}	t_fork;

typedef struct s_philo
{
	int 	pos;
	int		philo_mange;
	t_fork 	*first_fork;
	t_fork	*seconde_fork;
	struct s_table	*p_table;
}	t_philo;

typedef struct s_table
{
	int		nbr_philo;
	int		end;
	int		nbr_thread;
	int		all_full;
	long	time_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	nbr_time_eat;
	t_philo	*philo;  // philo = malloc(sizeof(t_philo) * nbr_philo); philo[0]->pos != philo[1]->pos
	t_fork	*fork;//fork[0 1 2 3 4];
}	t_table;

//ft_check_int.c
long	ft_atoi(const char *str, int *error);
int		ft_isdigit(int c);
int		ft_int_check(char *av);
int		ft_check_limit(int ac, char **av);
int		ft_check_int_av(int ac, char **av);

// ft_init
int 	ft_init_av(int ac, char **av, t_table *table);
int		ft_init_philo(t_table *table);

#endif