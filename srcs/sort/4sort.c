/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialousse <ialousse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 20:26:55 by ialousse          #+#    #+#             */
/*   Updated: 2023/03/15 18:11:28 by ialousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Trie la pile en utilisant une version modifiée de l'algorithme de tri
** par fusion. La pile est divisée en groupes et chaque groupe est trié 
** à l'aide de l'algorithme de tri par insertion. Les groupes triés sont 
** ensuite fusionnés en utilisant une variante de l'algorithme de fusion.
*/
void	sort_large(t_stack *a, t_stack *b)
{
	int	group_size;
	int	groups;

	group_size = get_group_size(a->size);
	groups = get_num_groups(a->size, group_size);
	while (groups > 0)
	{
		push_to_b(a, b, group_size, groups);
		groups--;
	}
	push_all_to_a(a, b, group_size);
	sort_remaining(a);
}

void	sort_small(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		sort_two(a);
	else if (a->size == 3)
		sort_three(a);
	else if (a->size == 4)
		sort_four(a, b);
	else if (a->size == 5)
		sort_five(a, b);
	else if (a->size <= 10)
		sort_ten(a, b);
	else
		sort_fifty(a, b);
}

void	sort_fifty(t_stack *a, t_stack *b)
{
	int	i;
	int	chunk_size;

	chunk_size = a->size / 5;
	i = 0;
	while (i < 5)
	{
		push_chunk_to_b(a, b, chunk_size, get_chunk_max(a, chunk_size));
		i++;
	}
	sort_five(a, b);
	i = 0;
	while (i < 2)
	{
		push_max_to_b(a, b);
		i++;
	}
	push_to_a(a, b);
}
