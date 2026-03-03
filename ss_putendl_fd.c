/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::   ::::::::  */
/*    ss_putendl_fd.c                                  :+:    :+: :+:    :+:  */
/*                                                    +:+        +:+          */
/*    By: Ser Superior <marcioeduine@gmail.com>      +#++:++#++ +#++:++#++    */
/*                                                         +#+        +#+     */
/*    Created: 2026/02/27 18:07:52 by Ser Superior #+#    #+# #+#    #+#      */
/*    Updated: 2026/02/27 18:08:02 by Ser Superior ########   ########        */
/*                                                                            */
/* ************************************************************************** */
#include "ss_lib.h"

void	ss_putendl_fd(const text s, number fd)
{
	ss_putstr_fd(s, fd);
	ss_putchar_fd('\n', fd);
}
