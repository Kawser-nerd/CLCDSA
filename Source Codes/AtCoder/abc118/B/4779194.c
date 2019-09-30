#include <stdio.h>
#include <string.h>
int main(void){
    int n,m,i,j,k,count=0,a[30]={0};
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++){
        scanf("%d",&k);
        for(j=0;j<k;j++){
            int l;
            scanf("%d",&l);
            a[l-1]++;
        }
    }
    for(i=0;i<m;i++){
        if(a[i]==n) count++;
    }
    printf("%d\n",count);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&n,&m);
     ^
./Main.c:7:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&k);
         ^
./Main.c:10:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%d",&l);
             ^