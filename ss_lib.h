/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::   ::::::::  */
/*    ss_lib.h                                         :+:    :+: :+:    :+:  */
/*                                                    +:+        +:+          */
/*    By: Ser Superior <marcioeduine@gmail.com>      +#++:++#++ +#++:++#++    */
/*                                                         +#+        +#+     */
/*    Created: 2026/02/27 18:03:34 by Ser Superior #+#    #+# #+#    #+#      */
/*    Updated: 2026/02/27 21:54:08 by Ser Superior ########   ########        */
/*                                                                            */
/* ************************************************************************** */
#ifndef SS_LIB_H
# define SS_LIB_H

# include <iso646.h>
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef char *		text;
typedef char **		matrix;
typedef long long	number;
typedef void *		generic;
typedef struct s_list
{
	generic			content;
	number			size;
	struct s_list	*next;
}					t_list;

number	ss_tonumber(const text s);
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
bool	ss_isnumber_limit(double n);

void	ss_putchar_fd(char c, number fd);
void	ss_putstr_fd(const text s, number fd);
void	ss_putendl_fd(const text s, number fd);
void	ss_putnbr_fd(int _number, number fd);
void	ss_free_matrix(matrix _matrix, number size);
void	ss_swap(generic a, generic b);

generic	ss_memset(generic s, number c, number length);
generic	ss_calloc(number member, number size);

text	ss_strchr(const text s, number c);
text	ss_strrchr(const text s, number c);
text	ss_strdup(const text s);
text	ss_substr(const text s, number start, number length);
text	ss_strtrim(const text s, const text charset);
text	ss_strljoin(const text dest, const text src, number length);
text	ss_totext(number n);

matrix	ss_split(const text s, const text charset);

#endif
