#include "ss_lib.h"

generic	ss_memset(generic s, number c, number length)
{
	if (!s)
		return (0);
	while (length--)
		*(text)s++ = (char)c;
	return (s);
}
