/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialousse <ialousse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:19:23 by ialousse          #+#    #+#             */
/*   Updated: 2023/03/09 18:47:50 by ialousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_reverse_rotate(t_stack *stack)
{
	int	tmp;
	int	i;

	if (stack->size < 2)
		return ;
	tmp = stack->data[0];
	i = 0;
	while (i < stack->top)
	{
		stack->data[i] = stack->data[i + 1];
		i++;
	}
	stack->data[stack->top] = tmp;
}

void	rra(t_stack *stack)
{
	int	temp;
	int	i;

	if (stack->top > 0)
	{
		temp = stack->data[stack->top - 1];
		i = stack->top - 1;
		while (i > 0)
		{
			stack->data[i] = stack->data[i - 1];
			i--;
		}
		stack->data[0] = temp;
	}
}

void	rrb(t_stack *stack)
{
	int	temp;
	int	i;

	if (stack->top > 0)
	{
		temp = stack->data[stack->top - 1];
		i = stack->top - 1;
		while (i > 0)
		{
			stack->data[i] = stack->data[i - 1];
			i--;
		}
		stack->data[0] = temp;
	}
}
