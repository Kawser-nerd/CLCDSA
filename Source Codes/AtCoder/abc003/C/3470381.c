#include <stdio.h>
#include <stdlib.h>
int compare(const void *a,const void *b){
    return *(int*)a - *(int*)b;  
}
int main(){
    int i,n,k,r[4001];
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++){
        scanf("%d",&r[i]);
    }
    double ans=0;
    qsort(r,n,sizeof(int),compare);
    for(i=n-k;i<n;i++){
        ans=(ans+r[i])/2;
    }
    printf("%lf\n",ans);
return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&n,&k);
     ^
./Main.c:10:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&r[i]);
         ^