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

int	main(int ac, matrix av)
{
	text	s = ss_calloc(ss_strlen(av[1]), sizeof(char));
	number	n = ss_atoi(av[1]);

	if (ac < 2)
		return (1);
	ss_putnbr_fd(n, 1);
	ss_putendl_fd(NULL, 1);
	ss_putendl_fd(ss_itoa(n), 1);
	if (ss_isnumber_limit(n))
		return (55);
	ss_putstr_fd(s, 1);
	return (0);
}
