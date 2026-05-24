/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::   ::::::::  */
/*   SoundScript.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+        +:+          */
/*    By: Ser Superior <marcioeduine@gmail.com>      +#++:++#++ +#++:++#++    */
/*                                                         +#+        +#+     */
/*    Created: 2026/05/23 17:24:31 by Ser Superior #+#    #+# #+#    #+#      */
/*   Updated: 2026/05/23 17:37:54 by mcaquart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOUND_SCRIPT_HPP
# define SOUND_SCRIPT_HPP

# include <cstdlib>
# include "miniaudio.h"

typedef std::string t_text;

void	ss_error(const &t_text, int fd = 1);

#endif
