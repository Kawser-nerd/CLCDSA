#include <stdio.h>
#include <stdbool.h>

#define len_string_max  10
#define str_phrase_win  "You can win"
#define str_phrase_lose "You will lose"

bool isEqualToAtMark (char target)
{
	if (target == 'a' || target == 't' || target == 'c' || target == 'o' || target == 'd' || target == 'e' || target == 'r')
	{ return true; }
	else
	{ return false; }
}

int main (void)
{
	/* variables for main process */
	char buf_target_string[2][len_string_max+1];

	/* support variables for main process */
	bool stat_game, stat_isEqualToAtMark[3];
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
		// if the character in the 1st string was '@'
		// if the character in the 2nd string was '@'
		stat_isEqualToAtMark[0] = buf_target_string[1][itr] == buf_target_string[2][itr];
		stat_isEqualToAtMark[1] = buf_target_string[1][itr] == '@' && isEqualToAtMark (buf_target_string[2][itr]);
		stat_isEqualToAtMark[2] = buf_target_string[2][itr] == '@' && isEqualToAtMark (buf_target_string[1][itr]);
		if (stat_isEqualToAtMark[0] || stat_isEqualToAtMark[1] || stat_isEqualToAtMark[2]) { itr++; continue; }

		// STEP.03.02
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