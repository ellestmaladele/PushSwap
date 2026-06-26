/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addufour <addufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 11:17:47 by addufour          #+#    #+#             */
/*   Updated: 2026/06/26 11:20:17 by addufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_rotations(t_node **a, int top_pos, int bot_pos)
{
	int	size;
	int	dist;

	size = stack_size(*a);
	if (top_pos <= size - bot_pos)
	{
		while (top_pos-- > 0)
			ra(a);
	}
	else
	{
		dist = size - bot_pos;
		while (dist-- > 0)
			rra(a);
	}
}
