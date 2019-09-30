#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define R 0
#define O 1
#define Y 2
#define G 3
#define B 4
#define V 5

#define NUM_COLORS 6

#define RED_H(X) (X[R] + X[V] + X[O])
#define YEL_H(X) (X[Y] + X[O] + X[G])
#define BLU_H(X) (X[B] + X[G] + X[V])

int invalid[NUM_COLORS][NUM_COLORS] = {
    {1, 1, 0, 0, 0, 1},
    {1, 1, 1, 0, 0, 0},
    {0, 1, 1, 1, 0, 0},
    {0, 0, 1, 1, 1, 0},
    {0, 0, 0, 1, 1, 1},
    {1, 0, 0, 0, 1, 1}
};

char color_char[NUM_COLORS + 1] = "ROYGBV";

void solve(){
    int i, j, temp;
    int N;
    int u[NUM_COLORS]; /* Unicorns */
    int sorted[3]; /* For small */
    char* result;

    scanf(" %d", &N);
    for (i = 0; i < NUM_COLORS; ++i)
        scanf(" %d", u + i);

    result = calloc(N+1, sizeof(char));

    /* Easy base case */
    if ((RED_H(u) > N/2) ||
        (YEL_H(u) > N/2) ||
        (BLU_H(u) > N/2)){
        printf("IMPOSSIBLE");
        return;
    }

    /* For small dataset */
    /* selection sort descending */
    sorted[0] = R;
    sorted[1] = Y;
    sorted[2] = B;
    for (i = 0; i < 3; ++i){
        for (j = i + 1; j < 3; ++j){
            if (u[sorted[j]] > u[sorted[i]]){
                temp = sorted[i];
                sorted[i] = sorted[j];
                sorted[j] = temp;
            }
        }
    }

    for (i = 0; i < u[sorted[0]]; ++i){
        result[i << 1] = color_char[sorted[0]];
    }
    j = (N%2) ? (N-2) : (N-1);
    for (i = 0; i < u[sorted[1]]; ++i){
        result[j - (i << 1)] = color_char[sorted[1]];
    }
    for (i = 0; i < N; ++i){
        if (!result[i])
            result[i] = color_char[sorted[2]];
    }

    printf(result);

}

int main(int argc, char** argv){
    int T, t;

    scanf(" %d", &T);

    for (t = 1; t <= T; ++t){
        printf("Case #%d: ", t);
        solve();
        printf("\n");
    }

    return 0;
}
