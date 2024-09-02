/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vita.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguidoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:34:44 by vguidoni          #+#    #+#             */
/*   Updated: 2023/04/17 17:34:49 by vguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_gest_mang(t_arrphilo *tphilo, int k)
{
	if (tphilo->filosofi == tphilo->nfi)
	{
		pthread_mutex_lock(&tphilo->fork[0]);
		ft_print(tphilo, "taken a fork 🍴", k);
		pthread_mutex_lock(&tphilo->fork[tphilo->nfi - 1]);
		ft_print(tphilo, "taken a fork 🍴", k);
	}
	else
	{
		pthread_mutex_lock(&tphilo->fork[tphilo->nfi - 1]);
		ft_print(tphilo, "taken a fork 🍴", k);
		pthread_mutex_lock(&tphilo->fork[tphilo->nfi]);
		ft_print(tphilo, "taken a fork 🍴", k);
	}
}

void	mangia(t_arrphilo *tphilo)
{
	int	k;

	k = tphilo->nfi;
	ft_gest_mang(tphilo, k);
	pthread_mutex_lock(tphilo->die);
	pthread_mutex_lock(&tphilo->filo->ultima_mag);
	tphilo->filo->ult_mang[tphilo->nfi - 1] = get_time(tphilo->filo);
	pthread_mutex_unlock(&tphilo->filo->ultima_mag);
	pthread_mutex_unlock(tphilo->die);
	ft_print(tphilo, "eating 🍔", k);
	usleep(tphilo->filo->mangia * 1000);
	if (tphilo->filo->filosofi == tphilo->nfi)
	{
		pthread_mutex_unlock(&tphilo->fork[tphilo->nfi - 1]);
		pthread_mutex_unlock(&tphilo->fork[0]);
	}
	else
	{
		pthread_mutex_unlock(&tphilo->fork[tphilo->nfi]);
		pthread_mutex_unlock(&tphilo->fork[tphilo->nfi - 1]);
	}
}

void	dorme(t_arrphilo *tphilo)
{
	int	k;

	k = tphilo->nfi;
	ft_print(tphilo, "sleeping 😴", k);
	usleep(tphilo->filo->dorme * 1000);
}

void	pensa(t_arrphilo *tphilo)
{
	int	k;

	k = tphilo->nfi;
	ft_print(tphilo, "thinking 💭", k);
}

void	*percorso(void *lol)
{
	t_arrphilo	*tphilo;
	int			i;

	i = -1;
	tphilo = (t_arrphilo *)lol;
	tphilo->count_it = 0;
	if ((tphilo->nfi % 2 == 0))
		usleep(6000);
	while (++i < tphilo->filo->turni || tphilo->filo->turni == 0)
	{
		mangia(tphilo);
		dorme(tphilo);
		pensa(tphilo);
		tphilo->count_it++;
	}
	return (NULL);
}
