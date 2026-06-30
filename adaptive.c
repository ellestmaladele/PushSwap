/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addufour <addufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 19:00:00 by addufour          #+#    #+#             */
/*   Updated: 2026/06/20 19:00:00 by addufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

#include "push_swap.h"

t_strategy	choose_strategy(int size, double disorder)
{
	if (size <= 5)
		return (SIMPLE);
	if (disorder < LOW_DISORDER)
		return (ADAPTIVE);
	if (disorder < MEDIUM_DISORDER)
		return (MEDIUM);
	return (COMPLEX);
}

static void	execute_simple_ad(t_stacks *stacks, t_config *cfg)
{
	(void)cfg;
	mini_sort(stacks);
}

static void	execute_medium_ad(t_stacks *stacks, t_config *cfg)
{
	(void)cfg;
	assign_indexes(stacks->a);
	chunk_sort(stacks);
}

static void	execute_complex_ad(t_stacks *stacks, t_config *cfg)
{
	(void)cfg;
	assign_indexes(stacks->a);
	radix_sort(stacks);
}

void	adaptive_sort(t_stacks *stacks, t_config *cfg)
{
	int	size;

	if (!stacks || !stacks->a || !cfg)
		return ;
	size = stack_size(stacks->a);
	cfg->used_strategy = choose_strategy(size, cfg->disorder);
	if (cfg->used_strategy == SIMPLE)
		execute_simple_ad(stacks, cfg);
	else if (cfg->used_strategy == ADAPTIVE)
		nearly_sorted_sort(stacks);
	else if (cfg->used_strategy == MEDIUM)
		execute_medium_ad(stacks, cfg);
	else
		execute_complex_ad(stacks, cfg);
}
