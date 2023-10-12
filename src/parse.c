/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrodri2 <alrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:58:52 by alrodri2          #+#    #+#             */
/*   Updated: 2023/10/12 16:35:48 by alrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
No float -> if '.' in number: error
No letters -> if letter: break
No numbers -> if numbers == 0: break
*/

#include "../push_swap.h"


static	int	sig_nbr(char *nbr)
{
	int 	i;

	i = 0;
	if ((ft_strlen(nbr) == 1 && nbr[0] == '-')
		|| (ft_strlen(nbr) == 1 && nbr[0] == '+'))
		return (ERROR);
	return (TRUE);

}    

static	int	int_check(char *nbr)
{
	int	len;

	len = ft_strlen(nbr);
	if (len == 0 || (((len > 10 && nbr[0] != '-')
		&& (len > 10 && nbr[0] == '+')) || len > 11))
		return (ERROR);
	if (nbr[0] != '-' && nbr[0] != '+'
		&& len == 10 && ft_strncmp(nbr, "2147483647", 10) > 0)
		return (ERROR);
	if (nbr[0] == '-' && len == 11
		&& ft_strncmp(nbr, "-2147483648", 11) > 0)
		return (ERROR);
	if (nbr[0] == '+' && len == 11
		&& ft_strncmp(nbr, "+2147483647", 11) > 0)
		return (ERROR);
	return (TRUE);
}

static	int	ft_isnumber(char *nbr)
{
	int	i;

	i = 0;
	if (nbr[0] && (nbr[0] == '+' || nbr[0] == '-'))
		++i;
	while (nbr[i])
	{
		if (!ft_isdigit(nbr[i]))
			return (ERROR);
		++i;
	}
	return (TRUE);
}

int parse(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	if (argc <= 1)
		exit(ERROR);
	while ((i < argc) && argv[i])
	{
		if (sig_nbr(argv[i]) != ERROR && int_check(argv[i]) != ERROR 
			&& ft_isnumber(argv[i]) != ERROR)
		{
			j = i + 1;
			while (j < (argc))
			{
				if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
					exit((write(1, "Error\n", 6) * 0) + ERROR);
				++j;
			}
		}
		else
			exit((write(1, "Error\n", 6) * 0) + ERROR);
		++i;
	}
	return (TRUE);
}