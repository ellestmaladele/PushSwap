/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchehbi <lchehbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 19:00:00 by lchehbi           #+#    #+#             */
/*   Updated: 2026/06/20 19:00:00 by lchehbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stacks *stacks)
{
	swap(&stacks->a);
	if (stacks->bench)
		bench_count(stacks->bench, OP_SA);
	print_op("sa\n");
}

void	sb(t_stacks *stacks)
{
	swap(&stacks->b);
	if (stacks->bench)
		bench_count(stacks->bench, OP_SB);
	print_op("sb\n");
}

void	ss(t_stacks *stacks)
{
	swap(&stacks->a);
	swap(&stacks->b);
	if (stacks->bench)
		bench_count(stacks->bench, OP_SS);
	print_op("ss\n");
}


