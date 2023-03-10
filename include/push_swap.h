/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialousse <ialousse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:07:02 by ialousse          #+#    #+#             */
/*   Updated: 2023/03/10 20:51:29 by ialousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

typedef struct	s_stack
{
	int	*data;
	int	size;
	int	top;
}				t_stack;

/**********SWAP.C************/
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);

/**********PUSH.C************/
void	pb(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);

/**********ROTATE.C**********/
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);

/*****REVERSE_ROTATE.C*******/
void	rra(t_stack *stack);
void	rrb(t_stack *stack);

/*****LIBUTILS.C********/
int		ft_atoi(char *str);
int		ft_isdigit(int c);
size_t	ft_strlen(const char *str);
long	ft_atol(const char *str);
int		ft_strisint(const char *str);
void	ft_putstr_fd(char *s, int fd);

/*******THREE_NBR********/
int		main_three(int argc, char **argv);
void	sort_three(t_stack *stack);

/*********TWO_NBR*********/
void	sort_two(t_stack *stack);
int		main_two(int argc, char **argv);


void	print_stack(t_stack *stack);

/*********MAIN*********/
void	push_swap(t_stack *stack_a);


/*********SORT*********/
void	sort_two(t_stack *stack);
void	sort_three(t_stack *stack);
void	sort_four(t_stack *a, t_stack *b);
void	sort_five(t_stack *a, t_stack *b);
void	sort_ten(t_stack *a, t_stack *b);
void	sort_fifty(t_stack *a, t_stack *b);
void	sort_small(t_stack *a, t_stack *b);
void	sort_large(t_stack *a, t_stack *b);

#endif