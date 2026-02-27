/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::   ::::::::  */
/*    ss_world_counter.c                               :+:    :+: :+:    :+:  */
/*                                                    +:+        +:+          */
/*    By: Ser Superior <marcioeduine@gmail.com>      +#++:++#++ +#++:++#++    */
/*                                                         +#+        +#+     */
/*    Created: 2026/02/27 18:47:27 by Ser Superior #+#    #+# #+#    #+#      */
/*    Updated: 2026/02/27 18:51:04 by Ser Superior ########   ########        */
/*                                                                            */
/* ************************************************************************** */
#include "ss_lib.h"

number	ss_world_counter(const text s)
{
	text	tmp;
	number	i;

	i = 0;
	if (not s)
		return (i);
	tmp = ss_strtrim(s, " \t");
	while (tmp[i])
		i += ss_isspace(tmp[i]);
	return (free(tmp), i);
}
