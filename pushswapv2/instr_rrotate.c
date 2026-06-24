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

void	rra(t_node **a)
{
	reverse_rotate(a);
	if (g_bench)
		bench_count(g_bench, OP_RRA);
	print_op("rra\n");
}

void	rrb(t_node **b)
{
	reverse_rotate(b);
	if (g_bench)
		bench_count(g_bench, OP_RRB);
	print_op("rrb\n");
}

void	rrr(t_node **a, t_node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (g_bench)
		bench_count(g_bench, OP_RRR);
	print_op("rrr\n");
}
