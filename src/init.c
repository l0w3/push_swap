/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrodri2 <alrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:19:05 by alrodri2          #+#    #+#             */
/*   Updated: 2023/10/12 16:35:19 by alrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


static int	init_stack(t_stack **stack)
{
	*stack = ft_calloc(sizeof(t_stack), 1);
	if (!*stack)
		return (ERROR);
	(*stack)->size = 0;
	(*stack)->first = NULL;
	(*stack)->last = NULL;
	return (SUCCESS);
}

int	double_init(t_stack **stk1, t_stack **stk2)
{
	if (init_stack(stk1) == ERROR || init_stack(stk2) == ERROR)
	{
		write(2, "Error\n", 6);
		exit(ERROR);
	}
	return (SUCCESS);
}