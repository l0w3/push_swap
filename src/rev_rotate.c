/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrodri2 <alrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:18:03 by alrodri2          #+#    #+#             */
/*   Updated: 2023/10/12 16:35:10 by alrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


static int	check_tango(t_stack *src, int stk)
{
	swap(src, 0);
	if (stk == STKA)
		ft_printf("rra\n");
	else if (stk == STKB)
		ft_printf("rrb\n");
	return (SUCCESS);
}

int	rev_rotate(t_stack *src, int stk)
{
	t_node	*top;
	t_node	*bot;
	t_node	*next;

	if (!src || src->size < 2)
		return (ERROR);
	if (src->size == 2)
	{
		check_tango(src, stk);
		return (SUCCESS);
	}
	get_bot(src, &bot, -1);
	top = src->first;
	bot->next = top;
	get_bot(src, &next, -2);
	next->next = NULL;
	src->first = bot;
	if (stk == STKA)
		ft_printf("rra\n");
	else if (stk == STKB)
		ft_printf("rrb\n");
	return (SUCCESS);
}

int	rev_rot_rot(t_stack *stka, t_stack *stkb)
{
	if (!stka || stka->size < 2 || !stkb || stkb->size < 2)
		return (ERROR);
	rev_rotate(stka, 0);
	rev_rotate(stkb, 0);
	ft_printf("rrr\n");
	return (SUCCESS);
}