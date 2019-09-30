#include <stdio.h>

int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    int l[q],r[q],t[q];
    for(int i=0;i<q;i++){
        scanf("%d%d%d",&l[i],&r[i],&t[i]);
    }
    int a[100]={0};
    for(int i=0;i<q;i++){
        for(int j=l[i]-1;j<r[i];j++){
            a[j]=t[i];
        }
    }
    for(int i=0;i<n;i++){
        printf("%d\n",a[i]);
    }
    
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&n,&q);
     ^
./Main.c:10:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d%d",&l[i],&r[i],&t[i]);
         ^