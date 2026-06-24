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

void	ra(t_node **a)
{
	rotate(a);
	if (g_bench)
		bench_count(g_bench, OP_RA);
	print_op("ra\n");
}

void	rb(t_node **b)
{
	rotate(b);
	if (g_bench)
		bench_count(g_bench, OP_RB);
	print_op("rb\n");
}

void	rr(t_node **a, t_node **b)
{
	rotate(a);
	rotate(b);
	if (g_bench)
		bench_count(g_bench, OP_RR);
	print_op("rr\n");
}
