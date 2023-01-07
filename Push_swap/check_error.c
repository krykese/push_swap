/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcosta <qcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:02:03 by qcosta            #+#    #+#             */
/*   Updated: 2022/10/06 16:29:08 by qcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_doublon(t_ps **a)
{
	t_ps	*tmp;
	t_ps	*temp;

	tmp = *a;
	while (tmp)
	{
		temp = tmp->next;
		while (temp)
		{
			if (tmp->data == temp->data)
			{
				write (2, "Error\n", 6);
				free_list(a);
				exit(EXIT_FAILURE);
			}
			temp = temp->next;
		}
		tmp = tmp->next;
	}
}

int	already_sort(t_ps **a)
{
	t_ps	*tmp;

	tmp = *a;
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

long	ft_atoi_check(const char *nptr)
{
	int		sign;
	long	res;
	int		i;

	sign = 1;
	res = 0;
	i = 0;
	if (nptr[i] == '-')
		sign = -1;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	if (!nptr[i])
		return (9999999999);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = (res * 10) + (nptr[i] - '0');
		i++;
	}
	if ((res * sign) > INT_MAX || (res * sign) < INT_MIN || nptr[i] != '\0')
		return (9999999999);
	return (res * sign);
}

void	check(t_ps **a, char **argv, long res, int argc)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		res = ft_atoi_check(argv[i]);
		if (res == 9999999999)
		{
			write(2, "Error\n", 6);
			free_list(a);
			exit(EXIT_FAILURE);
		}
		new_list(a, res);
		i++;
	}
}
