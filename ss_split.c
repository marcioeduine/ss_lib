/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::   ::::::::  */
/*    ss_split.c                                       :+:    :+: :+:    :+:  */
/*                                                    +:+        +:+          */
/*    By: Ser Superior <marcioeduine@gmail.com>      +#++:++#++ +#++:++#++    */
/*                                                         +#+        +#+     */
/*    Created: 2026/02/27 18:15:29 by Ser Superior #+#    #+# #+#    #+#      */
/*    Updated: 2026/02/27 18:19:05 by Ser Superior ########   ########        */
/*                                                                            */
/* ************************************************************************** */
#include "ss_lib.h"

static number	ss_skip_delimiter(const text s, const text charset)
{
	number	i;

	i = 0;
	while (s[i] and ss_strchr(charset, s[i]))
		i++;
	return (i);
}

matrix	ss_split(const text s, const text charset)
{
	matrix	_matrix;
	number	counter;
	number	i;
	number	y;

	if (not s)
		return (NULL);
	counter = ss_world_counter(s);
	_matrix = ss_calloc(counter + 1, sizeof(text));
	if (not _matrix)
		return (_matrix);
	i = -1;
	y = i;
	while (s[++i] and (++y < counter))
	{
		_matrix[y] = ss_calloc(ss_strlen(s) + 1, sizeof(char));
		if (not _matrix[y])
			return (ss_free_matrix(_matrix, counter), NULL);
		i += ss_skip_delimiter(s + i, charset);
		while (s[i] and not ss_strchr(charset, s[i]))
			*_matrix[y]++ = s[i++];
	}
	return (_matrix);
}
