#include <stdio.h>
int main(void)
{
    int a,b,c;
    long int x,y;
    scanf("%d %d %d %ld %ld",&a,&b,&c,&x,&y);
    c=2*c;
    long long int ans=0;
    if(a+b>c)
    {
        if(x>y)
        {
            ans+=y*c;
            if(a>c)ans+=(x-y)*c;
            else ans+=(x-y)*a;
        }
        else
        {
            ans+=x*c;
            if(b>c)ans+=(y-x)*c;
            else ans+=(y-x)*b;
        }
    }
    else ans+=x*a+y*b;
    printf("%lld",ans);
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d %ld %ld",&a,&b,&c,&x,&y);
     ^