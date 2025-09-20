#include "ss_lib.h"

void	ss_putstr_fd(const text s, number fd)
{
	if (!s)
		write(fd, "(null)", 6);
	else
		write(fd, s, ss_strlen(s));
}
