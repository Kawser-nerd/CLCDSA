#include <stdio.h>
#include <stdlib.h>

int asc(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int main(){
    int n, m, sum=0;
    scanf("%d %d", &n, &m);
    
    int x[m];
    for(int i = 0; i < m; i++){
        scanf("%d", &x[i]);
    }
    if(n >= m){
        printf("%d", 0);
        return 0;
    }

    qsort(x, m, sizeof(int), asc);

    int dif[m-1];
    for(int i = 0; i < m-1; i++){
        dif[i] = x[i+1] - x[i];
    }
               
    qsort(dif, m-1, sizeof(int), asc);

    for(int i = 0; i < m-n; i++){
        sum += dif[i];
    }
               
    printf("%d", sum);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &n, &m);
     ^
./Main.c:14:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &x[i]);
         ^