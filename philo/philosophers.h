/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooyang <wooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 19:04:18 by wooyang           #+#    #+#             */
/*   Updated: 2025/11/16 19:04:20 by wooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <sys/time.h>
# include <pthread.h>

# define SLEEP 1
# define EAT 2
# define THINK 3
# define DEAD 4
# define FORK1 5
# define FORK2 6

// struct t_table;
typedef struct s_fork
{
	pthread_mutex_t	fork;
	int				id;
}	t_fork;

typedef struct s_philo
{
	int				pos;
	int				philo_mange;
	long			last_meal;
	t_fork	 		*fork_le;
	t_fork			*fork_2e;
	pthread_t		philo_id;
	pthread_mutex_t	p_mange;
	struct s_table	*p_table;
}	t_philo;

typedef struct s_table
{
	pthread_mutex_t	write;
	int				nbr_philo;
	int				end;
	int				nbr_thread;
	int				all_full;
	long			time_debut;
	long			time_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			nbr_time_eat;
	pthread_t		manager;
	pthread_mutex_t	m_end;
	t_philo			*philo;  // philo = malloc(sizeof(t_philo) * nbr_philo); philo[0]->pos != philo[1]->pos
	t_fork			*fork;//fork[0 1 2 3 4];
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
int		ft_init_mutex(t_table *table);

// ft_thread.c
void	*routine(void *arg);
void	*routine_manager(void *arg);
int		ft_create_thread(t_table *table);
int		ft_join_thread(t_table *table);
int		ft_destroy_mutex(t_table *table);

// ft_time.c
long	ft_init_time(t_table *table);
long	ft_get_time_micro(t_table *table);
long	ft_get_time_ms(t_table *table);
void	ft_usleep(long msec, t_table *table);

// ft_etat.c
void	ft_write(t_philo *philo, int status);
void	ft_eat(t_philo *philo);
void	ft_sleep(t_philo *philo);
void	ft_think(t_philo *philo);

// ft_get.c
void	ft_incrementer_int(pthread_mutex_t *mutex, int *val);
void	ft_set_int(pthread_mutex_t *mutex, int *val, int new);
void	ft_set_long(pthread_mutex_t *mutex, long *val, long new);
int		ft_get_int(pthread_mutex_t *mutex, int *val);
long	ft_get_long(pthread_mutex_t *mutex, long *val);

#endif
