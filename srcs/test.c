/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialousse <ialousse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:43:19 by ialousse          #+#    #+#             */
/*   Updated: 2023/03/10 20:53:09 by ialousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../include/push_swap.h"

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

void	free_stack(t_stack *stack)
{
	if (stack)
	{
		if (stack->data)
			free(stack->data);
		free(stack);
	}
}


void	init_stack(t_stack *stack, int *data, int size)
{
	stack->data = data;
	stack->size = size;
	stack->top = size - 1;
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	int		*data;

	if (argc < 2 || argc > 1001)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	data = (int *)malloc(sizeof(int) * (argc - 1));
	if (!data)
		return (1);
	for (int i = 1; i < argc; i++)
	{
		if (!ft_isinteger(argv[i]))
		{
			free(data);
			ft_putstr_fd("Error\n", 2);
			return (1);
		}
		data[i - 1] = ft_atoi(argv[i]);
	}
	init_stack(&stack_a, data, argc - 1);
	push_swap(&stack_a);
	free(data);
	free(stack_a.data);
	return (0);
}
