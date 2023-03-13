/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialousse <ialousse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:04:55 by ialousse          #+#    #+#             */
/*   Updated: 2023/03/13 21:47:53 by ialousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** parcourt la pile stack à partir de l'indice stack->top et retourne 
** l'indice de l'élément ayant la valeur maximale
*/

int	get_max_index(t_stack *stack)
{
	int	max_index;
	int	max_value;
	int	i;

	if (stack_is_empty(stack))
		return (-1);
	max_index = stack->top;
	max_value = stack->data[max_index];
	i = stack->top;
	while (i < stack->size)
	{
		if (stack->data[i] > max_value)
		{
			max_index = i;
			max_value = stack->data[i];
		}
		i++;
	}
	return (max_index);
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


/*
** permet de ramener tous les éléments de la pile b sur la pile a
*/
void	push_to_a(t_stack *a, t_stack *b)
{
	while (b->size > 0)
	{
		if (b->top == b->size - 1)
			pa(a, b);
		else if (b->top == 0 && b->data[b->top] < b->data[b->top + 1])
			sb(b);
		else if (b->data[b->top] > b->data[b->top + 1])
			rb(b);
		else
			pa(a, b);
	}
}

/*
** renvoie 1 si la taille de la pile est égale à 0, sinon 0
*/
int	stack_is_empty(t_stack *stack)
{
	return (stack->size == 0);
}
