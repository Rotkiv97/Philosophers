/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguidoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:25:43 by vguidoni          #+#    #+#             */
/*   Updated: 2023/04/17 17:25:45 by vguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_gest_all(int ac, char **av, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->filosofi)
	{
		philo->tphilo[i].nfi = i + 1;
		philo->mangia = atoi(av[3]);
		philo->dorme = atoi(av[4]);
		if (av[5] != NULL && ac == 6)
			philo->turni = atoi(av[5]);
		philo->tphilo[i].time_usec = philo->time_usec;
		philo->tphilo[i].time_sec = philo->time_sec;
		philo->tphilo[i].mutex = &philo->mutex;
		philo->tphilo[i].filo = philo;
		philo->tphilo[i].filosofi = philo->filosofi;
		philo->tphilo[i].fork = philo->fork;
		philo->tphilo[i].die = &philo->die;
		philo->tphilo[i].ult_mang = philo->ult_mang;
		philo->tphilo[i].turni = &philo->turni;
		philo->tphilo[i].morte = philo->morte;
	}
}

void	ft_get_init(t_philo *philo)
{
	struct timeval	val;
	int				i;

	i = 0;
	pthread_mutex_init(&philo->mutex, NULL);
	pthread_mutex_init(&philo->die, NULL);
	pthread_mutex_init(&philo->ultima_mag, NULL);
	gettimeofday(&val, 0);
	philo->time_sec = val.tv_sec;
	philo->time_usec = val.tv_usec;
	philo->t = val;
	philo->fork = malloc(sizeof(pthread_mutex_t) * philo->filosofi);
	philo->ult_mang = malloc(sizeof(long unsigned int) * philo->filosofi);
	while (i < philo->filosofi)
	{
		philo->ult_mang[i] = 0;
		i++;
	}
}

void	ft_condizione_1(t_philo *philo)
{
	if (philo->filosofi == 1)
	{
		printf("%ldms  %d   %s 🍴\n", get_time(philo), 1, "taken a fork");
		usleep(philo->morte * 1000);
		printf("%ldms  %d   %s 💀\n", get_time(philo), 1, "death");
	}
}

void	ft_philosophers(char **av, int ac)
{
	int		i;
	t_philo	*philo;

	philo = NULL;
	ft_check(av, ac);
	philo = malloc(sizeof(t_philo) * 1);
	philo->filosofi = ft_atoi(av[1]);
	philo->morte = ft_atoi(av[2]);
	philo->tphilo = malloc(sizeof(t_arrphilo) * philo->filosofi);
	i = -1;
	ft_get_init(philo);
	ft_condizione_1(philo);
	while (++i < philo->filosofi && philo->filosofi != 1)
		pthread_mutex_init(&philo->fork[i], NULL);
	ft_gest_all(ac, av, philo);
	i = -1;
	while (++i < philo->filosofi && philo->filosofi != 1)
		pthread_create(&(philo->tphilo[i].tred),
			NULL, &percorso, &(philo->tphilo[i]));
	i = -1;
	if (philo->filosofi != 1)
		ft_death(philo);
	while (++i < philo->filosofi && philo->filosofi != 1)
		pthread_join(philo->tphilo[i].tred, NULL);
	ft_free(philo);
}

int	main(int ac, char **av)
{
	if (ac == 5 || ac == 6)
		ft_philosophers(av, ac);
	else
		printf("\033[31mError: numero argomenti invalido\033[0m\n");
	return (0);
}
