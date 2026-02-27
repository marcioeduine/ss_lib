/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::   ::::::::  */
/*    ss_strljoin.c                                    :+:    :+: :+:    :+:  */
/*                                                    +:+        +:+          */
/*    By: Ser Superior <marcioeduine@gmail.com>      +#++:++#++ +#++:++#++    */
/*                                                         +#+        +#+     */
/*    Created: 2026/02/27 18:55:10 by Ser Superior #+#    #+# #+#    #+#      */
/*    Updated: 2026/02/27 19:13:55 by Ser Superior ########   ########        */
/*                                                                            */
/* ************************************************************************** */

#include "ss_lib.h"

text	ss_strljoin(const text dest, const text src, number length)
{
	const number	src_length = ss_strlen(src);
	number			i;
	number			j;
	text			result;

	if (not (src_length and length))
		return (0);
	result = ss_calloc(ss_strlen(dest) + src_length + 1, sizeof(char));
	if (not result)
		return (result);
	if (length > src_length)
		length = src_length;
	result = ss_strdup(dest);
	if (not result)
		return (result);
	i = ss_strlen(result);
	j = 0;
	while (i < length)
		result[i++] = src[j++];
	return (result);
}
