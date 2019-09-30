// AtCoder Beginner Contest 001 C
// [URL]      https://atcoder.jp/contests/abc001/tasks/abc001_3
// [compiler] C (GCC 5.4.1)
// 
#include <stdio.h>
#include <math.h>

unsigned int calc_windscale( unsigned int wind_run )
{
	/* local variables for this function */
	unsigned int wind_speed_rounded;

	// STEP.01
	// convert the wind run to wind speed
	wind_speed_rounded = (unsigned int) round( wind_run/6.0e+00 );

	// STEP.END
	// determine the wind scale to output
	if      ( wind_speed_rounded <=   2 ) { return  0; }
	else if ( wind_speed_rounded <=  15 ) { return  1; }
	else if ( wind_speed_rounded <=  33 ) { return  2; }
	else if ( wind_speed_rounded <=  54 ) { return  3; }
	else if ( wind_speed_rounded <=  79 ) { return  4; }
	else if ( wind_speed_rounded <= 107 ) { return  5; }
	else if ( wind_speed_rounded <= 138 ) { return  6; }
	else if ( wind_speed_rounded <= 171 ) { return  7; }
	else if ( wind_speed_rounded <= 207 ) { return  8; }
	else if ( wind_speed_rounded <= 244 ) { return  9; }
	else if ( wind_speed_rounded <= 284 ) { return 10; }
	else if ( wind_speed_rounded <= 326 ) { return 11; }
	else                                  { return 12; };

}

char *calc_winddirection( unsigned int scale, unsigned int direction )
{
	/* local variable for this function */
	unsigned int direction_converted;

	// STEP.01
	// convert the value of the direction
	direction_converted = 10 * direction;

	// determine the wind direction as string
	if ( scale == 0 ) { return "C"; }
	else {
		if      (  1125 <= direction_converted && direction_converted <  3375 ) { return "NNE"; }
		else if (  3375 <= direction_converted && direction_converted <  5625 ) { return "NE";  }
		else if (  5625 <= direction_converted && direction_converted <  7875 ) { return "ENE"; }
		else if (  7875 <= direction_converted && direction_converted < 10125 ) { return "E";   }
		else if ( 10125 <= direction_converted && direction_converted < 12375 ) { return "ESE"; }
		else if ( 12375 <= direction_converted && direction_converted < 14625 ) { return "SE";  }
		else if ( 14625 <= direction_converted && direction_converted < 16875 ) { return "SSE"; }
		else if ( 16875 <= direction_converted && direction_converted < 19125 ) { return "S";   }
		else if ( 19125 <= direction_converted && direction_converted < 21375 ) { return "SSW"; }
		else if ( 21375 <= direction_converted && direction_converted < 23625 ) { return "SW";  }
		else if ( 23625 <= direction_converted && direction_converted < 25875 ) { return "WSW"; }
		else if ( 25875 <= direction_converted && direction_converted < 28125 ) { return "W";   }
		else if ( 28125 <= direction_converted && direction_converted < 30375 ) { return "WNW"; }
		else if ( 30375 <= direction_converted && direction_converted < 32625 ) { return "NW";  }
		else if ( 32625 <= direction_converted && direction_converted < 34875 ) { return "NNW"; }
		else                                                                    { return "N";   };
	};
}

int main (void)
{
	/* variables for main process */
	unsigned int wind_direction;
	unsigned int wind_run;
	unsigned int wind_scale;

	// STEP.01
	// read the values of degree and dis
	scanf( "%d %d", &wind_direction, &wind_run );

	// STEP.02
	// determine the wind scale
	wind_scale = calc_windscale( wind_run );

	// STEP.03
	// output the result
	printf( "%s %d\n", calc_winddirection( wind_scale, wind_direction ), wind_scale );

	// STEP.TRUE_END
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:75:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf( "%d %d", &wind_direction, &wind_run );
  ^