/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jspff.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialousse <ialousse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:02:58 by ialousse          #+#    #+#             */
/*   Updated: 2023/03/13 21:47:30 by ialousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
** is_valid_arg vérifie si la chaîne de caractères donnée 
** est un entier positif valide (c'est-à-dire une suite de chiffres)
*/

int	is_valid_arg(const char *str)
{
	if (*str == '-')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

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

int	stack_size(t_stack *stack)
{
    return (stack->top + 1);
}
