#include "Sample.hpp"

int main(void)
{
	try
	{
		Sample	kick("kick");
		Sample	snare("snare");
		Sample	drum("drum");
		Sample	clap("clap");
		Sample	hat("hat");
		Sample	open_hat("open_hat");
		Sample	crash("crash");
		Sample	rim("rim");
		Sample	shaker("shaker");
		Sample	conga("conga");
		Sample	beat("beat");

		// Pitched Cowbells for Melody
		Sample	cb_c5("cowbell", 1.0f);
		Sample	cb_bb4("cowbell", 0.8909f);
		Sample	cb_g4("cowbell", 0.7492f);
		Sample	cb_f5("cowbell", 1.3348f);
		Sample	cb_e5("cowbell", 1.2598f);

		// Pitched Drums for Bassline
		Sample	bass_f2("drum", 0.9701f);
		Sample	bass_g2("drum", 1.0889f);
		Sample	bass_bb2("drum", 1.2949f);
		Sample	bass_c3("drum", 1.4534f);

		int		step_frames(11200);
		int		bar(0);
		int		step(0);
		int		start_frame(0);

		// First save all individual base samples (all types)
		kick.save();
		snare.save();
		drum.save();
		clap.save();
		hat.save();
		open_hat.save();
		crash.save();
		rim.save();
		shaker.save();
		conga.save();
		cb_c5.save(); // Saves cowbell.wav (base pitch 1.0f)

		// Loop through all 16 bars (0 to 15)
		for (bar = 0; bar < 16; ++bar)
		{
			// Loop through all 16 steps of each bar
			for (step = 0; step < 16; ++step)
			{
				start_frame = (bar * 16 + step) * step_frames;

				// --- 1. DRUMS PATH ---
				// Kick: play on beat downbeats (0, 4, 8, 12)
				// Active in Bars 0-7, 10-14, and first half of Bar 15
				if ((step % 4 == 0) &&
					((bar <= 7) || (bar >= 10 && bar <= 13) || (bar == 14) || (bar == 15 && step < 8)))
				{
					beat.mix(kick, start_frame);
				}

				// Snare: play on backbeats (4, 12)
				// Active in Bars 0-7, 10-14
				if ((step == 4 || step == 12) &&
					((bar <= 7) || (bar >= 10 && bar <= 13) || (bar == 14)))
				{
					beat.mix(snare, start_frame);
				}

				// Shaker: play on all odd steps (1, 3, 5, 7, 9, 11, 13, 15)
				// Active in all bars (0 to 15)
				if (step % 2 != 0)
				{
					beat.mix(shaker, start_frame);
				}

				// Hat: play on all even steps (0, 2, 4, 6, 8, 10, 12, 14)
				// Open Hat: play on step 14 instead of closed hat in Bars 4-7 and 10-13
				if (step % 2 == 0)
				{
					if (step == 14 && ((bar >= 4 && bar <= 7) || (bar >= 10 && bar <= 13)))
						beat.mix(open_hat, start_frame);
					else if (bar <= 14)
						beat.mix(hat, start_frame);
				}

				// Crash: play at the start of Bars 0, 4, 10
				if (step == 0 && (bar == 0 || bar == 4 || bar == 10))
				{
					beat.mix(crash, start_frame);
				}

				// --- 2. BASSLINE PATH ---
				// Plays in Bars 2-7, 10-13, and Bar 14
				if ((bar >= 2 && bar <= 7) || (bar >= 10 && bar <= 13) || (bar == 14))
				{
					if (step == 0)  beat.mix(bass_g2, start_frame);
					if (step == 2)  beat.mix(bass_g2, start_frame);
					if (step == 3)  beat.mix(bass_bb2, start_frame);
					if (step == 4)  beat.mix(bass_g2, start_frame);
					if (step == 6)  beat.mix(bass_f2, start_frame);
					if (step == 7)  beat.mix(bass_g2, start_frame);
					if (step == 8)  beat.mix(bass_c3, start_frame);
					if (step == 10) beat.mix(bass_c3, start_frame);
					if (step == 11) beat.mix(bass_bb2, start_frame);
					if (step == 12) beat.mix(bass_c3, start_frame);
					if (step == 14) beat.mix(bass_g2, start_frame);
					if (step == 15) beat.mix(bass_bb2, start_frame);
				}

				// --- 3. MELODY PATH (Cowbell) ---
				// Plays in Bars 4, 6, 10, 12 (every alternate bar of the main sections)
				if (bar == 4 || bar == 6 || bar == 10 || bar == 12)
				{
					if (step == 0)  beat.mix(cb_c5, start_frame);
					if (step == 1)  beat.mix(cb_c5, start_frame);
					if (step == 2)  beat.mix(cb_bb4, start_frame);
					if (step == 3)  beat.mix(cb_c5, start_frame);
					if (step == 5)  beat.mix(cb_g4, start_frame);
					if (step == 7)  beat.mix(cb_g4, start_frame);
					if (step == 8)  beat.mix(cb_c5, start_frame);
					if (step == 9)  beat.mix(cb_f5, start_frame);
					if (step == 10) beat.mix(cb_e5, start_frame);
					if (step == 11) beat.mix(cb_c5, start_frame);
				}

				// --- 4. BREAKDOWN PERCUSSION (Congas & Rims) ---
				// Active in Bars 8-9 (Breakdown) and Bar 15 (Outro)
				if (bar == 8 || bar == 9 || bar == 15)
				{
					if (step == 2 || step == 6 || step == 10 || step == 14)
						beat.mix(conga, start_frame);
					if (step == 3 || step == 7 || step == 11 || step == 15)
						beat.mix(rim, start_frame);
				}
			}
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
