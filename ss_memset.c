/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::   ::::::::  */
/*    ss_memset.c                                      :+:    :+: :+:    :+:  */
/*                                                    +:+        +:+          */
/*    By: Ser Superior <marcioeduine@gmail.com>      +#++:++#++ +#++:++#++    */
/*                                                         +#+        +#+     */
/*    Created: 2026/02/27 18:03:14 by Ser Superior #+#    #+# #+#    #+#      */
/*    Updated: 2026/02/27 18:06:28 by Ser Superior ########   ########        */
/*                                                                            */
/* ************************************************************************** */
#include "ss_lib.h"

generic	ss_memset(generic s, number c, number length)
{
	if (not s)
		return (0);
	while (length--)
		*(text)s++ = (char)c;
	return (s);
}
