#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef M_PI_4
#define M_PI_4      0.785398163397448309116
#endif

int main(int argc, char **argv)
{
	FILE			*in;
	FILE			*out;
    unsigned int    num_cases;
    unsigned int    cur_case;
    double          f;
    double          R;
    double          R_m;
    double          t;
    double          r;
    double          g;
    double          d;
    double          x;
    double          x_max;
    double          x_max_y;
    double          y;
    double          y_max;
    double          y_max_full;
    double          s;
    double          s_hit;
    double          a;
    double          acosx;
    double          acosy;

	if(argc < 3)
        return 0;

	in = fopen(argv[1], "r");
	out = fopen(argv[2], "w");

	if(!in || !out)
	{
		if(in)
			fclose(in);
		if(out)
			fclose(out);
		return 0;
	}

    fscanf(in, "%u\n", &num_cases);

	for(cur_case = 0; cur_case < num_cases; cur_case++)
	{
        fscanf(in, "%lf %lf %lf %lf %lf\n", &f, &R, &t, &r, &g);

        a = g - f * 2;
        if(a <= 0)
        {
            fprintf(out, "Case #%u: %.7f\n", cur_case + 1, (float)1.);
            continue;
        }

        s = M_PI_4 * R * R;
        s_hit = s;
        d = g + 2 * r;
        R_m = R - t - f;
        x_max = sqrt(R_m * R_m - (r + f) * (r + f));

        for(x = r + f; x < x_max; x += d)
        {
            y_max = sqrt(R_m * R_m - x * x);
            y_max_full = -1.;
            if(x + a < R_m)
                y_max_full = sqrt(R_m * R_m - (x + a) * (x + a)) - a - r - f + d;
            if(y_max_full >= d)
            {
                s_hit -= a * a * floor(y_max_full / d);
                y = r + f + d * floor(y_max_full / d);
            }
            else
                y = r + f;

            acosx = acos(x / R_m);
            for(; y < y_max; y += d)
            {
                x_max_y = sqrt(R_m * R_m - y * y);
                acosy = acos(y / R_m);
                s_hit -= (x * y + ((acosx + acosy) / 2 -  M_PI_4) * R_m * R_m - (y_max * x + x_max_y * y) / 2);
                if(y + a < y_max)
                    s_hit += (x * (y + a) + ((acosx + acos((y + a) / R_m)) / 2 -  M_PI_4) * R_m * R_m - (y_max * x + sqrt(R_m * R_m - (y + a) * (y + a)) * (y + a)) / 2);
                if(x + a < x_max_y)
                    s_hit += ((x + a) * y + ((acos((x + a) / R_m) + acosy) / 2 -  M_PI_4) * R_m * R_m - (sqrt(R_m * R_m - (x + a) * (x + a)) * (x + a) + x_max_y * y) / 2);
            }
        }
        fprintf(out, "Case #%u: %.7lf\n", cur_case + 1, s_hit / s);
	}

	fclose(in);
	fclose(out);
	return 1;
}
