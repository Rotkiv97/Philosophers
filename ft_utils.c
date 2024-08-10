/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguidoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:23:13 by vguidoni          #+#    #+#             */
/*   Updated: 2023/04/17 17:23:15 by vguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_nbr(int i)
{
	if ((i >= '0' && i <= '9' ) || i == '-')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	const char	*y;
	int			tab;
	int			j;
	int			i;

	y = nptr;
	i = 0;
	tab = 0;
	j = 1;
	while ((y[i] >= 9 && y[i] <= 13) || y[i] == ' ')
		i++;
	if (y[i] == 43)
		i++;
	else if (y[i] == 45)
	{
		j *= -1;
		i++;
	}
	while (y[i] >= 48 && y[i] <= 57)
	{
		tab *= 10;
		tab += y[i] - 48;
		i++;
	}
	return (tab * j);
}
