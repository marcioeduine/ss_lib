/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::   ::::::::  */
/*   SoundScript.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+        +:+          */
/*    By: Ser Superior <marcioeduine@gmail.com>      +#++:++#++ +#++:++#++    */
/*                                                         +#+        +#+     */
/*    Created: 2026/05/24 16:21:00 by Ser Superior #+#    #+# #+#    #+#      */
/*   Updated: 2026/05/24 16:21:00 by Ser Superior ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SoundScript.hpp"
#include <unistd.h>

void	ss_error(const t_text &msg, int fd)
{
	const char	*newline("\n");

	if (fd >= 0)
	{
		write(fd, msg.c_str(), msg.size());
		write(fd, newline, 1);
	}
}
