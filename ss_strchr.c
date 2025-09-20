#include "ss_lib.h"

text	ss_strchr(const text s, number c)
{
	number	i;

	if (!s)
		return (0);
	i = -1;
	while (s[++i])
		if (s[i] == (char)c)
			return ((text)s + i);
	if (!c)
		return ((text)s);
	return (0);
}
