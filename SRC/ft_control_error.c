/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-ped <made-ped@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 12:48:28 by made-ped          #+#    #+#             */
/*   Updated: 2026/02/21 13:03:04 by made-ped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../INC/philosopher.h"

void	ft_control_error(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
	{
		write(2, "ERROR\n", 6);
		exit(0);
	}
	printf("control error\n");
	return;
}
