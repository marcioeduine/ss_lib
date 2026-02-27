/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::   ::::::::  */
/*    ss_calloc.c                                      :+:    :+: :+:    :+:  */
/*                                                    +:+        +:+          */
/*    By: Ser Superior <marcioeduine@gmail.com>      +#++:++#++ +#++:++#++    */
/*                                                         +#+        +#+     */
/*    Created: 2026/02/27 17:41:45 by Ser Superior #+#    #+# #+#    #+#      */
/*    Updated: 2026/02/27 17:55:37 by Ser Superior ########   ########        */
/*                                                                            */
/* ************************************************************************** */
#include "ss_lib.h"

generic	ss_calloc(number member, number size)
{
	generic	result;

	result = malloc(member * size);
	if (result)
		ss_memset(result, 0, member * size);
	return (result);
}
