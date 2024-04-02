/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:08:10 by aamirkha          #+#    #+#             */
/*   Updated: 2024/03/26 16:39:53 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include <stdint.h>
#include <stdio.h>
// #define __CHECK__

typedef struct s_node
{
	int				m_val;
	struct s_node	*m_next;
	struct s_node	*m_prev;

}					t_node;

typedef struct s_stack
{
	char			m_name;
	t_node			*m_head;
}					t_stack;

typedef enum e_input
{
	invalid_input = 2147483650
}					t_input;

typedef enum e_mode
{
	shadow,
	visible
}					t_mode;

typedef void		(*t_fptr)(t_node *);
typedef int			(*t_unary_predicate)(t_node *);
typedef t_node		*(*t_cmp)(t_node *, t_node *);

// stack methods
void				sort_stacks(t_stack *const a, t_stack *const b);
t_stack				*stack_init(char const name);
t_node				*node_init(int const val);
t_stack				*a_init(int ac, char **av, char const name);
t_node				*find(int const val, t_stack *stack);
int					top(t_stack *const stack);
void				push(int const val, t_stack *const stack);
void				traverse(t_fptr f, t_node *head);
int					traverse_unary_predicate(t_unary_predicate f,
						t_stack *const stack, t_node *start, t_node *end);
t_node				*traverse_binary_predicate(t_cmp f, t_node *head);
void				print(t_stack *stack);
void				clear(t_stack *stack);
int					empty(t_stack *const stack);

void				swap(t_stack *const stack, t_mode mode);
int					pop(t_stack *const stack);

void				push_a_b(t_stack *const lhv, t_stack *const rhv);
void				rotate(t_stack *const stack, t_mode mode);
void				rrotate(t_stack *const stack, t_mode mode);
void				destroy(t_stack **stack);
void				_print(t_node *node);
void				_clear(t_node *const node);

// unused functions
void				ss(t_stack *const a, t_stack *const b);
void				rr(t_stack *const a, t_stack *const b);
void				rrr(t_stack *const a, t_stack *const b);

// error handling
int					alloc_nums(int ac, char **av, t_stack *stack);
void				free_mat(char **mat);

// sorting functions
int					fullsorted(t_stack *stack);
int					sorted(t_stack *const stack);
void				print_parallel(t_stack *a, t_stack *b);
void				organize_rotate(t_stack *const stack, t_node *end);
t_node				*_smallest(t_node *f, t_node *l);
int					_sorted(t_node *node);
t_node				*_smallest(t_node *f, t_node *l);
t_node				*smallest(t_stack *const stack);

// my favorite
void				__death_666___(void);
