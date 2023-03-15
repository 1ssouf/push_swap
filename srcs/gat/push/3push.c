/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialousse <ialousse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:00:28 by ialousse          #+#    #+#             */
/*   Updated: 2023/03/15 18:00:56 by ialousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** push ajoute une valeur à la pile, 
** en agrandissant le tableau de données si nécessaire
*/

void	push(t_stack *stack, int value)
{
	int	*new_data;
	int	new_size;

	if (stack->top + 1 == stack->size)
	{
		new_size = stack->size * 2;
		new_data = malloc(new_size * sizeof(int));
		if (new_data == NULL)
		{
			ft_putstr_fd("Error: failed to allocate memory\n", 2);
			exit(EXIT_FAILURE);
		}
		ft_memcpy(new_data, stack->data, stack->size * sizeof(int));
		free(stack->data);
		stack->data = new_data;
		stack->size = new_size;
	}
	stack->top++;
	stack->data[stack->top] = value;
}

void	push_swap(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 2)
		sort_two(stack_a);
	else if (stack_a->size == 3)
		sort_three(stack_a);
	else if (stack_a->size <= 5)
		sort_small(stack_a, stack_b);
	else
		sort_large(stack_a, stack_b);
}