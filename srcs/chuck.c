/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chuck.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialousse <ialousse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:04:57 by ialousse          #+#    #+#             */
/*   Updated: 2023/03/13 21:47:13 by ialousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** get_chunk_max retourne la valeur maximale dans le chunk de la pile donnée
*/
int	get_chunk_max(t_stack *stack, int chunk_size)
{
	int	i;
	int	max;

	i = 0;
	max = stack->data[stack->top];
	while (i < chunk_size && i < stack->size)
	{
		if (stack->data[stack->top + i] > max)
			max = stack->data[stack->top + i];
		i++;
	}
	return (max);
}

/* 
** get_chunk_min - retourne la valeur minimale
*/

int	get_chunk_min(t_stack *stack, int chunk_size)
{
	int	i;
	int	min;

	i = 0;
	min = stack->data[stack->top];
	while (i < chunk_size && i < stack->size)
	{
		if (stack->data[stack->top + i] < min)
			min = stack->data[stack->top + i];
		i++;
	}
	return (min);
}

/*
** push_chunk_to_b - utilise la valeur maximale du chunk retournée 
** par get_chunk_max pour pousser les éléments dans la pile b.
*/

void	push_chunk_to_b(t_stack *a, t_stack *b, int chunk_size, int chunk_max)
{
	int	i;

	i = 0;
	while (i < chunk_size)
	{
		if (a->data[a->top] >= chunk_max)
			pb(a, b);
		else
			ra(a);
		i++;
	}
}

/*
** effectue les opérations nécessaires pour placer 
** le maximum en haut de la pile a
*/
void	push_max_to_b(t_stack *a, t_stack *b)
{
	int	max_pos;

	max_pos = get_max_index(a);
	if (max_pos == 0)
		ra(a);
	else if (max_pos == 1)
		rra(a);
	if (is_sorted_descending(a))
	{
		pb(a, b);
		if (a->data[a->top] > a->data[a->top + 1])
			sa(a);
	}
	else
	{
		pb(a, b);
		if (a->data[a->top] < a->data[a->top + 1])
			sa(a);
	}
}
