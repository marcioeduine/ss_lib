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

#include "Sample.hpp"

const float rate(RATE);

template <typename T>
void	write_binary(std::ostream &file, const T &value)
{
	file.write(reinterpret_cast<const char*>(&value), sizeof(T));
}

Sample::Sample(const std::string &_type, float _pitch_factor) : type(_type), phase(0.0f), audio_buffer(NULL), number_of_frames(0), pitch_factor(_pitch_factor)
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
	else if (type == "open_hat")
		number_of_frames = 0.6f * RATE;
	else if (type == "crash")
		number_of_frames = 1.5f * RATE;
	else if (type == "rim")
		number_of_frames = 0.05f * RATE;
	else if (type == "cowbell")
		number_of_frames = 0.3f * RATE;
	else if (type == "conga")
		number_of_frames = 0.25f * RATE;
	else if (type == "shaker")
		number_of_frames = 0.15f * RATE;
	else if (type.size() >= 6 && type.compare(0, 6, "piano_") == 0)
		number_of_frames = 1.0f * RATE;
	else if (type == "beat")
		number_of_frames = 64.0f * RATE;
	if (number_of_frames > 0)
	{
		audio_buffer = new float[number_of_frames * 2];
		if (not audio_buffer)
			throw (std::runtime_error(ERROR_ALLOC));
		std::fill(audio_buffer, audio_buffer + number_of_frames * 2, 0.0f);
		if (type == "hat")
			hat();
		else if (type == "kick")
			kick();
		else if (type == "drum")
			drum();
		else if (type == "clap")
			clap();
		else if (type == "snare")
			snare();
		else if (type == "open_hat")
			open_hat();
		else if (type == "crash")
			crash();
		else if (type == "rim")
			rim();
		else if (type == "cowbell")
			cowbell();
		else if (type == "conga")
			conga();
		else if (type == "shaker")
			shaker();
		else if (type.size() >= 6 && type.compare(0, 6, "piano_") == 0)
		{
			float frequency(261.63f);
			if (type == "piano_c4") frequency = 261.63f;
			else if (type == "piano_cs4") frequency = 277.18f;
			else if (type == "piano_d4") frequency = 293.66f;
			else if (type == "piano_ds4") frequency = 311.13f;
			else if (type == "piano_e4") frequency = 329.63f;
			else if (type == "piano_f4") frequency = 349.23f;
			else if (type == "piano_fs4") frequency = 369.99f;
			else if (type == "piano_g4") frequency = 392.00f;
			else if (type == "piano_gs4") frequency = 415.30f;
			else if (type == "piano_a4") frequency = 440.00f;
			else if (type == "piano_as4") frequency = 466.16f;
			else if (type == "piano_b4") frequency = 493.88f;
			else if (type == "piano_c5") frequency = 523.25f;
			piano(frequency);
		}
	}
}

Sample::Sample(const Sample &object) : audio_buffer(NULL)
{
	*this = object;
}

Sample	&Sample::operator=(const Sample &object)
{
	if (this != &object)
	{
		type = object.type;
		phase = object.phase;
		number_of_frames = object.number_of_frames;
		pitch_factor = object.pitch_factor;
		if (audio_buffer)
			delete[] audio_buffer;
		audio_buffer = NULL;
		if (number_of_frames > 0)
		{
			audio_buffer = new float[number_of_frames * 2];
			if (not audio_buffer)
				throw (std::runtime_error(ERROR_ALLOC));
			std::copy(object.audio_buffer, object.audio_buffer + number_of_frames * 2, audio_buffer);
		}
	}
	return (*this);
}

Sample::~Sample(void)
{
	delete[] audio_buffer;
}

void	Sample::save(void)
{
	std::ofstream	file(std::string(type + ".wav").c_str(), std::ios::binary);
	int				sub_chunk_1_size(16);
	int				sub_chunk_2_size(number_of_frames * 2 * 4);
	int				chunk_size(36 + sub_chunk_2_size);
	short			audio_format(1);
	short			num_channels(2);
	int				byte_rate(RATE * num_channels * 4);
	int				sample_rate(RATE);
	short 			block_align(num_channels * 4);
	short 			bits_per_sample(32);
	int 			pcm_sample;
	double 			sample;

	if (not file.is_open())
		return ;
	file.write("RIFF", 4);
	write_binary(file, chunk_size);
	file.write("WAVE", 4);
	file.write("fmt ", 4);
	write_binary(file, sub_chunk_1_size);
	write_binary(file, audio_format);
	write_binary(file, num_channels);
	write_binary(file, sample_rate);
	write_binary(file, byte_rate);
	write_binary(file, block_align);
	write_binary(file, bits_per_sample);
	file.write("data", 4);
	write_binary(file, sub_chunk_2_size);
	for (int i(0); i < number_of_frames * 2; ++i)
	{
		sample = audio_buffer[i];
		if (sample > 1.0f)
			sample = 1.0f;
		if (sample < -1.0f)
			sample = -1.0f;
		pcm_sample = sample * INT_MAX;
		write_binary(file, pcm_sample);
	}
	file.close();
}

