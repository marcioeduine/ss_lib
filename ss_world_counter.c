#include "ss_lib.h"

number	ss_world_counter(const text s)
{
	number	i;
	text	tmp;

	i = 0;
	if (!s)
		return (i);
	tmp = ss_strtrim(s, " \t");
	while (tmp[i])
		i += ss_isspace(tmp[i]);
	return (free(tmp), i);
}
