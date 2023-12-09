/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrodri2 <alrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:28:29 by alrodri2          #+#    #+#             */
/*   Updated: 2023/12/09 12:46:35 by alrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	push_stack(t_stack **stk, int cont, int index)
{
	t_node	*new;

	new = ft_calloc(sizeof(t_node), 1);
	if (!new)
		return (ERROR);
	new->cont = cont;
	new->index = index;
	new->next = (*stk)->first;
	(*stk)->first = new;
	(*stk)->size++;
	return (TRUE);
}

int	pop_stack(t_stack **stk)
{
	t_node	*rm;
	t_node	*next;

	if (!*stk || (*stk)->size == 0)
		return (ERROR);
	rm = (*stk)->first;
	next = (*stk)->first->next;
	free(rm);
	(*stk)->first = next;
	(*stk)->size--;
	return (SUCCESS);
}

int	push(t_stack **src, t_stack **dst, int stk)
{
	if (!src || (*src)->size == 0)
		return (ERROR);
	push_stack(dst, (*src)->first->cont, (*src)->first->index);
	pop_stack(src);
	if (stk == 1)
		ft_printf("pa\n");
	else if (stk == 2)
		ft_printf("pb\n");
	return (SUCCESS);
}