float	Sample::generate_white_noise(void)
{
	double	max_rand(RAND_MAX);
	float	result(std::rand() / max_rand);

	return (result * 2.0f - 1.0f);
}

void	Sample::update_oscillator_phase(int frequency)
{
	const float	pi(3.1415926535f);

	phase += (2.0f * pi * frequency) / rate;
	if (phase > 2.0f * pi)
		phase -= 2.0f * pi;
}

void	Sample::write_stereo_channels(int &frame, float value, bool flag)
{
	const int	channel[2] = {frame * 2, frame * 2 + 1};
	float		amplitude_envelope;

	if (flag)
	{
		audio_buffer[channel[0]] = value;
		audio_buffer[channel[1]] = value;
		return ;
	}
	amplitude_envelope = std::exp(value);
	audio_buffer[channel[0]] = generate_white_noise() * amplitude_envelope;
	audio_buffer[channel[1]] = generate_white_noise() * amplitude_envelope;
}

float	Sample::calculate_time(int current_frame)
{
	return (current_frame / rate);
}

void    Sample::hat(void)
{
	float	time(0.0f);
	float	envelope(0.0f);
	float	prev_noise(0.0f);
	float	curr_noise(0.0f);
	float	hp_noise(0.0f);

	for (int frame(0); frame < number_of_frames; ++frame)
	{
		time = calculate_time(frame);
		envelope = std::exp(-95.0f * time) * 0.3f;
		curr_noise = generate_white_noise();
		hp_noise = curr_noise - 0.85f * prev_noise;
		prev_noise = curr_noise;
		write_stereo_channels(frame, hp_noise * envelope, true);
	}
}

void	Sample::clap(void)
{
	float	time;
	float	signal;
	float	envelope;

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
		envelope = std::exp(signal) * 0.4f;
		write_stereo_channels(frame, generate_white_noise() * envelope, true);
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
		update_oscillator_phase((90.0f + 160.0f * std::exp(-25.0f * time)) * pitch_factor);
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
		time = calculate_time(frame);
		update_oscillator_phase(180.0f);
		signal[0] = std::sin(phase) * std::exp(-35.0f * time) * 0.4f;
		signal[1] = std::exp(-15.0f * time);
		write_stereo_channels(frame, signal[0] + generate_white_noise() * signal[1], true);
	}
}

void	Sample::mix(const Sample &sample, int start_frame)
{
	float	*src(sample.get_audio_buffer());
	int		frames(sample.get_number_of_frames());
	int		out_idx;
	int		src_idx;

	for (int i(0); i < frames; ++i)
	{
		out_idx = (start_frame + i) * 2;
		src_idx = i * 2;
		if (out_idx + 1 < number_of_frames * 2)
		{
			audio_buffer[out_idx] += src[src_idx];
			audio_buffer[out_idx + 1] += src[src_idx + 1];
		}
	}
}

void	Sample::open_hat(void)
{
	float	time(0.0f);
	float	envelope(0.0f);
	float	prev_noise(0.0f);
	float	curr_noise(0.0f);
	float	hp_noise(0.0f);

	for (int frame(0); frame < number_of_frames; ++frame)
	{
		time = calculate_time(frame);
		envelope = std::exp(-9.0f * time) * 0.3f;
		curr_noise = generate_white_noise();
		hp_noise = curr_noise - 0.85f * prev_noise;
		prev_noise = curr_noise;
		write_stereo_channels(frame, hp_noise * envelope, true);
	}
}

void	Sample::crash(void)
{
	float	time(0.0f);
	float	envelope(0.0f);
	float	prev_noise(0.0f);
	float	curr_noise(0.0f);
	float	hp_noise(0.0f);

	for (int frame(0); frame < number_of_frames; ++frame)
	{
		time = calculate_time(frame);
		envelope = (std::exp(-2.0f * time) * 0.5f + std::exp(-150.0f * time) * 0.3f) * 0.6f;
		curr_noise = generate_white_noise();
		hp_noise = curr_noise - 0.85f * prev_noise;
		prev_noise = curr_noise;
		write_stereo_channels(frame, hp_noise * envelope, true);
	}
}

