#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    FILE* reader = fopen("B-large.in", "r");
    int T;
    fscanf(reader, "%d", &T);

    for (int t=1; t<=T; t++) {
        int D;
        fscanf(reader, "%d", &D);
        int P[1000];
        for (int i=0; i<D; i++) {
            fscanf(reader, "%d", &P[i]);
        }

        int time_best=-1;
        for (int opt=1; opt<=1000; opt++) {
            int time=opt;
            for (int i=0; i<D; i++) {
                time += (P[i]-1)/opt;
            }

            if(time_best==-1 || time<time_best)
                time_best = time;
        }

        printf("Case #%d: %d\n", t, time_best);
    }

    return 0;
}
