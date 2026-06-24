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

void	sa(t_node **a)
{
	swap(a);
	if (g_bench)
		bench_count(g_bench, OP_SA);
	print_op("sa\n");
}

void	sb(t_node **b)
{
	swap(b);
	if (g_bench)
		bench_count(g_bench, OP_SB);
	print_op("sb\n");
}

void	ss(t_node **a, t_node **b)
{
	swap(a);
	swap(b);
	if (g_bench)
		bench_count(g_bench, OP_SS);
	print_op("ss\n");
}
