#include "ss_lib.h"

text	ss_strrchr(const text s, number c)
{
	number	i;

	if (!s)
		return (0);
	i = ss_strlen(s) + 1;
	while (--i != (number)-1)
		if (s[i] == (char)c)
			return ((text)s + i);
	return (0);
}
