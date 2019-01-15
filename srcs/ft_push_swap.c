/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccepre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 16:57:38 by ccepre            #+#    #+#             */
/*   Updated: 2019/01/15 15:31:28 by ccepre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int main(int ac, char *av[])
{
	t_pile	*a_pile;
	t_pile	*b_pile;
	char	*operations;

	if (!(a_pile = make_pile(ac, av, 0)))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	ft_putlst(a_pile);
	if (!(b_pile = (t_pile*)malloc(sizeof(t_pile))))
		return (1);
	if (!(operations = ft_quick_sort(&a_pile, NULL)))
		return (1);
	printf("OK\n");
	write(1, operations, ft_strlen(operations));
	free(operations);
	return (0);
}
