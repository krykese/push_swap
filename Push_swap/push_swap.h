/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcosta <qcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:29:38 by qcosta            #+#    #+#             */
/*   Updated: 2022/10/28 14:06:28 by qcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stddef.h>
# include <limits.h>

typedef struct ps_list
{
	int				data;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct ps_list	*next;
}	t_ps;

void	new_list(t_ps **a, int res);
void	print_list(t_ps **a);
//void	print_list2(t_ps **b);
void	free_list(t_ps **a);
void	free_list(t_ps **b);
long	ft_atoi_check(const char *nptr);
void	check_doublon(t_ps **a);
void	check_overflow(t_ps **a);

void	push_a(t_ps **a, t_ps **b);
void	push_b(t_ps **a, t_ps **b);

void	swap_a(t_ps **a);
void	swap_b(t_ps **b);
void	swap_a_b(t_ps **a, t_ps **b);

void	rotate_a(t_ps **a);
void	print_rotate_a(t_ps **a);
void	rotate_b(t_ps **b);
void	print_rotate_b(t_ps **b);
void	rotate_a_b(t_ps **a, t_ps **b);

void	reverse_rotate_a(t_ps **a);
void	print_reverse_rotate_a(t_ps **a);
void	reverse_rotate_b(t_ps **b);
void	print_reverse_rotate_b(t_ps **b);
void	reverse_rotate_a_b(t_ps **a, t_ps **b);

void	sort_index(t_ps **a);
void	position(t_ps **a);
void	target_pos(t_ps **a, t_ps **b, int max);
int		get_size(t_ps **a);

void	sort(t_ps **a, t_ps **b, int argc);
void	sort_2_nb(t_ps **a);
void	sort_3_nb(t_ps **a);
void	sort_big(t_ps **a, t_ps **b);

int		already_sort(t_ps **a);

void	send_to_b(t_ps **a, t_ps **b);

void	get_cost(t_ps **a, t_ps **b);
int		cost_min(t_ps **b);
int		absol(int nb);
void	cost_m(t_ps **a, t_ps **b);
void	operation_cost(t_ps **a, t_ps **b, int costa, int costb);
int		index_min(t_ps **a);

void	get_cost_a(t_ps **a);
void	operation_costa(t_ps **a, int costa);
void	operation_costb(t_ps **b, int costb);
void	last_sort(t_ps **a);

void	check(t_ps **a, char **argv, long res, int argc);

#endif