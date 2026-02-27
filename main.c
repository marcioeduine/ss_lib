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
	number	n;

	if (ac < 2)
		return (1);
	n = ss_tonumber(av[1]);
	if (ss_isnumber_limit(n))
		return (55);
	return (0);
}
