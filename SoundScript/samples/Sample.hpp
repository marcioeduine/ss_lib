/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::   ::::::::  */
/*   Sample.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+        +:+          */
/*    By: Ser Superior <marcioeduine@gmail.com>      +#++:++#++ +#++:++#++    */
/*                                                         +#+        +#+     */
/*    Created: 2026/05/23 23:39:09 by Ser Superior #+#    #+# #+#    #+#      */
/*   Updated: 2026/05/24 00:33:21 by mcaquart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE_HPP
# define SAMPLE_HPP

# define ERROR_ALLOC "Bad Audio Buffer allocation!"
# define RATE 44800

# include <cmath>
# include <cstdlib>
# include <fstream>
# include <iostream>

class	Sample
{
	private:
		std::string	type;
		float		phase;
		float		*audio_buffer;
		int			number_of_frames;

		float		generate_white_noise(void);
		float		calculate_time(int current_frame);
		void		update_oscillator_phase(int frequency);
		void		write_stereo_channels(int &frame, float value, bool flag = false);
		Sample(void);
	public:
		Sample(const std::string &_type);
		Sample(const Sample &object);
		Sample	&operator=(const Sample &object);
		~Sample(void);
		void	hat(void);
		void	kick(void);
		void	drum(void);
		void	snare(void);
		void	clap(void);
		void	save(void);
};

#endif
