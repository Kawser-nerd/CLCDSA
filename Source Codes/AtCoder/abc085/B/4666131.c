#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const void *b){
    return *(int*)b-*(int*)a;
}
int main(void){
    int n,d[100],i,x=1;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&d[i]);
    }
    qsort(d,n,sizeof(int),cmp);
    for(i=1;i<n;i++){
        if(d[i]<d[i-1]) x++;
    }
    printf("%d\n",x);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:10:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&d[i]);
         ^