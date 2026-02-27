/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::   ::::::::  */
/*    ss_strchr.c                                      :+:    :+: :+:    :+:  */
/*                                                    +:+        +:+          */
/*    By: Ser Superior <marcioeduine@gmail.com>      +#++:++#++ +#++:++#++    */
/*                                                         +#+        +#+     */
/*    Created: 2026/02/27 18:19:12 by Ser Superior #+#    #+# #+#    #+#      */
/*    Updated: 2026/02/27 18:29:38 by Ser Superior ########   ########        */
/*                                                                            */
/* ************************************************************************** */
#include "ss_lib.h"

text	ss_strchr(const text s, number c)
{
	number	i;

	if (not s)
		return (0);
	i = -1;
	while (s[++i])
		if (s[i] == (char)c)
			return ((text)s + i);
	if (not c)
		return ((text)s);
	return (0);
}
