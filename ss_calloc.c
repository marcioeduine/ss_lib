#include "ss_lib.h"

generic	ss_calloc(number member, number size)
{
	generic	result;

	result = malloc(member * size);
	if (result)
		ss_memset(result, 0, member * size);
	return (result);
}
