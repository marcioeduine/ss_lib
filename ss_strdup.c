#include "ss_lib.h"

text	ss_strdup(const text s)
{
	text	new;
	number	i;

	if (!s)
		return (0);
	new = ss_calloc(1, ss_strlen(s) + 1);
	if (!new)
		return (0);
	i = -1;
	while (s[++i])
		new[i] = s[i];
	return (new);
}
