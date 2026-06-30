/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchehbi <lchehbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 19:00:00 by lchehbi           #+#    #+#             */
/*   Updated: 2026/06/20 19:00:00 by lchehbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stacks *stacks)
{
	rotate(&stacks->a);
	if (stacks->bench)
		bench_count(stacks->bench, OP_RA);
	print_op("ra\n");
}

void	rb(t_stacks *stacks)
{
	rotate(&stacks->b);
	if (stacks->bench)
		bench_count(stacks->bench, OP_RB);
	print_op("rb\n");
}

void	rr(t_stacks *stacks)
{
	rotate(&stacks->a);
	rotate(&stacks->b);
	if (stacks->bench)
		bench_count(stacks->bench, OP_RR);
	print_op("rr\n");
}
