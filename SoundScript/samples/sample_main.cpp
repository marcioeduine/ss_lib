#include "../includes/Sample.hpp"

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
		Sample	rap_drill("rap_drill");

		// Pitched Cowbells for Melody
		Sample	cb_c5("cowbell", 1.0f);
		Sample	cb_bb4("cowbell", 0.8909f);
		Sample	cb_g4("cowbell", 0.7492f);
		Sample	cb_f5("cowbell", 1.3348f);
		Sample	cb_e5("cowbell", 1.2598f);

		// Pitched Drums for Bassline
		Sample	bass_c2("drum", 0.7268f);
		Sample	bass_f2("drum", 0.9701f);
		Sample	bass_ds2("drum", 0.8158f);
		Sample	bass_g2("drum", 1.0889f);
		Sample	bass_gs2("drum", 1.1537f);
		Sample	bass_bb2("drum", 1.2949f);
		Sample	bass_c3("drum", 1.4534f);

		// Chromatic Piano Notes
		Sample	piano_c4("piano_c4");
		Sample	piano_cs4("piano_cs4");
		Sample	piano_d4("piano_d4");
		Sample	piano_ds4("piano_ds4");
		Sample	piano_e4("piano_e4");
		Sample	piano_f4("piano_f4");
		Sample	piano_fs4("piano_fs4");
		Sample	piano_g4("piano_g4");
		Sample	piano_gs4("piano_gs4");
		Sample	piano_a4("piano_a4");
		Sample	piano_as4("piano_as4");
		Sample	piano_b4("piano_b4");
		Sample	piano_c5("piano_c5");

		int		step_frames(11200);
		int		bar(0);
		int		step(0);
		int		start_frame(0);
		int		step_in_loop(0);
		int		melody_bar(0);
		Sample	*note(NULL);
		Sample	*bass_note(NULL);

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

		// Save piano notes
		piano_c4.save();
		piano_cs4.save();
		piano_d4.save();
		piano_ds4.save();
		piano_e4.save();
		piano_f4.save();
		piano_fs4.save();
		piano_g4.save();
		piano_gs4.save();
		piano_a4.save();
		piano_as4.save();
		piano_b4.save();
		piano_c5.save();

		// Loop through all 16 bars (0 to 15)
		for (bar = 0; bar < 16; ++bar)
		{
			// Loop through all 16 steps of each bar
			for (step = 0; step < 16; ++step)
			{
				step_in_loop = (bar % 8) * 16 + step;
				note = NULL;

				start_frame = (bar * 16 + step) * step_frames;

				// --- 1. JINGLE BELLS MELODY (Piano) ---
				if (step_in_loop == 0)   note = &piano_e4;
				else if (step_in_loop == 2)   note = &piano_e4;
				else if (step_in_loop == 4)   note = &piano_e4;
				else if (step_in_loop == 8)   note = &piano_e4;
				else if (step_in_loop == 10)  note = &piano_e4;
				else if (step_in_loop == 12)  note = &piano_e4;
				else if (step_in_loop == 16)  note = &piano_e4;
				else if (step_in_loop == 18)  note = &piano_g4;
				else if (step_in_loop == 20)  note = &piano_c4;
				else if (step_in_loop == 22)  note = &piano_d4;
				else if (step_in_loop == 24)  note = &piano_e4;
				else if (step_in_loop == 32)  note = &piano_f4;
				else if (step_in_loop == 34)  note = &piano_f4;
				else if (step_in_loop == 36)  note = &piano_f4;
				else if (step_in_loop == 38)  note = &piano_f4;
				else if (step_in_loop == 40)  note = &piano_f4;
				else if (step_in_loop == 42)  note = &piano_e4;
				else if (step_in_loop == 44)  note = &piano_e4;
				else if (step_in_loop == 46)  note = &piano_e4;
				else if (step_in_loop == 48)  note = &piano_e4;
				else if (step_in_loop == 50)  note = &piano_d4;
				else if (step_in_loop == 52)  note = &piano_d4;
				else if (step_in_loop == 54)  note = &piano_e4;
				else if (step_in_loop == 56)  note = &piano_d4;
				else if (step_in_loop == 60)  note = &piano_g4;
				else if (step_in_loop == 64)  note = &piano_e4;
				else if (step_in_loop == 66)  note = &piano_e4;
				else if (step_in_loop == 68)  note = &piano_e4;
				else if (step_in_loop == 72)  note = &piano_e4;
				else if (step_in_loop == 74)  note = &piano_e4;
				else if (step_in_loop == 76)  note = &piano_e4;
				else if (step_in_loop == 80)  note = &piano_e4;
				else if (step_in_loop == 82)  note = &piano_g4;
				else if (step_in_loop == 84)  note = &piano_c4;
				else if (step_in_loop == 86)  note = &piano_d4;
				else if (step_in_loop == 88)  note = &piano_e4;
				else if (step_in_loop == 96)  note = &piano_f4;
				else if (step_in_loop == 98)  note = &piano_f4;
				else if (step_in_loop == 100) note = &piano_f4;
				else if (step_in_loop == 102) note = &piano_f4;
				else if (step_in_loop == 104) note = &piano_f4;
				else if (step_in_loop == 106) note = &piano_e4;
				else if (step_in_loop == 108) note = &piano_e4;
				else if (step_in_loop == 110) note = &piano_e4;
				else if (step_in_loop == 112) note = &piano_g4;
				else if (step_in_loop == 114) note = &piano_g4;
				else if (step_in_loop == 116) note = &piano_f4;
				else if (step_in_loop == 118) note = &piano_d4;
				else if (step_in_loop == 120) note = &piano_c4;

				if (note)
				{
					beat.mix(*note, start_frame);
				}

				// --- 2. PERCUSSION PATH ---
				// Sleigh bells (shaker) plays on all odd steps to add festive feel
				if (step % 2 != 0)
				{
					beat.mix(shaker, start_frame);
				}

				// Loop 1 (Bars 0-7): Soft, minimalist accompaniment
				if (bar <= 7)
				{
					// Kick drum only on step 0 and 8
					if (step == 0 || step == 8)
					{
						beat.mix(kick, start_frame);
					}
					// Rimshot on step 4 and 12
					if (step == 4 || step == 12)
					{
						beat.mix(rim, start_frame);
					}
					// Conga play on steps 2, 6, 10, 14
					if (step == 2 || step == 6 || step == 10 || step == 14)
					{
						beat.mix(conga, start_frame);
					}
				}
				// Loop 2 (Bars 8-15): Full energetic beat
				else
				{
					// Standard kick on 0, 4, 8, 12
					if (step % 4 == 0)
					{
						beat.mix(kick, start_frame);
					}
					// Snare on backbeats 4, 12
					if (step == 4 || step == 12)
					{
						beat.mix(snare, start_frame);
					}
					// Closed hat on even steps, open hat on step 14
					if (step % 2 == 0)
					{
						if (step == 14)
							beat.mix(open_hat, start_frame);
						else
							beat.mix(hat, start_frame);
					}
					// Crash cymbal at the start of loop 2 (Bar 8)
					if (step == 0 && bar == 8)
					{
						beat.mix(crash, start_frame);
					}

					// --- 3. BASSLINE PATH (Pitched Drum) ---
					// Simple C Major chord root notes playing on step 0 and 8
					if (step == 0 || step == 8)
					{
						int chord_bar(bar % 8);
						bass_note = &bass_c3; // Default to C3

						if (chord_bar == 0 || chord_bar == 1 || chord_bar == 4 || chord_bar == 5)
						{
							bass_note = &bass_c3;
						}
						else if (chord_bar == 2 || chord_bar == 6)
						{
							bass_note = (step == 0) ? &bass_f2 : &bass_c3;
						}
						else if (chord_bar == 3)
						{
							bass_note = &bass_g2;
						}
						else if (chord_bar == 7)
						{
							bass_note = (step == 0) ? &bass_g2 : &bass_c3;
						}

						beat.mix(*bass_note, start_frame);
					}
				}
			}
		}

		beat.save();

		// --- 5. RAP DRILL SEQUENCER ---
		// UK/US Drill Beat (syncopated, 136 BPM, 36 bars of 16 steps)
		step_frames = 4928;
		for (bar = 0; bar < 36; ++bar)
		{
			for (step = 0; step < 16; ++step)
			{
				melody_bar = bar % 4;
				note = NULL;
				bass_note = NULL;

				start_frame = (bar * 16 + step) * step_frames;

				// --- A. MELODY PATH (Haunting C Minor Piano) ---
				// Plays in Bars 0-34
				if (bar <= 34)
				{
					if (melody_bar == 0)
					{
						if (step == 0)  note = &piano_c4;
						if (step == 3)  note = &piano_ds4;
						if (step == 6)  note = &piano_g4;
						if (step == 8)  note = &piano_g4;
						if (step == 11) note = &piano_ds4;
					}
					else if (melody_bar == 1)
					{
						if (step == 0)  note = &piano_c4;
						if (step == 3)  note = &piano_ds4;
						if (step == 6)  note = &piano_f4;
						if (step == 8)  note = &piano_fs4;
						if (step == 10) note = &piano_f4;
						if (step == 12) note = &piano_ds4;
					}
					else if (melody_bar == 2)
					{
						if (step == 0)  note = &piano_c4;
						if (step == 3)  note = &piano_ds4;
						if (step == 6)  note = &piano_g4;
						if (step == 8)  note = &piano_c5;
						if (step == 10) note = &piano_b4;
						if (step == 12) note = &piano_g4;
					}
					else if (melody_bar == 3)
					{
						if (step == 0)  note = &piano_gs4;
						if (step == 3)  note = &piano_g4;
						if (step == 6)  note = &piano_f4;
						if (step == 8)  note = &piano_ds4;
						if (step == 11) note = &piano_d4;
					}
				}

				if (note)
				{
					rap_drill.mix(*note, start_frame);
				}

				// --- B. DRUMS PATH ---
				// Kick: syncopated Drill pattern (hits on 0, 10)
				// Active in Bars 8-19 and 24-31 (Drop / Main sections)
				if ((step == 0 || step == 10) && ((bar >= 8 && bar <= 19) || (bar >= 24 && bar <= 31)))
				{
					rap_drill.mix(kick, start_frame);
				}

				// Snare: hits on step 8 (beat 3 backbeat)
				// Active in Bars 8-19, 24-31. Outro has conga/rimshots instead.
				if (step == 8 && ((bar >= 8 && bar <= 19) || (bar >= 24 && bar <= 31)))
				{
					rap_drill.mix(snare, start_frame);
					// Add a secondary clap to snare to make it fatter in main sections
					if (bar >= 12 && bar <= 19)
						rap_drill.mix(clap, start_frame);
				}

				// Triplet-feel Drill Hi-hats: steps 0, 3, 8, 11, 14
				// Active in Intro/Verse (Bars 4-31)
				if ((bar >= 4 && bar <= 31) && (bar != 20 && bar != 21 && bar != 22 && bar != 23)) // drop out during breakdown
				{
					if (step == 0 || step == 3 || step == 8 || step == 11 || step == 14)
					{
						rap_drill.mix(hat, start_frame);
					}
					// Double-time triplet rolls on steps 10 and 11
					if ((step == 10 || step == 11) && (bar % 2 == 0))
					{
						rap_drill.mix(hat, start_frame);
					}
				}

				// Open Hat on off-beat step 14
				if (step == 14 && ((bar >= 8 && bar <= 19) || (bar >= 24 && bar <= 31)))
				{
					rap_drill.mix(open_hat, start_frame);
				}

				// Shaker as extra rhythmic glue (played on steps 2, 6, 10, 14)
				if ((step == 2 || step == 6 || step == 10 || step == 14) && (bar >= 8))
				{
					rap_drill.mix(shaker, start_frame);
				}

				// Crash cymbal at the start of section changes (Bar 8, Bar 24)
				if (step == 0 && (bar == 8 || bar == 24))
				{
					rap_drill.mix(crash, start_frame);
				}

				// --- C. BASSLINE PATH (Hard-hitting 808 slides) ---
				// Bassline hits on 0, 6, 10.
				// Active in Bars 4-19, 24-31, and outro (32-34)
				if ((bar >= 4 && bar <= 34) && (bar != 20 && bar != 21 && bar != 22 && bar != 23))
				{
					if (melody_bar == 0)
					{
						if (step == 0)  bass_note = &bass_c2;
						if (step == 6)  bass_note = &bass_c2;
						if (step == 10) bass_note = &bass_ds2;
					}
					else if (melody_bar == 1)
					{
						if (step == 0)  bass_note = &bass_c2;
						if (step == 6)  bass_note = &bass_c2;
						if (step == 10) bass_note = &bass_g2;
					}
					else if (melody_bar == 2)
					{
						if (step == 0)  bass_note = &bass_c2;
						if (step == 6)  bass_note = &bass_c2;
						if (step == 10) bass_note = &bass_gs2;
					}
					else if (melody_bar == 3)
					{
						if (step == 0)  bass_note = &bass_gs2;
						if (step == 6)  bass_note = &bass_g2;
						if (step == 10) bass_note = &bass_ds2;
					}

					if (bass_note)
					{
						rap_drill.mix(*bass_note, start_frame);
					}
				}

				// --- D. BREAKDOWN PERCUSSION (Congas & Rims) ---
				// Active in Breakdown (Bars 20-23) and Outro (Bars 32-35)
				if ((bar >= 20 && bar <= 23) || (bar >= 32))
				{
					if (step == 4 || step == 12)
						rap_drill.mix(rim, start_frame);
					if (step == 2 || step == 6 || step == 10 || step == 14)
						rap_drill.mix(conga, start_frame);
				}
			}
		}

		rap_drill.save();
	}
	catch (const std::exception &e)
	{
		std::cerr << "[ SAMPLE ERROR ] " << e.what() << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
