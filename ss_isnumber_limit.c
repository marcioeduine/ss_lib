/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::   ::::::::  */
/*    ss_isnumber_limit.c                              :+:    :+: :+:    :+:  */
/*                                                    +:+        +:+          */
/*    By: Ser Superior <marcioeduine@gmail.com>      +#++:++#++ +#++:++#++    */
/*                                                         +#+        +#+     */
/*    Created: 2026/02/27 21:43:50 by Ser Superior #+#    #+# #+#    #+#      */
/*    Updated: 2026/02/27 21:50:49 by Ser Superior ########   ########        */
/*                                                                            */
/* ************************************************************************** */

#include "ss_lib.h"

bool	ss_isnumber_limit(double n)
{
	return (n < (double)LLONG_MIN or n > (double)LLONG_MAX);
}
