#include <stdio.h>
int main(void){
    // Your code here!
    int n,q,l,r,t,i,j;
    scanf("%d%d",&n,&q);
    int a[n];
    for(i=0;i<n;i++)
        a[i]=0;
    for(i=0;i<q;i++){
        scanf("%d%d%d",&l,&r,&t);
        for(j=l-1;j<=r-1;j++)
            a[j]=t;
    }
    for(i=0;i<n;i++)
        printf("%d\n",a[i]);
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&n,&q);
     ^
./Main.c:10:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d%d",&l,&r,&t);
         ^