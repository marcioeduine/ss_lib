#include "ss_lib.h"

void	ss_putnbr_fd(int _number, number fd)
{
	if (_number == -2147483648)
		return (ss_putstr_fd("-2147483648", fd));
	if (_number < 0)
		return (ss_putchar_fd('-', fd), ss_putnbr_fd(-_number, fd));
	if (_number > 9)
		ss_putnbr_fd(_number / 10, fd);
	ss_putchar_fd("0123456789"[_number % 10], fd);
}
