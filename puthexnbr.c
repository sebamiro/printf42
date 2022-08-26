/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puthexnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seba <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 15:31:21 by seba              #+#    #+#             */
/*   Updated: 2022/08/22 15:10:54 by seba             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hexlen(unsigned int n)
{
	int		x;

	x = 1;
	while (n >= 16)
	{
		x++;
		n = n / 16;
	}
	return (x);
}

int	puthexnbr(unsigned int n, char x)
{
	char	*nums;
	int		total;

	total = 0;
	nums = "0123456789abcdef";
	if (n >= 16)
	{
		total += puthexnbr((n / 16), x);
		total += puthexnbr((n % 16), x);
	}
	else
	{
		if (x == 'X' && n > 9)
			total += ftputchar(nums[n] - 32);
		else
			total += ftputchar(nums[n]);
	}
	if (total != hexlen(n))
		return (-1);
	return (total);
}
