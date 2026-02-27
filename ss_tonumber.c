/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::   ::::::::  */
/*    ss_tonumber.c                                    :+:    :+: :+:    :+:  */
/*                                                    +:+        +:+          */
/*    By: Ser Superior <marcioeduine@gmail.com>      +#++:++#++ +#++:++#++    */
/*                                                         +#+        +#+     */
/*    Created: 2026/02/27 21:32:05 by Ser Superior #+#    #+# #+#    #+#      */
/*    Updated: 2026/02/27 21:42:37 by Ser Superior ########   ########        */
/*                                                                            */
/* ************************************************************************** */

#include "ss_lib.h"

number	ss_tonumber(const text s)
{
	number	result;
	number	signal;
	number	i;

	result = 0;
	signal = 1;
	i = 0;
	if (not (s and s[i]))
		return (result);
	while (ss_isspace(s[i]))
		i++;
	if (s[i] == '-' or s[i] == '+')
		if (s[i++] == '-')
			signal = -1;
	while (s[i] and ss_isdigit(s[i]))
	{
		result = result * 10 + s[i++] - '0';
		if (ss_isnumber_limit(result))
			return (0);
	}
	return (result * signal);
}
