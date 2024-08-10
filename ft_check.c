/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguidoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:11:33 by vguidoni          #+#    #+#             */
/*   Updated: 2023/04/17 17:11:36 by vguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_check(char **av, int ac)
{
	int	i;
	int	k;
	int	flag[2];

	i = 1;
	flag[0] = 0;
	flag[1] = 0;
	while (i < ac)
	{
		k = 0;
		while (av[i][k])
		{
			if (!ft_nbr(av[i][k]))
				flag[0] = 1;
			k++;
		}
		if (ft_atoi(av[i]) < 0)
			flag[1] = 1;
		i++;
	}
	if (flag[0] == 1)
		printf("metti un numero\n");
	if (flag[1] == 1)
		printf("metti un numero positivo\n");
	return (1);
}
