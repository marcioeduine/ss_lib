/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::   ::::::::  */
/*    main.c                                           :+:    :+: :+:    :+:  */
/*                                                    +:+        +:+          */
/*    By: Ser Superior <marcioeduine@gmail.com>      +#++:++#++ +#++:++#++    */
/*                                                         +#+        +#+     */
/*    Created: 2026/02/27 21:25:57 by Ser Superior #+#    #+# #+#    #+#      */
/*    Updated: 2026/02/27 22:11:37 by Ser Superior ########   ########        */
/*                                                                            */
/* ************************************************************************** */

#include "ss_lib.h"

int	main(int ac, char **av)
{
	text	a = av[1];
	text	b = av[2];
	number	c = ss_tonumber(av[1]);
	number	d = ss_tonumber(av[2]);

	if (ac == 1)
		return (1);
	ss_swap(a, b);
	ss_swap(c, d);
	ss_putendl_fd(a, 1);
	ss_putendl_fd(b, 1);
	ss_putnbr_fd(c, 1);
	ss_putchar_fd('\n', 1);
	ss_putnbr_fd(d, 1);
	return (0);
}
