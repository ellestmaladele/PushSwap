/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 11:17:47 by addufour          #+#    #+#             */
/*   Updated: 2026/06/30 14:19:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_rotations(t_stacks *stacks, int top_pos, int bot_pos)
{
	int	size;
	int	dist;

	size = stack_size(stacks->a);
	if (top_pos <= size - bot_pos)
	{
		while (top_pos-- > 0)
			ra(stacks);
	}
	else
	{
		dist = size - bot_pos;
		while (dist-- > 0)
			rra(stacks);
	}
}
