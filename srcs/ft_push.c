/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialousse <ialousse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:18:22 by ialousse          #+#    #+#             */
/*   Updated: 2023/03/01 18:29:29 by ialousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_push(t_stack *src, t_stack *dest)
{
	int	tmp;

	if (src->size == 0)
		return ;
	tmp = src->data[src->top];
	src->top--;
	dest->top++;
	dest->data[dest->top] = tmp;
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
    if (stack_b->top >= 0)
    {
        stack_a->top++;
        stack_a->data[stack_a->top] = stack_b->data[stack_b->top];
        stack_b->top--;
    }
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
    if (stack_a->top >= 0)
    {
        stack_b->top++;
        stack_b->data[stack_b->top] = stack_a->data[stack_a->top];
        stack_a->top--;
    }
}