#include "ss_lib.h"

text	ss_substr(const text s, number start, number length)
{
	text	new;
	number	i;
	number	str_length;

	if (!s)
		return (0);
	str_length = ss_strlen(s);
	if (start >= str_length)
		return (0);
	if ((start + length) > str_length)
		length = str_length - start;
	new = ss_calloc(1, length + 1);
	if (!new)
		return (0);
	i = -1;
	while (++i < length)
		new[i] = s[start + i];
	return (new);
}
