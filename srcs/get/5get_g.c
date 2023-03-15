/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utlis.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialousse <ialousse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 15:38:52 by ialousse          #+#    #+#             */
/*   Updated: 2023/03/15 17:59:49 by ialousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** get_min - trouve la plus petite valeur dans la pile donnée
** Return: la plus petite valeur dans la pile
*/

int	get_min(t_stack *stack)
{
	int	i;
	int	min;

	min = stack->data[stack->top];
	i = stack->top;
	while (i < stack->size)
	{
		if (stack->data[i] < min)
			min = stack->data[i];
		i++;
	}
	return (min);
}

/*
** get_max - trouve la plus grande valeur dans la pile donnée
** Return: la plus grande valeur dans la pile
*/

int	get_max(t_stack *stack)
{
	int	i;
	int	max;

	max = stack->data[stack->top];
	i = stack->top;
	while (i < stack->size)
	{
		if (stack->data[i] > max)
			max = stack->data[i];
		i++;
	}
	return (max);
}

/*
** get_group_size - Obtien la taille de groupe optimale pour le tri.
** La taille du groupe est déterminée en prenant 
** la racine carrée de la taille de la pile.
*/

int	get_group_size(int size)
{
	int	group_size;

	group_size = 0;
	while (group_size * group_size < size)
		group_size++;
	return (group_size);
}

/*
** get_num_groups - Obtien le nombre de groupes nécessaires pour trier la pile.
** Le nombre de groupes est déterminé en divisant la taille 
** de la pile par la taille du groupe.
*/

int	get_num_groups(int size, int group_size)
{
	return ((size + group_size - 1) / group_size);
}
