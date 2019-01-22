/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccepre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 12:12:43 by ccepre            #+#    #+#             */
/*   Updated: 2019/01/22 15:24:38 by ccepre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <libft.h>
# define BUFF_SIZE 20
# define SUBLST_SIZE 7

typedef struct	s_pile
{
	int			nb;
	int			p;
	struct s_pile	*next;
}				t_pile;

typedef struct	s_stacks
{
	t_pile		*a_pile;
	t_pile		*b_pile;
}				t_stacks;

typedef struct	s_oper_fcts
{
	char		action;
	void		(*f)(char*, t_pile**, t_pile**);
}				t_oper_fcts;

t_pile          *ft_lstnew(int nb);
void            ft_lstadd(t_pile **alst, t_pile *new);
void            ft_lstaddend(t_pile **lst, t_pile *new);
size_t          ft_lstlen(t_pile *lst);
void            ft_putlst(t_pile *lst);
void			ft_swap(int *a, int *b);
t_pile			*ft_lstgetlast(t_pile *lst);
int				ft_lstgetpos(t_pile *lst, int nb);

t_pile			*make_pile(int ac, char *av[], int visualize);
void			swap(char *operation, t_pile **a_pile, t_pile **b_pile);
void			push(char *operation, t_pile **a_pile, t_pile **b_pile);
void			rotate(char *operation, t_pile **a_pile, t_pile **b_pile);
t_oper_fcts		*make_struct(void);
int				visualizer(t_pile *a_pile, t_pile *b_pile);
int				ft_quick_sort(t_stacks *stacks, char **operations,\
		t_oper_fcts *fcts_tab, t_pile **sorted);
int				append_actions(char *actions, t_stacks *stacks,\
		char **operations, t_oper_fcts *fcts_tab);
int				action_applier(char *action, t_stacks *stacks,\
		t_oper_fcts *fcts_tab, int visualize);
char			*ft_simplifier(char **operations);
int				three_sort(t_stacks *stacks, char **operations, t_oper_fcts *fcts_tab);
int				little_list_sort(t_stacks *stacks, char **operations,\
		t_oper_fcts *fcts_tab);
int			ft_lst_opposites(t_pile *pile, int *min, int *max);

#endif
