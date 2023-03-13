/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialousse <ialousse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:07:02 by ialousse          #+#    #+#             */
/*   Updated: 2023/03/13 21:45:51 by ialousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>

typedef struct s_liste
{
    void            *content;
    struct s_liste  *next;
}                   t_liste;
typedef struct	s_stack
{
    int		*data;
    int		size;
    int		top;
    t_liste	*instructions;
}	t_stack;

/********************COMMEND**********************/
void	sa(t_stack *stack_a);/********************/
void	sb(t_stack *stack_b);/********************/
void	ss(t_stack *stack_a, t_stack *stack_b);/**/
void	pb(t_stack *stack_a, t_stack *stack_b);/**/
void	pa(t_stack *stack_a, t_stack *stack_b);/**/
void	ra(t_stack *stack_a);/********************/
void	rb(t_stack *stack_b);/********************/
void	rr(t_stack *stack_a, t_stack *stack_b);/**/
void	rra(t_stack *stack);/*********************/
void	rrb(t_stack *stack);/*********************/
/********************COMMEND**********************/

/*************LIBUTILS.C*****************/
int		ft_atoi(char *str);/*************/
int		ft_isdigit(int c);/**************/
size_t	ft_strlen(const char *str);/*****/
long	ft_atol(const char *str);/*******/
int		ft_strisint(const char *str);/***/
void	ft_putstr_fd(char *s, int fd);
void	*ft_memcpy(void *dst, const void *src, size_t n);/**/
/*************LIBUTILS.C*****************/

void	print_stack(t_stack *stack);

/************************MAIN****************************/
void	push_swap(t_stack *stack_a, t_stack *stack_b);/**/
/************************MAIN****************************/

/**********************************UTILS************************************/
int		get_min(t_stack *stack);/*******************************************/
int		get_max(t_stack *stack);/*******************************************/
int		get_num_groups(int size, int group_size);/**************************/
int		get_group_size(int size);/******************************************/
void	push_to_b(t_stack *a, t_stack *b, int group_size, int group_num);/**/
void	push_all_to_a(t_stack *a, t_stack *b, int group_size);/*************/
void	sort_remaining(t_stack *a);/****************************************/
int		get_next(t_stack *a, int cur, int dir);/****************************/
void	pb_to_a(t_stack *a, t_stack *b, int group_size);/*******************/
int		is_sorted(t_stack *stack);
int		get_max_index(t_stack *stack);
int		is_sorted_descending(t_stack *stack);
void	push_to_a(t_stack *a, t_stack *b);
int		stack_is_empty(t_stack *stack);/*****************************/
/**********************************UTILS************************************/

/*******************SORT**********************/
void	sort_two(t_stack *stack);/************/
void	sort_three(t_stack *stack);/**********/
void	sort_four(t_stack *a, t_stack *b);/***/
void	sort_five(t_stack *a, t_stack *b);/***/
void	sort_ten(t_stack *a, t_stack *b);/****/
void	sort_fifty(t_stack *a, t_stack *b);/**/
void	sort_small(t_stack *a, t_stack *b);/**/
void	sort_large(t_stack *a, t_stack *b);/**/
/*******************SORT**********************/

/*******************CHUCK**********************/
int		get_chunk_max(t_stack *stack, int chunk_size);
int		get_chunk_min(t_stack *stack, int chunk_size);
void	push_chunk_to_b(t_stack *a, t_stack *b, int chunk_size, int chunk_max);
void	push_max_to_b(t_stack *a, t_stack *b);

/*******************JSP**********************/
t_stack	*parse_stack(int argc, char **argv);
t_stack	*stack_init(int size);
int		is_valid_arg(const char *str);
void	push(t_stack *stack, int value);
void	exit_failure(char *message);
void	free_stack(t_stack *stack);
void	sort_stack(t_stack *a, t_stack *b);
int		stack_size(t_stack *stack);
void	print_instructions(t_liste *instructions);
#endif