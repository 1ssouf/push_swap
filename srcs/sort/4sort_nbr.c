/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_nbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialousse <ialousse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 20:31:24 by ialousse          #+#    #+#             */
/*   Updated: 2023/03/15 18:08:48 by ialousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_two(t_stack *stack)
{
	if (stack->size == 2 && stack->data[0] > stack->data[1])
		sa(stack);
}

void	sort_three(t_stack *stack)
{
	if (stack->size == 3)
	{
		if (stack->data[0] > stack->data[1] && stack->data[0] < stack->data[2])
			sa(stack);
		else if (stack->data[0] > stack->data[1] && \
			stack->data[0] > stack->data[2] && stack->data[1] < stack->data[2])
			ra(stack);
		else if (stack->data[0] < stack->data[1] && \
			stack->data[1] > stack->data[2])
			rra(stack);
		else if (stack->data[0] < stack->data[1] && \
			stack->data[1] < stack->data[2])
		{
			sa(stack);
			rra(stack);
		}
		else if (stack->data[0] > stack->data[1] && \
			stack->data[1] > stack->data[2])
		{
			sa(stack);
			ra(stack);
		}
	}
}

void	sort_four(t_stack *a, t_stack *b)
{
	int	max;

	while (a->size > 3)
		pb(a, b);
	sort_three(a);
	if (b->data[b->top] > b->data[b->top + 1])
		sb(b);
	max = get_max(b);
	while (b->size > 0 && b->data[b->top] != max)
	{
		if (b->data[b->top] < max / 2)
			rb(b);
		else
			pa(b, a);
	}
	while (a->data[a->top] != get_min(a))
		rra(a);
	pa(b, a);
	pa(b, a);
}

void	sort_five(t_stack *a, t_stack *b)
{
	int	max;

	while (a->size > 2)
		pb(a, b);
	sort_three(a);
	sort_two(b);
	pa(b, a);
	if (b->data[b->top] > b->data[b->top + 1])
		sb(b);
	max = get_max(b);
	while (b->size > 0 && b->data[b->top] != max)
	{
		if (b->data[b->top] < max / 2)
			rb(b);
		else
			pa(b, a);
	}
	while (a->data[a->top] != get_min(a))
		rra(a);
	pa(b, a);
	pa(b, a);
}

void	sort_ten(t_stack *a, t_stack *b)
{
	int	chunk_size;

	chunk_size = a->size / 2;
	push_chunk_to_b(a, b, chunk_size, get_chunk_max(a, chunk_size));
	push_all_to_a(a, b, chunk_size);
	push_chunk_to_b(a, b, chunk_size, get_chunk_max(a, chunk_size));
	push_all_to_a(a, b, chunk_size);
}

/*
** vérifie si la pile a est triée de manière décroissante.
*/

int	is_sorted_descending(t_stack *stack)
{
	int	i;

	if (stack->size == 0)
		return (1);
	i = stack->top;
	while (i < stack->size - 1)
	{
		if (stack->data[i] < stack->data[i + 1])
			return (0);
		i++;
	}
	return (1);
}