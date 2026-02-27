/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::   ::::::::  */
/*    ss_putnbr_fd.c                                   :+:    :+: :+:    :+:  */
/*                                                    +:+        +:+          */
/*    By: Ser Superior <marcioeduine@gmail.com>      +#++:++#++ +#++:++#++    */
/*                                                         +#+        +#+     */
/*    Created: 2026/02/27 18:10:13 by Ser Superior #+#    #+# #+#    #+#      */
/*    Updated: 2026/02/27 18:10:13 by Ser Superior ########   ########        */
/*                                                                            */
/* ************************************************************************** */
#include "ss_lib.h"

void	ss_putnbr_fd(int _number, number fd)
{
	if (_number == INT_MIN)
		return (ss_putstr_fd(ss_totext(INT_MIN), fd));
	if (_number < 0)
		return (ss_putchar_fd('-', fd), ss_putnbr_fd(-_number, fd));
	if (_number > 9)
		ss_putnbr_fd(_number / 10, fd);
	ss_putchar_fd(_number % 10 - '0', fd);
}
