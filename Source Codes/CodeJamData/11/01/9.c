/*
problem a, google code jam 2011
coded by Jason Thong
jason.thong.86@gmail.com

insight: always move both robots to their next position, even if the other one may be the bottleneck
this could be sped up by jumping N time steps where the current robot needed has to move N steps to press the next button...

compiled with: gcc a.c -o a -Wall -O3
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_CASES 100

int main(int argc, char **argv) {
	char input_char, update_num_buttons_pressed;
	int test_cases, num_buttons, i, j, k, which_robot[MAX_CASES], which_button[MAX_CASES];
	int next_button_blue, next_button_orange, pos_blue, pos_orange, num_buttons_pressed, steps;
	FILE *fp_in, *fp_out;
	
	if (argc!=3) {
		printf("provide input and output file names as first 2 command line parameters\n");
		exit(1);
	}
	if ((fp_in=fopen(argv[1],"r"))==NULL) { printf("can't open file %s\n", argv[1]); exit(1); }
	if ((fp_out=fopen(argv[2],"w"))==NULL) { printf("can't open file %s\n", argv[2]); exit(1); }
	fscanf(fp_in, "%d\n", &test_cases);
	
	for (i=1; i<=test_cases; i++) {
		fscanf(fp_in, "%d", &num_buttons);
		for (j=0; j<num_buttons; j++) {
			fscanf(fp_in, " %c %d", &input_char, &k);
			which_robot[j] = (input_char=='B') ? 1 : 0;
			which_button[j] = k;
		}
		pos_blue = 1;
		pos_orange = 1;
		num_buttons_pressed = 0;
		steps = 0;
		for (j=0; j<num_buttons; j++) if (which_robot[j]==1) break;
		next_button_blue = (j<num_buttons) ? which_button[j] : 1;
		for (j=0; j<num_buttons; j++) if (which_robot[j]==0) break;
		next_button_orange = (j<num_buttons) ? which_button[j] : 1;
//		printf("next blue %d, next orange %d\n", next_button_blue, next_button_orange);
		while (num_buttons_pressed < num_buttons) {
			update_num_buttons_pressed = 0;
			if (pos_blue < next_button_blue) pos_blue++;
			else if (pos_blue > next_button_blue) pos_blue--;
			else if (which_robot[num_buttons_pressed]==1) {
				update_num_buttons_pressed = 1;
				for (j=num_buttons_pressed+1; j<num_buttons; j++) if (which_robot[j]==1) break;
				next_button_blue = (j<num_buttons) ? which_button[j] : 1;
//				printf("next blue %d\n", next_button_blue);
			}
			if (pos_orange < next_button_orange) pos_orange++;
			else if (pos_orange > next_button_orange) pos_orange--;
			else if (which_robot[num_buttons_pressed]==0) {
				update_num_buttons_pressed = 1;
				for (j=num_buttons_pressed+1; j<num_buttons; j++) if (which_robot[j]==0) break;
				next_button_orange = (j<num_buttons) ? which_button[j] : 1;
//				printf("next orange %d\n", next_button_orange);
			}
			if (update_num_buttons_pressed) num_buttons_pressed++;
			steps++;
//			printf("pos blue %d, pos orange %d\n", pos_blue, pos_orange);
		}
		fprintf(fp_out, "Case #%d: %d\n", i, steps);
//		printf("\n\n");
	}
	
	fclose(fp_in);
	fclose(fp_out);
	return 0;
}



