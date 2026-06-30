/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunksort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addufour <addufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 19:00:00 by addufour          #+#    #+#             */
/*   Updated: 2026/06/20 19:00:00 by addufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	get_chunk_size(int size)
{
	if (size <= 100)
		return (15);
	return (30);
}

static void	push_chunk(t_stacks *stacks, int *limit, int chk_size)
{
	pb(stacks);
	if (stacks->b && stacks->b->index < (*limit - chk_size / 2))
		rb(stacks);
	(*limit)++;
}

void	push_chunks_to_b2(t_stacks *stacks, int chunk_size)
{
	int	limit;

	limit = chunk_size;
	while (stacks->a)
	{
		if (stacks->a->index <= limit)
			push_chunk(stacks, &limit, chunk_size);
		else
			ra(stacks);
	}
}

static void	move_max_to_top(t_stacks *stacks)
{
	int	pos;
	int	size;

	pos = find_max_position(stacks->b);
	size = stack_size(stacks->b);
	if (pos <= size / 2)
	{
		while (pos--)
			rb(stacks);
	}
	else
	{
		pos = size - pos;
		while (pos--)
			rrb(stacks);
	}
}

void	chunk_sort(t_stacks *stacks)
{
	int	chunk_size;

	chunk_size = get_chunk_size(stack_size(stacks->a));
	push_chunks_to_b2(stacks, chunk_size);
	while (stacks->b)
	{
		move_max_to_top(stacks);
		pa(stacks);
	}
}
