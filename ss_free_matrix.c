#include "ss_lib.h"

void	ss_free_matrix(matrix _matrix, number size)
{
	number	i;

	if (!_matrix)
		return ;
	i = -1;
	while (++i < size)
		if (_matrix[i])
			free(_matrix[i]);
	free(_matrix);
	_matrix = NULL;
}
