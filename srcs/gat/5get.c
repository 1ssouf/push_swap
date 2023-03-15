/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialousse <ialousse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:08:05 by ialousse          #+#    #+#             */
/*   Updated: 2023/03/15 18:14:34 by ialousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


/*
** Renvoie l'élément suivant à traiter
*/

int	get_next(t_stack *a, int cur, int dir)
{
	int		i;
	int		next;

	if (dir == 1)
	{
		i = a->top;
		while (i < a->size && a->data[i] < cur)
			i++;
		if (i == a->size)
			next = get_min(a);
		else
			next = a->data[i];
	}
	else
	{
		i = a->size - 1;
		while (i >= a->top && a->data[i] > cur)
			i--;
		if (i < a->top)
			next = get_max(a);
		else
			next = a->data[i];
	}
	return (next);
}

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
