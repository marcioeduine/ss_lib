#include "ss_lib.h"

number	ss_strlen(const text s)
{
	if (!s || !(*s))
		return (0);
	return (1 + ss_strlen(s + 1));
}
