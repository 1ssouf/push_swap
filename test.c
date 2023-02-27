/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialousse <ialousse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:43:19 by ialousse          #+#    #+#             */
/*   Updated: 2023/02/27 13:11:51 by ialousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_sa(int *stack_a, int top_a)
{
	int	tmp;

	if (top_a > 0)
	{
		tmp = stack_a[top_a];
		stack_a[top_a] = stack_a[top_a - 1];
		stack_a[top_a - 1] = tmp;
	}
}

void	ft_sb(int *stack_b, int top_b)
{
	int	tmp;
	if (top_b > 0)
	{
		tmp = stack_b[top_b];
		stack_b[top_b] = stack_b[top_b - 1];
		stack_b[top_b - 1] = tmp;
	}
}

// int	main(void)
// {
// 	int	*a;
// 	int	b, c, d;
// 	a[1] = 545;
// 	a[2] = 212;
// 	a[3] = 200;
// 	b = a[1];
// 	c = a[2];
// 	d = a[3];

// 	ft_sa(a, 1);
// 	printf("-------%d-----\n",b);
// 	return (0);
// }