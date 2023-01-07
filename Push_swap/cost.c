/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcosta <qcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:04:08 by qcosta            #+#    #+#             */
/*   Updated: 2022/10/06 16:26:52 by qcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_cost(t_ps **a, t_ps **b)
{
	int		size_a;
	int		size_b;
	t_ps	*tmp1;
	t_ps	*tmp2;

	size_a = get_size(a);
	size_b = get_size(b);
	tmp2 = *b;
	while (tmp2)
	{
		if (tmp2->pos <= size_b / 2)
			tmp2->cost_b = tmp2->pos;
		else
			tmp2->cost_b = (size_b - tmp2->pos) * -1;
		tmp1 = *a;
		while (tmp1)
		{
			if (tmp2->target_pos <= size_a / 2 && tmp2->target_pos == tmp1->pos)
				tmp2->cost_a = tmp1->pos;
			else if (tmp2->target_pos == tmp1->pos)
				tmp2->cost_a = (size_a - tmp1->pos) * -1;
			tmp1 = tmp1->next;
		}
	tmp2 = tmp2->next;
	}
}

void	get_cost_a(t_ps **a)
{
	t_ps	*tmp;
	int		size;

	tmp = *a;
	size = get_size(a);
	while (tmp)
	{
		if (tmp->index == 1 && tmp->pos <= size / 2)
		{
			tmp->cost_a = tmp->pos;
			operation_costa(a, tmp->cost_a);
		}
		else if (tmp->index == 1 && tmp->pos > size / 2)
		{
			tmp->cost_a = (size - tmp->pos) * -1;
			operation_costa(a, tmp->cost_a);
		}
		tmp = tmp->next;
	}
}

int	index_min(t_ps **a)
{
	t_ps	*tmp;
	int		index_min;
	int		pos_min;

	tmp = *a;
	position(a);
	index_min = INT_MAX;
	pos_min = tmp->pos;
	while (tmp)
	{
		if (tmp->index < index_min)
		{
			index_min = tmp->index;
			pos_min = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (pos_min);
}

int	cost_min(t_ps **b)
{
	t_ps	*tmp2;
	int		max;
	int		result;

	tmp2 = *b;
	max = INT_MAX;
	while (tmp2)
	{
		result = absol(tmp2->cost_a) + absol(tmp2->cost_b);
		if (result < max)
			max = result;
		tmp2 = tmp2->next;
	}
	return (max);
}

void	cost_m(t_ps **a, t_ps **b)
{
	t_ps	*tmp2;
	int		min;
	int		result;

	min = cost_min(b);
	tmp2 = *b;
	while (tmp2)
	{
		result = absol(tmp2->cost_a) + absol(tmp2->cost_b);
		if (result == min)
		{
			operation_cost(a, b, tmp2->cost_a, tmp2->cost_b);
			break ;
		}
		tmp2 = tmp2->next;
	}
}
