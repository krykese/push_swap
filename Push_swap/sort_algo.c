/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcosta <qcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:37:56 by qcosta            #+#    #+#             */
/*   Updated: 2022/10/10 14:28:43 by qcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_index(t_ps **a)
{
	t_ps	*tmp;
	t_ps	*temp;
	int		i;

	tmp = *a;
	while (tmp)
	{
		i = 1;
		temp = *a;
		while (temp)
		{
			if (tmp->data > temp->data)
				i++;
		temp = temp->next;
		}
		tmp->index = i;
		tmp = tmp->next;
	}
}

void	sort_2_nb(t_ps **a)
{
	if (*a == NULL)
		return ;
	if ((*a)->data > (*a)->next->data)
		swap_a(a);
	else
		return ;
}

void	sort_3_nb(t_ps **a)
{
	t_ps	*temp1;
	t_ps	*temp2;

	if (!*a)
		return ;
	temp1 = (*a)->next;
	temp2 = temp1->next;
	if ((*a)->index > temp1->index && (*a)->index > temp2->index)
		print_rotate_a(a);
	else if (temp1->index > (*a)->index && temp1->index > temp2->index)
		print_reverse_rotate_a(a);
	temp1 = (*a)->next;
	if ((*a)->index > temp1->index)
		swap_a(a);
}

void	send_to_b(t_ps **a, t_ps **b)
{
	int		size;
	int		i;

	i = 0;
	size = get_size(a);
	if (*a == NULL)
		return ;
	while (*a && i <= size - 3)
	{
		if ((*a)->index <= size / 2)
			push_b(a, b);
		else
			print_rotate_a(a);
		i++;
	}
	size = get_size(a);
	while (*a && size > 3)
	{
		push_b(a, b);
		size--;
	}
}

void	sort_big(t_ps **a, t_ps **b)
{
	int		max;

	max = INT_MAX;
	send_to_b(a, b);
	sort_3_nb(a);
	while (*b)
	{
		position(a);
		position(b);
		target_pos(a, b, max);
		get_cost(a, b);
		cost_m(a, b);
	}
}
