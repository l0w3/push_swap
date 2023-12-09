/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrodri2 <alrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:33:11 by alrodri2          #+#    #+#             */
/*   Updated: 2023/12/09 12:49:10 by alrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	print_node(t_stack *stk)
{
	t_node	*aux;

	if (!stk)
		return (ERROR);
	aux = stk->first;
	while (aux)
	{
		ft_printf("El nodo actual: %p el nodo siguiente es: %p\n",
			aux, aux->next);
		ft_printf("El contenido es: %i el indice es: %i\n",
			aux->cont, aux->index);
		aux = aux->next;
	}
	ft_printf("El tamaño del stack es: %i\n", stk->size);
	return (SUCCESS);
}

int	free_willy(t_stack *stk)
{
	t_node	*rm;

	if (!stk)
		return (SUCCESS);
	while (stk->first)
	{
		rm = stk->first;
		stk->first = stk->first->next;
		free(rm);
	}
	free(stk);
	return (SUCCESS);
}

void	willy_willy(t_stack *stka, t_stack *stkb)
{
	free_willy(stka);
	free_willy(stkb);
}
