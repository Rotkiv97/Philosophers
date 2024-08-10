/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguidoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:38:26 by vguidoni          #+#    #+#             */
/*   Updated: 2023/04/17 18:38:27 by vguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <pthread.h>
# include <sys/stat.h>
# include <sys/time.h>
# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <fcntl.h>

/*compila con -lpthread*/
/*valgrind --tool=helgrind*/
/* -fsanitize=thread */
/* -pthread */

struct	s_philo;

typedef struct s_arrphilo
{
	struct s_philo		*filo;
	int					nfi;
	int					filosofi;
	long unsigned int	time_usec;
	long unsigned int	time_sec;
	int					count_it;
	int					morte;
	int					*turni;
	pthread_mutex_t		*mutex;
	pthread_t			tred;
	pthread_mutex_t		*fork;
	int					*ult_mang;
	struct timeval		t;
	pthread_mutex_t		*die;
}	t_arrphilo;

typedef struct s_philo
{
	t_arrphilo			*tphilo;
	int					filosofi;
	int					mangia;
	int					dorme;
	int					pensa;
	int					turni;
	int					morte;
	int					count_die;
	int					*ult_mang;
	long unsigned int	time_usec;
	long unsigned int	time_sec;
	pthread_mutex_t		mutex;
	pthread_mutex_t		*fork;
	pthread_mutex_t		die;
	pthread_mutex_t		ultima_mag;
	struct timeval		t;
}	t_philo;

int					ft_check(char **av, int ac);
int					ft_atoi(const char *nptr);
int					ft_nbr(int i);
int					ft_strlen(char *str);
void				ft_philosophers(char **av, int ac);
void				mangia(t_arrphilo *tphilo);
void				dorme(t_arrphilo *tphilo);
void				pensa(t_arrphilo *tphilo);
void				ft_death(t_philo *philo);
void				*percorso(void *lol);
unsigned long int	get_time(t_philo *philo);
void				ft_gest_all(int ac, char **av, t_philo *philo);
void				ft_free(t_philo *philo);
void				ft_print(t_arrphilo *tphilo, char *msg, int k);

#endif
