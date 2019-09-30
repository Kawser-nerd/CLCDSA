// [reference]
// <1> https://www.slideshare.net/chokudai/abc006 p.26/57
// 
#include <stdio.h>

#define num_legs_adult   2
#define num_legs_senior  3
#define num_legs_baby    4
#define val_error       -1


// calculate the total number of the legs from each population
unsigned calc_num_legs( unsigned num_adults, unsigned num_seniors, unsigned num_babies )
{
	return num_adults*num_legs_adult + num_seniors*num_legs_senior + num_babies*num_legs_baby;
}


// output the possible structure using `printf`
void printf_structure( unsigned num_adults, unsigned num_seniors, unsigned num_babies )
{
	printf( "%d %d %d\n", num_adults, num_seniors, num_babies );
	return;
}


// find the possible structure of the adults, seniors and babies
void find_structure( unsigned population, unsigned num_legs_total )
{
	/* variables for this function */
	unsigned itr_adult, itr_senior, itr_baby;

	// STEP.01
	// iterate the population of the seniors
	for(itr_senior = 0; itr_senior <= 1; itr_senior++)
	{
		for(itr_adult = 0; itr_adult <= population-itr_senior; itr_adult++)
		{
			itr_baby = population - ( itr_adult+itr_senior );
			if( itr_baby >= 0 && calc_num_legs( itr_adult, itr_senior, itr_baby ) == num_legs_total )
			{
				printf_structure( itr_adult, itr_senior, itr_baby );
				return; // STEP.TRUE_END
			}
		}
	}

	// STEP.BAD_END
	printf_structure( val_error, val_error, val_error );
	return;
}


int main (void)
{
	/* variables for main process */
	unsigned population, num_legs_total;

	// STEP.01
	// read the target number
	scanf( "%d %d", &population, &num_legs_total );

	// STEP.02
	// output the mod
	find_structure( population, num_legs_total );

	// STEP.TRUE_END
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:61:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf( "%d %d", &population, &num_legs_total );
  ^