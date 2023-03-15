/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialousse <ialousse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:05:06 by ialousse          #+#    #+#             */
/*   Updated: 2023/03/13 21:47:27 by ialousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_stack *stack_a)
{
	int	tmp;

    if (stack_a->top >= 1)
    {
        tmp = stack_a->data[stack_a->top];
        stack_a->data[stack_a->top] = stack_a->data[stack_a->top - 1];
        stack_a->data[stack_a->top - 1] = tmp;
    }
}

void	sb(t_stack *stack_b)
{
    int	tmp;

    if (stack_b->top >= 1)
    {
        tmp = stack_b->data[stack_b->top];
        stack_b->data[stack_b->top] = stack_b->data[stack_b->top - 1];
        stack_b->data[stack_b->top - 1] = tmp;
    }
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
    sa(stack_a);
    sb(stack_b);
}
