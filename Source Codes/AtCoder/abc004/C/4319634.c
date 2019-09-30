#include <stdio.h>
#define Num_of_Cards 6
#define mod 5
#define swap(a, b) (a+=b, b=a-b, a-=b)
int Cards[6] = {1, 2, 3, 4, 5, 6};

int main(int argc, char const *argv[]) {
    // ??
    long N;
    // ????
    scanf("%ld", &N );
    // ??????
    N = N%(Num_of_Cards*mod);
    for (int i = 0; i < N; i++) {
        swap( Cards[i%5], Cards[i%5+1] );
    }
    // ??
    for (int i = 0; i < Num_of_Cards; i++) {
        printf("%d", Cards[i] );
    }
    printf("\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld", &N );
     ^