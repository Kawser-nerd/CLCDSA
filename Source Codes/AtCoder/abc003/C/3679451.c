#include <stdio.h>
#include <stdlib.h>

int compare_int(const void *a, const void *b){
    return *(int*)a-*(int*)b;
}

int main(){
    int n,i,k;
    float rate=0.0;

    scanf("%d%d",&n,&k);
    int r[n];

    for(i=0;i<n;i++){
        scanf("%d",&r[i]);
    }
    qsort(r,n,sizeof(int),compare_int);

    for(i=0;i<k;i++){
        rate=(rate+r[n-k+i])/2;
    }

    printf("%f\n",rate);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&n,&k);
     ^
./Main.c:16:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&r[i]);
         ^