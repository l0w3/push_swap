/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrodri2 <alrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:33:11 by alrodri2          #+#    #+#             */
/*   Updated: 2023/10/12 16:42:21 by alrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int is_sorted(t_stack *stack)
{
    t_node *node;

    node = stack->first;
    while(node && node ->next)
    {
        if (node->index > node->next->index)
            return (-1);
        node = node->next;
    }
    return (1);
}

