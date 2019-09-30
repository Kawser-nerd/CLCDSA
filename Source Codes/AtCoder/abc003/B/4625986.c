#include <stdio.h>
#include <stdbool.h>

#define len_string_max  10
#define str_phrase_win  "You can win"
#define str_phrase_lose "You will lose"

int main (void)
{
	/* variables for main process */
	char buf_target_string[2][len_string_max+1];

	/* support variables for main process */
	bool stat_game;
	int  rtvl_scanf;
	int  itr;

	// STEP.01
	// read out the target string
	rtvl_scanf = scanf ("%s", buf_target_string[1]);
	rtvl_scanf = scanf ("%s", buf_target_string[2]);

	// STEP.02
	// initialize the status of the game
	stat_game = true;

	// STEP.03
	// judge whether it is possible to win
	while (buf_target_string[1][itr] != '\0')
	{
		// STEP.03.01
		// if the target characters were completely equal
		if (buf_target_string[1][itr] == buf_target_string[2][itr]) { itr++; continue; }

		// STEP.03.02
		// if the character in the 1st string was '@'
		if (buf_target_string[1][itr] == '@')
		{
			if (buf_target_string[2][itr] == 'a') { itr++; continue; }
			if (buf_target_string[2][itr] == 't') { itr++; continue; }
			if (buf_target_string[2][itr] == 'c') { itr++; continue; }
			if (buf_target_string[2][itr] == 'o') { itr++; continue; }
			if (buf_target_string[2][itr] == 'd') { itr++; continue; }
			if (buf_target_string[2][itr] == 'e') { itr++; continue; }
			if (buf_target_string[2][itr] == 'r') { itr++; continue; }
		}

		// STEP.03.03
		// if the character in the 2nd string was '@'
		if (buf_target_string[2][itr] == '@')
		{
			if (buf_target_string[1][itr] == 'a') { itr++; continue; }
			if (buf_target_string[1][itr] == 't') { itr++; continue; }
			if (buf_target_string[1][itr] == 'c') { itr++; continue; }
			if (buf_target_string[1][itr] == 'o') { itr++; continue; }
			if (buf_target_string[1][itr] == 'd') { itr++; continue; }
			if (buf_target_string[1][itr] == 'e') { itr++; continue; }
			if (buf_target_string[1][itr] == 'r') { itr++; continue; }
		}

		// STEP.03.03
		// if the characters were not equal, considering the effect of `@`
		stat_game = false;
		break;
	}

	// STEP.04
	// output the result
	if (stat_game) { printf ("%s\n", str_phrase_win ); }
	else           { printf ("%s\n", str_phrase_lose); }

	// STEP.TRUE_END
	return 0;
}