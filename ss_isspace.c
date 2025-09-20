#include "ss_lib.h"

bool	ss_isspace(number c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}
