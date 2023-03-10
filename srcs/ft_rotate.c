/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialousse <ialousse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:17:29 by ialousse          #+#    #+#             */
/*   Updated: 2023/03/10 20:24:17 by ialousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_rotate(t_stack *stack)
{
	int	tmp;
	int	i;

	if (stack->size < 2)
		return ;
	tmp = stack->data[stack->top];
	i = stack->top;
	while (i > 0)
	{
		stack->data[i] = stack->data[i - 1];
		i--;
	}
	stack->data[0] = tmp;
}

void	ra(t_stack *stack_a)
{
    int tmp;
    int i;

    if (stack_a->top >= 1)
    {
        tmp = stack_a->data[stack_a->top];
        i = stack_a->top;
        while (i > 0)
        {
            stack_a->data[i] = stack_a->data[i - 1];
            i--;
        }
        stack_a->data[0] = tmp;
    }
}

void	rb(t_stack *stack_b)
{
    int	tmp;
    int	i;

    if (stack_b->top >= 1)
    {
        tmp = stack_b->data[stack_b->top];
        i = stack_b->top;
        while (i > 0)
        {
            stack_b->data[i] = stack_b->data[i - 1];
            i--;
        }
        stack_b->data[0] = tmp;
    }
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
    ra(stack_a);
    rb(stack_b);
}
