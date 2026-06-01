/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelescu <stelescu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 00:00:00 by youssef           #+#    #+#             */
/*   Updated: 2026/06/01 16:17:09 by stelescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int	*tab;
	int *coord_value;
	int	size;
	int	top;
}		t_stack;

typedef struct s_option
{
	int	bench;
	int	simple;
	int	medium;
	int	complx;
	int	adaptive;	
}				t_option;

typedef struct s_benchmark
{
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
	int		disorder;
	char	*startegy;
}				t_benchmark;
t_stack	*create_stack(int size);
int		search_stack(t_stack *a, int value);
t_stack	*destroy_stack(t_stack *a);
t_stack	*ft_copy_stack(t_stack *a);
int		push_stack(t_stack *s, int value);
int		pop(t_stack *s);
int		swap_stack(t_stack *a, char c);
int		push_in(t_stack *src, t_stack *dest, char c);
int		re_rotate_stack(t_stack *a, char c);
int		rotate_stack(t_stack *a, char c);
int		ft_strlen(char *s);
int		ft_error(t_stack *a, t_stack *b);
int		ft_is_sorted(t_stack *a);
int		ft_parse(char *s, int *out);
t_stack	*ft_verfier(char *s[], int l, int skip);
int		ft_strcmp(char *s1, char *s2);
void	ft_op(t_option *p);
int		already_option(t_option *p);
int		ft_option(char *s, t_option *p);
int		ft_skip(t_option *op, char **av, int ac);
void	ft_bzero(void *p, size_t size);
void	decide_algorithm(t_stack *a, t_stack *b, t_option *op, int ac);
void	ft_simple(t_stack *a, t_stack *b, t_benchmark *bench);
char	*get_next_line(int fd);
int		ft_opration(char *s, t_stack *a, t_stack *b);
void	display_bench(t_benchmark *bench);
int		ft_printf(const char *s, ...);
int		ft_find_sqrt(int nb);
int		*ft_range(int min, int max);
void	ft_medium(t_stack *a, t_stack *b, t_benchmark *bench, int nb_count);

#endif
