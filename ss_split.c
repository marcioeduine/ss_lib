#include "ss_lib.h"

static number	ss_skip_delimiter(const text s, const text charset)
{
	number	i;

	i = 0;
	while (s[i] && ss_strchr(charset, s[i]))
		i++;
	return (i);
}

matrix	ss_split(const text s, const text charset)
{
	matrix	_matrix;
	number	counter;
	number	i;
	number	y;

	if (!s)
		return (NULL);
	counter = ss_world_counter(s);
	_matrix = ss_calloc(counter + 1, sizeof(text));
	if (!_matrix)
		return (NULL);
	i = -1;
	y = i;
	while (s[++i] && (++y < counter))
	{
		_matrix[y] = ss_calloc(1, ss_strlen(s) + 1);
		if (!_matrix[y])
			return (ss_free_matrix(_matrix, counter), NULL);
		i += ss_skip_delimiter(s + i, charset);
		while (s[i] && !ss_strchr(charset, s[i]))
			*_matrix[y]++ = s[i++];
	}
	return (_matrix);
}
