/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::   ::::::::  */
/*    ss_strtrim.c                                     :+:    :+: :+:    :+:  */
/*                                                    +:+        +:+          */
/*    By: Ser Superior <marcioeduine@gmail.com>      +#++:++#++ +#++:++#++    */
/*                                                         +#+        +#+     */
/*    Created: 2026/02/27 18:27:42 by Ser Superior #+#    #+# #+#    #+#      */
/*    Updated: 2026/02/27 18:34:10 by Ser Superior ########   ########        */
/*                                                                            */
/* ************************************************************************** */
#include "ss_lib.h"

text	ss_strtrim(const text s, const text charset)
{
	number	start;
	number	end;

	if (not (s and charset))
		return (0);
	start = 0;
	end = ss_strlen(s);
	while (ss_strchr(charset, s[start]))
		start++;
	while (ss_strchr(charset, s[end]))
		end--;
	return (ss_substr(s, start, end - start + 1));
}
