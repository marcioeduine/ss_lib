/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::   ::::::::  */
/*    ss_substr.c                                      :+:    :+: :+:    :+:  */
/*                                                    +:+        +:+          */
/*    By: Ser Superior <marcioeduine@gmail.com>      +#++:++#++ +#++:++#++    */
/*                                                         +#+        +#+     */
/*    Created: 2026/02/27 18:34:16 by Ser Superior #+#    #+# #+#    #+#      */
/*    Updated: 2026/02/27 18:47:21 by Ser Superior ########   ########        */
/*                                                                            */
/* ************************************************************************** */
#include "ss_lib.h"

text	ss_substr(const text s, number start, number length)
{
	const number	str_length = ss_strlen(s);
	text			new;

	if (not str_length or start >= str_length)
		return (0);
	if (start + length > str_length)
		length = str_length - start;
	return (new = NULL, new = ss_strljoin(new, s + start, length));
}
