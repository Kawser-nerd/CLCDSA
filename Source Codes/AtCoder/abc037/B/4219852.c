#include <stdio.h>
int main(void){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        a[i] = 0;
    }
    int q;
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        int l,r,t;
        scanf("%d%d%d",&l,&r,&t);
        while(l<=r)
        {
            a[l-1] = t;
            l++;
        }
    }
    
    for(int i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&q);
     ^
./Main.c:15:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d%d",&l,&r,&t);
         ^