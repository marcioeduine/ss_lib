#include "ss_lib.h"

void	ss_putendl_fd(const text s, number fd)
{
	ss_putstr_fd(s, fd);
	ss_putchar_fd('\n', fd);
}
