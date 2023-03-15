/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialousse <ialousse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:43:19 by ialousse          #+#    #+#             */
/*   Updated: 2023/03/15 18:14:13 by ialousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_instructions(t_liste *instructions)
{
	while (instructions != NULL)
	{
		ft_putstr_fd(instructions->content, 1);
		ft_putstr_fd("\n", 1);
		instructions = instructions->next;
	}
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

int	main(int argc, char **argv)
{
    t_stack *stack_a;
	t_stack *stack_b = NULL;

    if (argc < 2)
    {
        ft_putstr_fd("Error: missing arguments\n", 2);
        return (1);
    }
    stack_a = parse_stack(argc, argv);
    if (stack_a == NULL)
    {
        ft_putstr_fd("Error: invalid input\n", 2);
        return (1);
    }
    sort_stack(stack_a, stack_b);
    print_instructions(stack_a->instructions);
    free_stack(stack_a);
    return (0);
}