/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::   ::::::::  */
/*    ss_free_matrix.c                                 :+:    :+: :+:    :+:  */
/*                                                    +:+        +:+          */
/*    By: Ser Superior <marcioeduine@gmail.com>      +#++:++#++ +#++:++#++    */
/*                                                         +#+        +#+     */
/*    Created: 2026/02/27 17:51:05 by Ser Superior #+#    #+# #+#    #+#      */
/*    Updated: 2026/02/27 17:54:47 by Ser Superior ########   ########        */
/*                                                                            */
/* ************************************************************************** */
#include "ss_lib.h"

void	ss_free_matrix(matrix _matrix, number size)
{
	number	i;

	if (not _matrix)
		return ;
	i = -1;
	while (++i < size)
		if (_matrix[i])
			free(_matrix[i]);
	(free(_matrix), _matrix = NULL);
}
