#include <stdio.h>

static const char K[][21]={
    "WBWBWWBWBWBWWBWBWWBW",
    "WBWWBWBWBWWBWBWWBWBW",
    "WWBWBWBWWBWBWWBWBWBW",
    "WBWBWBWWBWBWWBWBWBWW",
    "WBWBWWBWBWWBWBWBWWBW",
    "WBWWBWBWWBWBWBWWBWBW",
    "WWBWBWWBWBWBWWBWBWWB"
};

static const char scale[][3]={
    [31]="Do",
    [22]="Re",
    [4]="Mi",
    [27]="Fa",
    [30]="So",
    [20]="La",
    [0]="Si"
};

int main() {
    char S[32];
    scanf("%s", S);

    int h=((((S[1]=='B')<<1|(S[3]=='B'))<<1|(S[6]=='B'))<<1|(S[8]=='B'))<<1|(S[10]=='B');

    printf("%s\n", scale[h]);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:25:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", S);
     ^