/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_rrotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchehbi <lchehbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 19:00:00 by lchehbi           #+#    #+#             */
/*   Updated: 2026/06/20 19:00:00 by lchehbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stacks *stacks)
{
	reverse_rotate(&stacks->a);
	if (stacks->bench)
		bench_count(stacks->bench, OP_RRA);
	print_op("rra\n");
}

void	rrb(t_stacks *stacks)
{
	reverse_rotate(&stacks->b);
	if (stacks->bench)
		bench_count(stacks->bench, OP_RRB);
	print_op("rrb\n");
}

void	rrr(t_stacks *stacks)
{
	reverse_rotate(&stacks->a);
	reverse_rotate(&stacks->b);
	if (stacks->bench)
		bench_count(stacks->bench, OP_RRR);
	print_op("rrr\n");
}
