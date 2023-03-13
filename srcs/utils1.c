/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialousse <ialousse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:08:05 by ialousse          #+#    #+#             */
/*   Updated: 2023/03/13 21:47:50 by ialousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
** Trie les éléments restants de la pile a.
*/

void	sort_remaining(t_stack *a)
{
	while (!is_sorted(a))
	{
		if (a->data[a->top] > a->data[a->top + 1])
			sa(a);
		if (a->size > 2 && a->data[a->top] < a->data[a->top + 2])
			ra(a);
		else
			rra(a);
	}
}

/*
** Renvoie l'élément suivant à traiter
*/

int	get_next(t_stack *a, int cur, int dir)
{
	int		i;
	int		next;

	if (dir == 1)
	{
		i = a->top;
		while (i < a->size && a->data[i] < cur)
			i++;
		if (i == a->size)
			next = get_min(a);
		else
			next = a->data[i];
	}
	else
	{
		i = a->size - 1;
		while (i >= a->top && a->data[i] > cur)
			i--;
		if (i < a->top)
			next = get_max(a);
		else
			next = a->data[i];
	}
	return (next);
}

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
** Vérifie si une pile est triée dans l'ordre croissant.
*/

int	is_sorted(t_stack *stack)
{
	int	i;

	i = stack->top;
	while (i < stack->size - 1)
	{
		if (stack->data[i] > stack->data[i + 1])
			return (0);
		i++;
	}
	return (1);
}
