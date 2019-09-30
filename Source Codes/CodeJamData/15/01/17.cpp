#include <iostream>
#include <stdio.h>
#include <algorithm>>

using namespace std;

int main()
{
    FILE* reader = fopen("A-large.in", "r");

    int T;
    fscanf(reader, "%d", &T);

    for (int t=1; t<=T; t++) {
        int S_max;
        int S[1010];
        fscanf(reader, "%d", &S_max);
        char c;
        fscanf(reader, "%c", &c);

        for(int i=0; i<=S_max; i++) {
            fscanf(reader, "%c", &c);
            S[i]=c-'0';
        }

        int standing = 0;
        int friends = 0;

        for(int i=0; i<=S_max; i++) {
            if(standing >= i) {
                standing += S[i];
            } else {
                friends += i-standing;
                standing = i + S[i];
            }
        }

        printf("Case #%d: %d\n", t, friends);
    }

    return 0;
}
