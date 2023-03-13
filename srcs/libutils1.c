/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libutils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialousse <ialousse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:50:24 by ialousse          #+#    #+#             */
/*   Updated: 2023/03/13 21:47:33 by ialousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;

	if (!src && !dst)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}