/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::   ::::::::  */
/*    ss_totext.c                                      :+:    :+: :+:    :+:  */
/*                                                    +:+        +:+          */
/*    By: Ser Superior <marcioeduine@gmail.com>      +#++:++#++ +#++:++#++    */
/*                                                         +#+        +#+     */
/*    Created: 2026/02/27 19:15:11 by Ser Superior #+#    #+# #+#    #+#      */
/*    Updated: 2026/02/27 21:56:08 by Ser Superior ########   ########        */
/*                                                                            */
/* ************************************************************************** */

#include "ss_lib.h"

static number	ss_number_length(number n)
{
	number	i;

	if (not n)
		return (1);
	i = -1;
	while ((++i, n or n < 0))
		n /= 10;
	return (0);
}

text	ss_totext(number n)
{
	text	s;
	number	length;
	number	tmp;

	if (ss_isnumber_limit(n))
		return (0);
	tmp = n;
	length = ss_number_length(n) - 1;
	while ((length++, n < 0))
		tmp = -tmp;
	s = ss_calloc(length + 1, sizeof(char));
	if (not s)
		return (s);
	while (tmp)
	{
		s[--length] = tmp % 10 + '0';
		tmp /= 10;
	}
	if (n < 0)
		s[0] = '-';
	if (not n)
		s[0] = '0';
	return (s);
}
