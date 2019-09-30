#include <stdio.h>
#include <stdlib.h>
int compare_int(const void *a, const void *b){
    return *(int *)b - *(int *)a;
}

int main(void){
    int N = 0; int H = 0;
    scanf("%d %d", &N, &H);
    int a[100000] = {0}; int b[100000] = {0};
    for(int i = 0; i < N; i++){
        scanf("%d %d", &a[i], &b[i]);
    }
    int amax = 0;
    for(int i = 0; i < N; i++){
        if(amax < a[i]){
            amax = a[i];
        }
    }
    qsort(b, N, sizeof(int), compare_int);

    int attack = 0;
    for(int i = 0; i < N; i++){
        if(b[i] >= amax){
            H -= b[i];
            attack++;
            if(H <= 0){
                break;
            }
        }else {
            break;
        }
    }
    while(H > 0){
        H -= amax;
        attack++;
    }
    printf("%d\n", attack);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &N, &H);
     ^
./Main.c:12:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d", &a[i], &b[i]);
         ^