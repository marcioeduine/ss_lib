#ifndef SS_LIB_H
# define SS_LIB_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

typedef char * text;
typedef char ** matrix;
typedef size_t number;
typedef void * generic;
typedef struct s_list
{
	generic			content;
	number			size;
	struct s_list	*next;
}					t_list;

number	ss_strlen(const text s);
number	ss_world_counter(const text s);

bool	ss_isascii(int c);
bool	ss_isalpha(number c);
bool	ss_isdigit(number c);
bool	ss_isalnum(number c);
bool	ss_isprint(number c);
bool	ss_islower(number c);
bool	ss_isupper(number c);
bool	ss_isspace(number c);

void	ss_putchar_fd(char c, number fd);
void	ss_putstr_fd(const text s, number fd);
void	ss_putendl_fd(const text s, number fd);
void	ss_putnbr_fd(int _number, number fd);
void	ss_free_matrix(matrix _matrix, number size);

generic	ss_memset(generic s, number c, number length);
generic	ss_calloc(number member, number size);

text	ss_strchr(const text s, number c);
text	ss_strrchr(const text s, number c);
text	ss_strdup(const text s);
text	ss_substr(const text s, number start, number length);
text	ss_strtrim(const text s, const text charset);

matrix	ss_split(const text s, const text charset);

#endif
