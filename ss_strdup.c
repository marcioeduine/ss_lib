/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::   ::::::::  */
/*    ss_strdup.c                                      :+:    :+: :+:    :+:  */
/*                                                    +:+        +:+          */
/*    By: Ser Superior <marcioeduine@gmail.com>      +#++:++#++ +#++:++#++    */
/*                                                         +#+        +#+     */
/*    Created: 2026/02/27 18:19:57 by Ser Superior #+#    #+# #+#    #+#      */
/*    Updated: 2026/02/27 18:21:50 by Ser Superior ########   ########        */
/*                                                                            */
/* ************************************************************************** */
#include "ss_lib.h"

text	ss_strdup(const text s)
{
	text	new;
	number	i;

	if (not s)
		return (0);
	new = ss_calloc(ss_strlen(s) + 1, sizeof(char));
	if (not new)
		return (0);
	i = -1;
	while (s[++i])
		new[i] = s[i];
	return (new);
}
