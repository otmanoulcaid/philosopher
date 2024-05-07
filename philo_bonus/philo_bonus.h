/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:47:15 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/05/06 23:38:46 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H

# define PHILO_BONUS_H
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <semaphore.h>
# include <sys/stat.h>
# include <limits.h>
# include <fcntl.h>
# include <signal.h>
# include <string.h>

/*------------------------structures-----------------------*/

typedef struct s_data	t_data;
typedef struct s_philo
{
	int		pid;
	int		id;
	int		eaten_meals;
	int		last_meal;
	int		status;
	sem_t	*sem_last_meal;
	t_data	*data;
}	t_philo;

typedef struct s_data
{
	int		meals;
	int		nb_philo;
	int		time_to_eat;
	int		time_to_sleep;
	int		time_to_die;
	int		start;
	sem_t	*sem_write;
	sem_t	*sem_finish;
	sem_t	*forks;
}	t_data;

/*---------------------end_of_structures-------------------*/

/*-------------------------functions-----------------------*/

int		get_time(void);
char	*itoa(int n);
void	eat(t_philo *philo);
void	*monitor(void *data);
void	clean(t_philo *philo);
void	think(t_philo *philo);
void	*supervisor(void *arg);
int		ft_atoi(char *s, int *n);
void	ft_sleep(t_philo *philo);
void	ft_usleep(size_t milisecond);
int		get_last_meal(t_philo *philo);
void	set_last_meal(t_philo *philo);
void	print(t_philo *philo, char *str);
int		simulate(t_philo *philo, int nb_philo);
void	take_fork(t_philo *philo, sem_t *fork);
int		not_valid(t_data *data, int ac, char **av);
t_philo	*ft_init_data(t_data *data, int ac, char **av);

/*---------------------end_of_functions--------------------*/

#endif
