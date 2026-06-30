/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nearly_sorted.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addufour <addufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 19:00:00 by addufour          #+#    #+#             */
/*   Updated: 2026/06/20 19:00:00 by addufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	has_local_inversion(t_stack *a)
{
	while (a && a->next)
	{
		if (a->value > a->next->value)
			return (1);
		a = a->next;
	}
	return (0);
}

static void	correct_top(t_stacks *stacks)
{
	if (stacks->a->next
		&& stacks->a->value > stacks->a->next->value)
		sa(stacks);
	else
		ra(stacks);
}

static void	rewind_stack(t_stacks *stacks)
{
	int	size;

	size = stack_size(stacks->a);
	while (size--)
		rra(stacks);
}

void	nearly_sorted_sort(t_stacks *stacks)
{
	int	limit;

	limit = stack_size(stacks->a) * stack_size(stacks->a);
	while (has_local_inversion(stacks->a) && limit--)
		correct_top(stacks);
	rewind_stack(stacks);
}
