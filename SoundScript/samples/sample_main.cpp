#include "Sample.hpp"

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
		Sample beat("beat");

		snare.save();
		kick.save();
		drum.save();
		clap.save();
		hat.save();

		// Sequence the "We Will Rock You" beat
		int step_frames(11200); // 0.25 seconds per step
		int bar;
		int start_frame;

		for (bar = 0; bar < 4; ++bar)
		{
			// Step 0: Kick
			start_frame = bar * 4 * step_frames + 0 * step_frames;
			beat.mix(kick, start_frame);

			// Step 1: Kick
			start_frame = bar * 4 * step_frames + 1 * step_frames;
			beat.mix(kick, start_frame);

			// Step 2: Clap
			start_frame = bar * 4 * step_frames + 2 * step_frames;
			beat.mix(clap, start_frame);

			// Step 3: Silence
		}

		beat.save();
	}
	catch (const std::exception &e)
	{
		std::cerr << "[ SAMPLE ERROR ] " << e.what() << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
