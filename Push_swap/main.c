/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcosta <qcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:03:29 by qcosta            #+#    #+#             */
/*   Updated: 2022/10/28 14:06:45 by qcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	new_list(t_ps **a, int res)
{
	t_ps	*tmp;
	t_ps	*temp;

	tmp = (t_ps *)malloc(sizeof(t_ps) * 1);
	if (!tmp)
		return ;
	tmp->data = res;
	tmp->next = NULL;
	if (!*a)
		*a = tmp;
	else
	{
		temp = *a;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = tmp;
	}
}

void	free_list(t_ps **a)
{
	t_ps	*tmp;
	t_ps	*temp;

	tmp = *a;
	while (tmp != NULL)
	{
		temp = tmp->next;
		free(tmp);
		tmp = temp;
	}
}

void	last_sort(t_ps **a)
{
	if (!already_sort(a))
	{
		position(a);
		get_cost_a(a);
	}
}

void	print_list(t_ps **a)
{
	t_ps	*tmp;
	tmp = *a;
	while(tmp != NULL)
	{
		printf("PILE A	data = %d	index = %d	pos = %d\n", tmp->data, tmp->index, tmp->pos);
		tmp = tmp->next;
	}
}

void	print_list(t_ps **b)
{
	t_ps	*tmp;
	tmp = *b;
	while(tmp)
	{
		printf("PILE B	data = %d	index = %d	pos = %d	target = %d		cost_a = %d		cost_b = %d\n", tmp->data, tmp->index, tmp->pos, tmp->target_pos, tmp->cost_a, tmp->cost_b);
		tmp = tmp->next;
	}
}
int	main(int argc, char **argv)
{
	long	res;
	t_ps	*a;
	t_ps	*b;

	a = NULL;
	b = NULL;
	res = 0;
	if (argc >= 2)
	{
		check(&a, argv, res, argc);
		check_doublon(&a);
		sort_index(&a);
		print_list(&a);
		print_list(&b);
		sort(&a, &b, argc);
		
		last_sort(&a);
		print_list(&a);
		free_list(&a);
		free_list(&b);
	}
	return (0);
}
