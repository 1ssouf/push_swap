/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialousse <ialousse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:09:13 by ialousse          #+#    #+#             */
/*   Updated: 2023/03/15 18:10:48 by ialousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

/*
** Vérifie si une pile est triée dans l'ordre croissant.
*/

int	is_sorted(t_stack *stack)
{
	int	i;

	i = stack->top;
	while (i < stack->size - 1)
	{
		if (stack->data[i] > stack->data[i + 1])
			return (0);
		i++;
	}
	return (1);
}

/*
** Trie les éléments restants de la pile a.
*/

void	sort_remaining(t_stack *a)
{
	while (!is_sorted(a))
	{
		if (a->data[a->top] > a->data[a->top + 1])
			sa(a);
		if (a->size > 2 && a->data[a->top] < a->data[a->top + 2])
			ra(a);
		else
			rra(a);
	}
}
