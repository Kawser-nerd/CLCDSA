#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int descending_compare(const void *a, const void *b){
    return (int)(*(int*)b - *(int*)a);
}

int ascending_compare(const void *a, const void *b){
    return (int)*(int*)a - *(int*)b;
}

int s[100000];
int t[100000];
int c[100000];
int merge[200000];
int time[200000] = {0};

int main(void){
    int N, C;
    int i, j;
    int max = 0;
    scanf("%d %d", &N, &C);

    for (i = 0; i < N; i++){
        scanf("%d %d %d", &s[i], &t[i], &c[i]);
    }

    for (i = 1; i <= C; i++){
        for (j = 0; j < 200000; j++){
            merge[j] = 0;
        }
        for (j = 0; j < N; j++){
            if (c[j] == i){
                merge[s[j]*2-1] = 1;
                merge[t[j]*2] = -1;
            }
        }
        for (j = 1; j < 200000; j++){
            merge[j] += merge[j-1];
        }
        for (j = 0; j < 200000; j++){
            if (merge[j] > 0){
                time[j]++;
            }
        }
    }

    for (i = 0; i < 200000; i++){
        max = time[i]>max?time[i]:max;
    }

    printf("%d\n", max);


    return 0;
} ./Main.c: In function ‘main’:
./Main.c:24:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &N, &C);
     ^
./Main.c:27:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d %d", &s[i], &t[i], &c[i]);
         ^