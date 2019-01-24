/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sublist_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccepre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 16:48:45 by ccepre            #+#    #+#             */
/*   Updated: 2019/01/24 18:08:00 by ccepre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static int	three_sort(t_stacks *stacks, char **operations, int index)
{
	char	*actions;
	t_pile	*pile;
	t_pile	*current;

//	printf("--------THREE SORT-------\n");
	actions = "";
	pile = index ? stacks->b_pile : stacks->a_pile;
	if (pile->nb > pile->next->nb &&\
			pile->nb > pile->next->next->nb)
	{
		if (pile->next->nb < pile->next->next->nb)
			actions = index ? "pa\nsb\npb" : "rra";
		else
			actions = index ? "" : "rra\nrra";
	}
	else if (pile->nb < pile->next->nb &&\
			pile->nb < pile->next->next->nb)
	{
		if (pile->next->nb < pile->next->next->nb)
			actions = index ? "rb\nsb" : "";
		else
			actions = index ? "rb" : "rra\nsa";
	}
	else
	{
		if (pile->next->nb < pile->next->next->nb)
			actions = index ? "rrb" : "sa";
		else
			actions = index ? "sb" : "rra";
	}
	if (*actions && append_actions(actions, stacks, operations))
		return (1);
	current = stacks->a_pile;
	while (!index && current)
	{
		current->p = 1;
		current = current->next;
	}	
	while (stacks->b_pile)
	{
		stacks->b_pile->p = 1;
		if (append_actions("pa", stacks, operations))
			return (1);
	}
//	ft_putlst(stacks->a_pile);
//	ft_putlst(stacks->b_pile);
//	printf("----THREE SORT DONE-----\n");
//	getchar();
	return (0);
}

static int	one_two_sort(t_stacks *stacks, char **operations, int index)
{
	int		len;
	t_pile	*pile;
	char	*action;

	pile = index ? stacks->b_pile : stacks->a_pile;
	len = ft_lstlen(pile);
//	printf("----ONE TWO SORT-----\n");
	if (len == 2)
		if (pile->nb < pile->next->nb && index)
		{
			action = index ? "sb" : "sa";
			if (append_actions(action, stacks, operations))
				return (1);
		}
	action = index ? "pa" : "pb";
	while (pile && index)
	{
		pile->p = 1;
		if (append_actions(action, stacks, operations))
			return (1);
		pile = index ? stacks->b_pile : stacks->a_pile;
	}
//	ft_putlst(stacks->a_pile);
//	ft_putlst(stacks->b_pile);
//	printf("----ONE TWO SORT DONE-----\n");
//	getchar();
	return (0);
}

static int	push_nbr(t_stacks *stacks, char **operations, int index, int nbr)
{
	int	pos_nbr;
	char	*action;
	t_pile	*pile;
	int len;

	pile = index ? stacks->b_pile : stacks->a_pile;
	pos_nbr = ft_lstgetpos(pile, nbr);
	len = ft_lstlen(pile);
	if (pos_nbr <= len / 2)
	{
		action = index ? "rb" : "ra";
		while (pos_nbr--)
			if (append_actions(action, stacks, operations))
				return (1);
	}
	else
	{
		action = index ? "rrb" : "rra";
		while (++pos_nbr <= len)
			if (append_actions(action, stacks, operations))
				return (1);
	}
	pile = index ? stacks->b_pile : stacks->a_pile;
	pile->p = 1;
	action = index ? "pa" : "pb";
	if (append_actions(action, stacks, operations))
		return (1);
	return (0);
}

int	little_list_sort(t_stacks *stacks, char **operations, int index)
{
	int	nbr;
	t_pile	*pile;
	int	i;

	pile = index ? stacks->b_pile : stacks->a_pile;
	i = ft_lstlen(pile);
	while (--i >= 3)
	{
//		printf("-----SELECTION SORT------\n");
		pile = index ? stacks->b_pile : stacks->a_pile;
		nbr = pile->nb;
		if (index)
			ft_lst_opposites(pile, NULL, &nbr);
		else
			ft_lst_opposites(pile, &nbr, NULL);
		if (push_nbr(stacks, operations, index, nbr))
			return (1);
//		ft_putlst(stacks->a_pile);
//		ft_putlst(stacks->b_pile);
//		printf("----SELECTION SORT DONE-----\n");
//		getchar();
	}
	if (i == 2)
		return (three_sort(stacks, operations, index));
	else
		return (one_two_sort(stacks, operations, index));
	return (0);
}
