#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const void *b){
    return *(int*)a-*(int*)b;
}
int main(void){
    int n,k,i,r[100];
    double rate=0;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++){
        scanf("%d",&r[i]);
    }
    qsort(r,n,sizeof(int),cmp);
    for(i=n-k;i<n;i++){
        rate=((rate+r[i])/2);
    }
    printf("%f\n",rate);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&n,&k);
     ^
./Main.c:11:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&r[i]);
         ^