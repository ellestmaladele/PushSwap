/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchehbi <lchehbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 19:00:00 by lchehbi           #+#    #+#             */
/*   Updated: 2026/06/20 19:00:00 by lchehbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stacks *stacks)
{
	t_node	*node;

	node = pop_front(&stacks->b);
	if (!node)
		return ;
	push_front(&stacks->a, node);
	if (stacks->bench)
		bench_count(stacks->bench, OP_PA);
	print_op("pa\n");
}

void	pb(t_stacks *stacks)
{
	t_node	*node;

	node = pop_front(&stacks->a);
	if (!node)
		return ;
	push_front(&stacks->b, node);
	if (stacks->bench)
		bench_count(stacks->bench, OP_PB);
	print_op("pb\n");
}
