#include <stdio.h>
#include <stdlib.h>

int compare_int(const void *a, const void *b){
    return -1 * (*(int*)a - *(int*)b);
}

int main(){
    int N, Alice = 0, Bob = 0;
    scanf("%d", &N);
    int a[N];
    for(int i = 0; i < N; i++){
        scanf("%d", &a[i]);
    }
    qsort(a, N, sizeof(int), compare_int);
    for(int i = 0; i < N; i++){
        if(i%2 == 0) Alice += a[i];
        else Bob += a[i];
    }
    printf("%d", Alice - Bob);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &N);
     ^
./Main.c:13:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &a[i]);
         ^