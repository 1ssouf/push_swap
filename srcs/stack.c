/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialousse <ialousse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:26:54 by ialousse          #+#    #+#             */
/*   Updated: 2023/03/15 18:13:50 by ialousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** stack_init alloue de la mémoire pour la pile et 
** son tableau de données, et renvoie un pointeur vers la pile initialisée
*/

t_stack	*stack_init(int size)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->data = malloc(sizeof(int) * size);
	if (!stack->data)
	{
		free(stack);
		return (NULL);
	}
	stack->size = size;
	stack->top = -1;
	return (stack);
}

/*
** créer deux piles vides, stack_a et stack_b, 
** qui seront remplies par les nombres passés en arguments.
*/

t_stack	*parse_stack(int argc, char **argv)
{
	t_stack	*stack_a;
	int		i;

	stack_a = stack_init(argc - 1);
	if (stack_a == NULL)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		if (!is_valid_arg(argv[i]))
		{
			free_stack(stack_a);
			return (NULL);
		}
		push(stack_a, ft_atoi(argv[i]));
		i++;
	}
	return (stack_a);
}


int	stack_size(t_stack *stack)
{
    return (stack->top + 1);
}

void sort_stack(t_stack *a, t_stack *b)
{
    if (stack_size(a) <= 1)
        return;
    else if (stack_size(a) == 2)
    {
        if (a->data[a->top] > a->data[a->top + 1])
            sa(a);
        return;
    }
    else if (stack_size(a) == 3)
        sort_three(a);
    else if (stack_size(a) <= 5)
        sort_five(a, b);
    else
        sort_large(a, b);
}

/*
** renvoie 1 si la taille de la pile est égale à 0, sinon 0
*/
int	stack_is_empty(t_stack *stack)
{
	return (stack->size == 0);
}