/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialousse <ialousse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:56:54 by ialousse          #+#    #+#             */
/*   Updated: 2023/03/15 18:00:54 by ialousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Déplace le plus grand élément de la pile B vers la pile A.
*/

void	pb_to_a(t_stack *a, t_stack *b, int group_size)
{
	int	index_max;
	int	index_cur;
	int	next;

	index_max = get_max_index(b);
	index_cur = b->top;
	while (index_cur != index_max)
	{
		next = get_next(b, b->data[index_cur], 1);
		if (next <= group_size || (b->data[index_cur] == get_max(b) && b->size - b->top <= group_size))
			break;
		if (index_cur > index_max - index_cur)
			rrb(b);
		else
			rb(b);
		index_cur = b->top;
	}
	pa(b, a);
}

/*
** Pousse tous les éléments restants de la pile b vers la pile a.
*/

void push_all_to_a(t_stack *a, t_stack *b, int group_size)
{
    while (b->size > 0)
    {
        int max_value;

		max_value = get_max(b);
		while (get_next(b, b->data[b->top], 1) != -1)
        {
            if (b->data[b->top] == max_value || 
                get_next(b, b->data[b->top], 1) <= group_size ||
                (b->size - b->top) <= group_size)
                pb_to_a(a, b, group_size);
            else
                rb(b);
        }
        while (b->size > 0)
            pb_to_a(a, b, group_size);
    }
}

/*
** permet de ramener tous les éléments de la pile b sur la pile a
*/
void	push_to_a(t_stack *a, t_stack *b)
{
	while (b->size > 0)
	{
		if (b->top == b->size - 1)
			pa(a, b);
		else if (b->top == 0 && b->data[b->top] < b->data[b->top + 1])
			sb(b);
		else if (b->data[b->top] > b->data[b->top + 1])
			rb(b);
		else
			pa(a, b);
	}
}

void	push_to_b(t_stack *a, t_stack *b, int group_size, int group_num)
{
	int	i;

	i = 0;
	while (i < group_size && a->size > 0)
	{
		if ((a->data[a->top] / group_num) == group_size - i - 1)
			pb(a, b);
		else
			ra(a);
		i++;
	}
}
