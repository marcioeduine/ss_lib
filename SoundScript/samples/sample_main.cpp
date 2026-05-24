#include "Sample.hpp"
#include <fstream>
#include <climits>

template <typename T>
void write_binary(std::ostream &file, const T &value)
{
	file.write(reinterpret_cast<const char*>(&value), sizeof(T));
}

void mix_sample(float *output_buffer, int total_frames, const Sample &sample, int start_frame)
{
	float *src(sample.get_audio_buffer());
	int frames(sample.get_number_of_frames());
	int i;
	int out_idx;
	int src_idx;

	for (i = 0; i < frames; ++i)
	{
		out_idx = (start_frame + i) * 2;
		src_idx = i * 2;
		if (out_idx + 1 < total_frames * 2)
		{
			output_buffer[out_idx] += src[src_idx];
			output_buffer[out_idx + 1] += src[src_idx + 1];
		}
	}
}

void save_wav(const std::string &filename, float *buffer, int total_frames)
{
	std::ofstream	file(filename.c_str(), std::ios::binary);
	int				sub_chunk_1_size(16);
	int				sub_chunk_2_size(total_frames * 2 * 4);
	int				chunk_size(36 + sub_chunk_2_size);
	short			audio_format(1);
	short			num_channels(2);
	int				byte_rate(RATE * num_channels * 4);
	int				sample_rate(RATE);
	short 			block_align(num_channels * 4);
	short 			bits_per_sample(32);
	int 			pcm_sample;
	double 			sample;
	int				i;

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

	for (i = 0; i < total_frames * 2; ++i)
	{
		sample = buffer[i];
		if (sample > 1.0f)
			sample = 1.0f;
		if (sample < -1.0f)
			sample = -1.0f;
		pcm_sample = sample * INT_MAX;
		write_binary(file, pcm_sample);
	}
	file.close();
}

int main(void)
{
	try
	{
		// Generate and save individual sounds
		Sample snare("snare");
		Sample kick("kick");
		Sample drum("drum");
		Sample clap("clap");
		Sample hat("hat");

		snare.save();
		kick.save();
		drum.save();
		clap.save();
		hat.save();

		// Sequence a "We Will Rock You" beat
		// 4 seconds duration = 44800 * 4 = 179200 frames
		int total_frames(179200);
		float *output_buffer(new float[total_frames * 2]);
		int step_frames(11200); // 0.25 seconds per step
		int bar;
		int start_frame;

		std::fill(output_buffer, output_buffer + total_frames * 2, 0.0f);

		for (bar = 0; bar < 4; ++bar)
		{
			// Step 0: Kick
			start_frame = bar * 4 * step_frames + 0 * step_frames;
			mix_sample(output_buffer, total_frames, kick, start_frame);

			// Step 1: Kick
			start_frame = bar * 4 * step_frames + 1 * step_frames;
			mix_sample(output_buffer, total_frames, kick, start_frame);

			// Step 2: Clap
			start_frame = bar * 4 * step_frames + 2 * step_frames;
			mix_sample(output_buffer, total_frames, clap, start_frame);

			// Step 3: Silence
		}

		save_wav("beat.wav", output_buffer, total_frames);
		delete[] output_buffer;
	}
	catch (const std::exception &e)
	{
		std::cerr << "[ SAMPLE ERROR ] " << e.what() << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
