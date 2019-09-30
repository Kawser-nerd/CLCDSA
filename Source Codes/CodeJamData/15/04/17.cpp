#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    //FILE* reader = fopen("input.txt", "r");
    FILE* reader = fopen("D-large.in", "r");
    int T;
    fscanf(reader, "%d", &T);

    for (int t=1; t<=T; t++) {
        int X, R, C;
        fscanf(reader, "%d %d %d", &X, &R, &C);
        if(R>C)
            swap(R, C);

        bool doable = true;
        if (R*C % X != 0)
            doable = false;
        else if (X >= 2*R+1 || X > C) // L, or straight wins.
            doable = false;
        else if (X >= 7) // Hole inside X
            doable = false;
        else if (X==6) {
            if (R == 3)
                doable = false;
            else
                doable = true;
        } else if (X==5) {
            if(R==3 && C==5)
                doable = false;
            else
                doable = true;

        } else if (X==4) {
            if(R==2)
                doable = false;
            else
                doable = true;
        } else
            doable = true;

        if (doable)
            printf("Case #%d: GABRIEL\n", t);
        else
            printf("Case #%d: RICHARD\n", t);

    }
    return 0;
}
