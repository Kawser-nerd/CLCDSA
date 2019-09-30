#include <stdio.h>
#include <math.h> 

int
main(int argc, char* argv[])
{
    FILE       *fp;
    int         num_testcases;
    int         num_flies;
    int         locs[500][3];
    int         vels[500][3];    
    int         i, j;
    long double      time;
    long double      distance;
    long double      cm[3];
    long double      vel[3];

    fp = fopen(argv[1], "r");

    fscanf(fp, "%d\n", &num_testcases);

    for (i = 0; i < num_testcases; i++) {
        fscanf(fp, "%d\n", &num_flies);
        cm[0] = 0.0; vel[0] = 0.0;
        cm[1] = 0.0; vel[1] = 0.0;
        cm[2] = 0.0; vel[2] = 0.0;

        for (j = 0; j < num_flies; j++) {
            fscanf(fp, "%d %d %d %d %d %d\n", &locs[j][0], &locs[j][1], &locs[j][2],
                   &vels[j][0], &vels[j][1], &vels[j][2]);
            cm[0] += locs[j][0];
            cm[1] += locs[j][1];
            cm[2] += locs[j][2];

            vel[0] += vels[j][0];
            vel[1] += vels[j][1];
            vel[2] += vels[j][2];
        }
        cm[0] /= (long double)num_flies;
        cm[1] /= (long double)num_flies;
        cm[2] /= (long double)num_flies;
        vel[0] /= (long double)num_flies;
        vel[1] /= (long double)num_flies;
        vel[2] /= (long double)num_flies;

        if (vel[0] * vel[0] + vel[1] * vel[1] + vel[2] * vel[2] == 0.0) {
            time = 0.0;
        }
        else {
            time = -(cm[0] * vel[0] + cm[1] * vel[1] + cm[2] * vel[2]) / 
                   (vel[0] * vel[0] + vel[1] * vel[1] + vel[2] * vel[2]);
        }

        if (time <= 1E-07) {
            time = 0.0;
            distance = cm[0]*cm[0] + cm[1]*cm[1] + cm[2]*cm[2];
            distance = sqrtl(distance);
        }
        else {
            distance = cm[0]*cm[0] + cm[1]*cm[1] + cm[2]*cm[2] + 
                       2 * time * (vel[0]*cm[0] + vel[1]*cm[1] + vel[2]*cm[2]) +
                       time * time * (vel[0]*vel[0] + vel[1]*vel[1] + vel[2]*vel[2]);
    
            if (distance <= 1E-07)
                distance = 0.0;
            else
                distance = sqrtl(distance);
        }
                    
        printf("Case #%d: %.8Lf %.8Lf\n", i + 1, distance, time);
    }

    fclose(fp);

    return 0;
}
