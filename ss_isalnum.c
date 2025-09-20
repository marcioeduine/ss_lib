#include "ss_lib.h"

bool	ss_isalnum(number c)
{
	return (ss_isalpha(c) || ss_isdigit(c));
}
