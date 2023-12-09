/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrodri2 <alrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:14:21 by alrodri2          #+#    #+#             */
/*   Updated: 2023/12/09 12:47:31 by alrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	check_tango(t_stack *src, int stk)
{
	swap(src, 0);
	if (stk == STKA)
		ft_printf("ra\n");
	else if (stk == STKB)
		ft_printf("rb\n");
	return (SUCCESS);
}

int	get_bot(t_stack *src, t_node **bot, int limit)
{
	int	i;

	i = 0;
	*bot = src->first;
	while (i < (src->size + limit))
	{
		*bot = (*bot)->next;
		i++;
	}
	return (SUCCESS);
}

int	rotate(t_stack *src, int stk)
{
	t_node	*bot;
	t_node	*top;
	t_node	*next;

	if (!src || src->size < 2)
		return (ERROR);
	if (src->size == 2)
	{
		check_tango(src, stk);
		return (SUCCESS);
	}
	get_bot(src, &bot, -1);
	next = src->first->next;
	top = src->first;
	top->next = NULL;
	bot->next = top;
	src->first = next;
	if (stk == STKA)
		ft_printf("ra\n");
	else if (stk == STKB)
		ft_printf("rb\n");
	return (SUCCESS);
}

int	rotate_rotate(t_stack *stka, t_stack *stkb)
{
	if (!stka || stka->size < 2 || !stkb || stkb->size < 2)
		return (ERROR);
	rotate(stka, 0);
	rotate(stkb, 0);
	ft_printf("rr\n");
	return (SUCCESS);
}
