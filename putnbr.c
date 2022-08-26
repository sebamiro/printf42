/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seba <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 13:04:24 by seba              #+#    #+#             */
/*   Updated: 2022/08/22 18:44:04 by seba             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	unlen(unsigned int n)
{
	int	total;

	total = 1;
	while (n > 9)
	{
		total++;
		n = n / 10;
	}
	return (total);
}

static int	nlen(int n)
{
	int	total;

	total = 1;
	if (n < 0)
	{
		total++;
		n = -n;
	}
	while (n > 9)
	{
		total++;
		n = n / 10;
	}
	return (total);
}

int	ftputnbr(int n)
{
	int	total;

	total = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	else if (n < 0)
	{
		total += ftputchar('-');
		total += ftputnbr(-n);
	}
	else if (n > 9)
	{
		total += ftputnbr(n / 10);
		total += ftputnbr(n % 10);
	}
	else
		return (ftputchar(n + '0'));
	if (total != nlen(n))
		return (-1);
	return (total);
}

int	ftputuint(unsigned int n)
{
	int	total;

	total = 0;
	if (n > 9)
	{
		total += ftputnbr(n / 10);
		total += ftputnbr(n % 10);
	}
	else
		return (ftputchar(n + '0'));
	if (total != unlen(n))
		return (-1);
	return (total);
}
