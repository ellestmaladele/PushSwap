/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addufour <addufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 19:00:00 by addufour          #+#    #+#             */
/*   Updated: 2026/06/20 19:00:00 by addufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	stack_max_index(t_stack *a)
{
	int	max;

	max = 0;
	while (a)
	{
		if (a->index > max)
			max = a->index;
		a = a->next;
	}
	return (max);
}

int	get_max_bits(t_stack *a)
{
	int	max;
	int	bits;

	max = stack_max_index(a);
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

static void	process_bit(t_stacks *stacks, int bit, int size)
{
	int	i;

	if (!stacks->a)
		return ;
	i = 0;
	while (i < size)
	{
		if ((stacks->a->index >> bit) & 1)
			ra(stacks);
		else
			pb(stacks);
		i++;
	}
}

static void	restore_stack(t_stacks *stacks)
{
	while (stacks->b)
		pa(stacks);
}

void	radix_sort(t_stacks *stacks)
{
	int	max_bits;
	int	size;
	int	bit;

	size = stack_size(stacks->a);
	max_bits = get_max_bits(stacks->a);
	bit = 0;
	while (bit < max_bits)
	{
		process_bit(stacks, bit, size);
		restore_stack(stacks);
		bit++;
	}
}
