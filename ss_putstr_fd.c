/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::   ::::::::  */
/*    ss_putstr_fd.c                                   :+:    :+: :+:    :+:  */
/*                                                    +:+        +:+          */
/*    By: Ser Superior <marcioeduine@gmail.com>      +#++:++#++ +#++:++#++    */
/*                                                         +#+        +#+     */
/*    Created: 2026/02/27 18:13:25 by Ser Superior #+#    #+# #+#    #+#      */
/*    Updated: 2026/02/27 18:15:20 by Ser Superior ########   ########        */
/*                                                                            */
/* ************************************************************************** */
#include "ss_lib.h"

void	ss_putstr_fd(const text s, number fd)
{
	if (not s)
		write(fd, "(null)", 6);
	else
		write(fd, s, ss_strlen(s));
}
