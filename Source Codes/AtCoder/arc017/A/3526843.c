#include<stdio.h>
int main()
{
    int n,f=1;
    scanf("%d",&n);
    for(int i=2;i<n;i++)
    {
        f=n%i;
        if(f==0)
        {
            printf("NO\n");
            break;
        }

    }
    if(f!=0)
        printf("YES\n");

} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^