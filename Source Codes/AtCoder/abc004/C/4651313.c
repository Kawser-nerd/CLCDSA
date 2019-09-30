#include <stdio.h>

#define num_cards 6

void swap (char *a, char *b)
{
	char buf;
	buf   = *a;
	*a    = *b;
	*b    = buf;
	return;
}

int main (void)
{
	/* variables for main process */
	char val_card[num_cards], buf_val;
	int  num_operations;
	int  elem;

	// STEP.01
	// initialize the number of cards
	for (char itr = 0; itr < num_cards; itr++) { val_card[itr] = itr; }

	// STEP.02
	// read out the number of the operations
	int rtvl_scanf = scanf ("%d", &num_operations);

	// STEP.03
	// exchange the values of the cards
	for (size_t itr = 0; itr < num_operations; itr++)
	{
		elem = itr % 5;
		swap (&val_card[ elem ], &val_card[ elem+1 ]);
	}

	// STEP.04
	// output the result
	for (char itr = 0; itr < num_cards; itr++) { printf ("%d", val_card[itr] + 1); }
	printf ("\n");

	// STEP.END
	return 0;
}