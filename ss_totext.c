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
	if (n < 0)
		(i++, n = -n);
	while ((++i, n))
		n /= 10;
	return (i);
}

text	ss_totext(number n)
{
	text	s;
	number	i;

	if (not n)
		return (ss_strdup("0"));
	if (n == LLONG_MIN)
		return (ss_strdup("-9223372036854775807"));
	i = ss_number_length(n);
	s = ss_calloc(i + 1, sizeof(char));
	if (not s)
		return (s);
	if (n < 0)
	{
		s[0] = '-';
		n = -n;
	}
	while (n)
	{
		s[--i] = n % 10 + '0';
		n /= 10;
	}
	return (s);
}
