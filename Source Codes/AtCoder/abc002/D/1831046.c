#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void){
    int n;
    int m;
    unsigned int i, j;
    int relation[2] = {0};
    unsigned int friends[12] = {0};
    int answer = 1;
    int member = 0;
    int digit;

    scanf("%d %d", &n, &m);
    for (i = 0; i < m; i++){
        scanf("%d %d", &relation[0], &relation[1]);
        friends[relation[0]-1] += pow(2, relation[1]-1);
        friends[relation[1]-1] += pow(2, relation[0]-1);
    }

    for (i = 1; i < (1 << n); i++){
        digit = 0;
        member = 0;
        for (j = 1; j < 1 << n; j = j << 1){
            if ((i & j) == j && ((friends[digit] + (int)pow(2, digit))& i) == i){
                member++;
            }
            digit++;
        }
        answer = answer>member?answer:member;
    }

    printf("%d\n", answer);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:16:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &n, &m);
     ^
./Main.c:18:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d", &relation[0], &relation[1]);
         ^