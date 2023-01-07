/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcosta <qcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:26:43 by qcosta            #+#    #+#             */
/*   Updated: 2022/10/06 16:28:29 by qcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_size(t_ps **a)
{
	int		len;
	t_ps	*tmp;

	tmp = *a;
	len = 0;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

int	absol(int nb)
{
	if (nb == 0)
		nb = 0;
	if (nb < 0)
		nb = -nb;
	else
		nb = nb;
	return (nb);
}

void	position(t_ps **a)
{
	int		i;
	t_ps	*tmp;

	i = 0;
	tmp = *a;
	while (tmp != NULL)
	{
		tmp->pos = i;
		i++;
		tmp = tmp->next;
	}
}

void	target_pos(t_ps **a, t_ps **b, int max)
{
	t_ps	*tmp1;
	t_ps	*tmp2;

	tmp2 = *b;
	while (tmp2)
	{
		max = INT_MAX;
		tmp1 = *a;
		while (tmp1)
		{
			if (tmp2->index < tmp1->index && tmp1->index < max)
			{
				max = tmp1->index;
				tmp2->target_pos = tmp1->pos;
			}
			tmp1 = tmp1->next;
		}
		if (max == INT_MAX)
			tmp2->target_pos = index_min(a);
		tmp2 = tmp2->next;
	}
}

void	sort(t_ps **a, t_ps **b, int argc)
{
	if (argc == 3 && !already_sort(a))
		sort_2_nb(a);
	else if (argc == 4 && !already_sort(a))
		sort_3_nb(a);
	else if (argc > 4 && !already_sort(a))
		sort_big(a, b);
}
