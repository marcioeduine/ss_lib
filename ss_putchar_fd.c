#include "ss_lib.h"

void	ss_putchar_fd(char c, number fd)
{
	write(fd, &c, 1);
}