void	Sample::rim(void)
{
	float	time(0.0f);
	float	envelope(0.0f);
	float	click_envelope(0.0f);
	float	signal(0.0f);

	phase = 0.0f;
	for (int frame(0); frame < number_of_frames; ++frame)
	{
		time = calculate_time(frame);
		update_oscillator_phase(1200);
		envelope = std::exp(-150.0f * time) * 0.8f;
		click_envelope = std::exp(-400.0f * time) * 0.2f;
		signal = std::sin(phase) * envelope + generate_white_noise() * click_envelope;
		write_stereo_channels(frame, signal, true);
	}
}

void	Sample::cowbell(void)
{
	const float	pi(3.1415926535f);
	float		time(0.0f);
	float		sig1(0.0f);
	float		sig2(0.0f);
	float		signal(0.0f);
	float		envelope(0.0f);

	for (int frame(0); frame < number_of_frames; ++frame)
	{
		time = calculate_time(frame);
		sig1 = std::sin(2.0f * pi * 540.0f * pitch_factor * time) >= 0.0f ? 1.0f : -1.0f;
		sig2 = std::sin(2.0f * pi * 800.0f * pitch_factor * time) >= 0.0f ? 1.0f : -1.0f;
		envelope = std::exp(-15.0f * time) * 0.5f;
		signal = (0.5f * sig1 + 0.5f * sig2) * envelope;
		write_stereo_channels(frame, signal, true);
	}
}

void	Sample::conga(void)
{
	float	time(0.0f);
	float	freq(0.0f);
	float	signal(0.0f);
	float	envelope(0.0f);

	phase = 0.0f;
	for (int frame(0); frame < number_of_frames; ++frame)
	{
		time = calculate_time(frame);
		freq = (180.0f + 40.0f * std::exp(-25.0f * time)) * pitch_factor;
		update_oscillator_phase(freq);
		envelope = std::exp(-12.0f * time) * 0.6f;
		signal = std::sin(phase) * envelope;
		write_stereo_channels(frame, signal, true);
	}
}

void	Sample::shaker(void)
{
	float	time(0.0f);
	float	envelope(0.0f);
	float	prev_noise(0.0f);
	float	curr_noise(0.0f);
	float	hp_noise(0.0f);

	for (int frame(0); frame < number_of_frames; ++frame)
	{
		time = calculate_time(frame);
		if (time < 0.02f)
			envelope = (time / 0.02f) * 0.4f;
		else
			envelope = std::exp(-35.0f * (time - 0.02f)) * 0.4f;
		curr_noise = generate_white_noise();
		hp_noise = curr_noise - 0.85f * prev_noise;
		prev_noise = curr_noise;
		write_stereo_channels(frame, hp_noise * envelope, true);
	}
}

void	Sample::piano(float frequency)
{
	const float	pi(3.1415926535f);
	float		time(0.0f);
	float		signal(0.0f);
	float		attack(0.0f);
	float		envelope(0.0f);
	float		harmonic_amps[6] = {1.0f, 0.5f, 0.25f, 0.12f, 0.06f, 0.03f};
	float		harmonic_decays[6] = {1.5f, 3.0f, 4.5f, 6.0f, 7.5f, 9.0f};
	float		harmonic_sum(0.0f);
	float		mult(0.0f);
	float		phase_val(0.0f);
	float		harmonic_decay(0.0f);
	float		strike_noise(0.0f);
	int			h(0);

	for (int frame(0); frame < number_of_frames; ++frame)
	{
		time = calculate_time(frame);

		if (time < 0.005f)
			attack = time / 0.005f;
		else
			attack = 1.0f;

		envelope = std::exp(-1.5f * time) * attack;

		harmonic_sum = 0.0f;
		for (h = 0; h < 6; ++h)
		{
			mult = h + 1.0f;
			phase_val = 2.0f * pi * frequency * mult * time;
			harmonic_decay = std::exp(-harmonic_decays[h] * time);
			harmonic_sum += harmonic_amps[h] * std::sin(phase_val) * harmonic_decay;
		}

		strike_noise = 0.0f;
		if (time < 0.010f)
			strike_noise = generate_white_noise() * std::exp(-500.0f * time) * 0.15f;

		signal = (harmonic_sum * envelope * 0.4f) + strike_noise;
		write_stereo_channels(frame, signal, true);
	}
}

