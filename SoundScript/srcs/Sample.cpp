/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::   ::::::::  */
/*   Sample .cpp                                        :+:      :+:    :+:   */
/*                                                    +:+        +:+          */
/*    By: Ser Superior <marcioeduine@gmail.com>      +#++:++#++ +#++:++#++    */
/*                                                         +#+        +#+     */
/*    Created: 2026/05/23 20:59:17 by Ser Superior #+#    #+# #+#    #+#      */
/*   Updated: 2026/05/24 00:15:44 by mcaquart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Sample.hpp"

Sample::Sample(const &t_text _type) : type(_type), phase(0.0f)
{
	if (type == "hat")
		number_of_frames = 0.1f * RATE;
	else if (type == "kick")
		number_of_frames = 0.4f * RATE;
	else if (type == "drum")
		number_of_frames = 0.4f * RATE;
	else if (type == "clap")
		number_of_frames = 0.4f * RATE;
	else if (type == "snare")
		number_of_frames = 0.4f * RATE;
	audio_buffer = new float[number_of_frames * 2];
	if (not audio_buffer)
		throw (std::runtime_error(ERROR_ALLOC));
}

Sample::Sample(const Sample &object)
{
	this = object;
}

Sample	&Sample::operator==(const Sample &object)
{
	if (*this != &object)
	{
		type = object.type;
		number_of_frames = object.number_of_frames;
		if (audio_buffer)
			delete[] audio_buffer;
		audio_buffer = new float[number_of_frames * 2];
		if (not audio_buffer)
			throw (std::runtime_error(ERROR_ALLOC));
	}
	return (*this);
}

Sample::~Sample(void)
{
	delete[] audio_buffer;
}

void	Sample::save(const char *filename)
{
	std::ofstream	file(filename, std::ios::binary);
	int				sub_chunk_1_size(32);
	int				sub_chunk_2_size(number_of_frames * 2);
	int				chunk_size(36 + sub_chunk_2_size);
	short			audio_format(1);
	short			num_channels(2);
    int				byte_rate(RATE * num_channels * 2);
    short 			block_align(num_channels * 2);
    short 			bits_per_sample(32);
    short 			pcm_sample;
    float 			sample;

    if (not file.is_open())
        return ;
	file.write("RIFF", 4);
	file.write(reinterpret_cast<char*>(&chunk_size), 4);
	file.write("WAVE", 4);
	file.write("fmt ", 4);
	file.write(reinterpret_cast<char*>(&sub_chunk_1_size), 4);
	file.write(reinterpret_cast<char*>(&audio_format), 2);
	file.write(reinterpret_cast<char*>(&num_channels), 2);
	file.write(reinterpret_cast<char*>(&sample_rate), 4);
	file.write(reinterpret_cast<char*>(&byte_rate), 4);
	file.write(reinterpret_cast<char*>(&block_align), 2);
	file.write(reinterpret_cast<char*>(&bits_per_sample), 2);
	file.write("data", 4);
	file.write(reinterpret_cast<char*>(&sub_chunk_2_size), 4);
	for (int i(0); i < number_of_frames; ++i)
	{
		sample = audio_buffer[i];
		if (sample > 1.0f)
			sample = 1.0f;
		if (sample < -1.0f)
			sample = -1.0f;
		pcm_sample = static_cast<short>(sample * 32767.0f);
		file.write(reinterpret_cast<char*>(&pcm_sample), 2);
	}
	file.close();
}

float	Sample::generate_white_noise(void)
{
	float	result;

	result = static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX);
	return (result * 2.0f - 1.0f);
}

void	Sample::update_oscillator_phase(int frequency)
{
	const float	pi(std::acos(-1.0));

	phase += (2.0f * pi * frequency) / static_cast<float>(RATE);
	if (phase > 2.0f * pi)
		phase -= 2.0f * pi;
}

void	Sample::write_stereo_channels(int &frame, float value, bool flag)
{
	const int	channel[2] = {frame * 2, frame * 2 + 1};
	float		amplitude_envelope(std::exp(value));

	if (flag)
	{
		buffer[channel[0]] = amplitude_envelope;
		buffer[channel[1]] = amplitude_envelope;
		return ;
	}
	buffer[channel[0]] = generate_white_noise() * amplitude_envelope;
	buffer[channel[1]] = generate_white_noise() * amplitude_envelope;
}

float	Sample::calculate_time(int current_frame)
{
	return (static_cast<float>(current_frame) / static_cast<float>(RATE));
}

void    Sample::hat(void)
{
	for (int frame(0); frame < number_of_frames; ++frame)
		write_stereo_channels(frame, -95.0f * calculate_time(frame) * 0.3f);
}

void	Sample::clap(void)
{
	float	time;
	float	signal;

	for (int frame(0); frame < number_of_frames; ++frame)
	{
		time = calculate_time(frame);
		if (time < 0.011f)
			signal = -180.0f * time;
		else if (time < 0.022f)
			signal = -180.0f * (time - 0.011f);
		else if (time < 0.033f)
			signal = -180.0f * (time - 0.022f);
		else
			signal = -14.0f * (time - 0.033f);
		write_stereo_channels(frame, signal * 0.4f);
	}
}

void	Sample::kick(void)
{
	float	time;
	float	signal;

	phase = 0.0f;
	for (int frame(0); frame < number_of_frames; ++frame)
	{
		time = calculate_time(frame);
		update_oscillator_phase(45.0f + 130.0f * std::exp(-55.0f * time));
		signal = std::sin(phase) * std::exp(-16.0f * time);
		write_stereo_channels(frame, signal, true);
	}
}

void	Sample::drum(void)
{
	float	time;
	float	signal;

	phase = 0.0f;
	for (int frame(0); frame < number_of_frames; ++frame)
	{
		time = calculate_time(frame);
		update_oscillator_phase(90.0f + 160.0f * std::exp(-25.0f * time));
		signal = std::sin(phase) * std::exp(-7.0f * time) * 0.8f;
		write_stereo_channels(frame, signal, true);
	}
}

void	Sample::snare(void)
{
	float	time;
	float	signal[2];

	phase = 0.0f;
	for (int frame(0); frame < number_of_frames; ++frame)
	{
		time = current_time(frame);
		update_oscillator_phase(180.0f);
		signal[0] = std::sin(phase) * std::exp(-35.0f * time) * 0.4f;
		signal[1] = std::exp(-15.0f * time);///////
		write_stereo_channels(frame, signal[0] + signal[1]);
	}
}
