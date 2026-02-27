/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::   ::::::::  */
/*    ss_strrchr.c                                     :+:    :+: :+:    :+:  */
/*                                                    +:+        +:+          */
/*    By: Ser Superior <marcioeduine@gmail.com>      +#++:++#++ +#++:++#++    */
/*                                                         +#+        +#+     */
/*    Created: 2026/02/27 18:25:07 by Ser Superior #+#    #+# #+#    #+#      */
/*    Updated: 2026/02/27 18:27:35 by Ser Superior ########   ########        */
/*                                                                            */
/* ************************************************************************** */
#include "ss_lib.h"

text	ss_strrchr(const text s, number c)
{
	number	i;

	if (not s)
		return (0);
	i = ss_strlen(s) + 1;
	while (s[--i])
		if (s[i] == (char)c)
			return ((text)s + i);
	return (0);
}
