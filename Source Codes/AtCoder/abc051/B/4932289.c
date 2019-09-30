#include <stdio.h>
int main(void)
{
    int k,s;
    scanf("%d%d", &k, &s);
    int x,y,z,ans=0;
    for(z=0; z<=k; z++)
    {
        if(2*k<s-z) ans+=0;
        else
        {
            if(s-z<0) ans+=0;
            else if(k>=s-z) ans+=s-z+1;
            else ans+=2*k-s+z+1;
        }
    }
    printf("%d", ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d", &k, &s);
     ^