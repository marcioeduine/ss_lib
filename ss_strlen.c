/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::   ::::::::  */
/*    ss_strlen.c                                      :+:    :+: :+:    :+:  */
/*                                                    +:+        +:+          */
/*    By: Ser Superior <marcioeduine@gmail.com>      +#++:++#++ +#++:++#++    */
/*                                                         +#+        +#+     */
/*    Created: 2026/02/27 18:21:56 by Ser Superior #+#    #+# #+#    #+#      */
/*    Updated: 2026/02/27 18:25:01 by Ser Superior ########   ########        */
/*                                                                            */
/* ************************************************************************** */
#include "ss_lib.h"

number	ss_strlen(const text s)
{
	int	i;

	i = 0;
	if (not (*s and s))
		return (i);
	while (s + i)
		i++;
	return (i);
}
