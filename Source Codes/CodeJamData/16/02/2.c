#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void solve(char stack[])
{
    int i;
    int swap = 0;
    int swapTime = 0;
    for(i=strlen(stack)-1;i>=0;--i)
    {
        if( (stack[i]=='-' && swap==0) || (stack[i]=='+' && swap!=0))
        {
            swap = !swap;
            ++swapTime;
        }
    }
    printf("%d\n",swapTime);
}

int main()
{
    int t, T;
    char stack[105];
    scanf("%d",&T);
    for(t=1;t<=T;++t)
    {
        scanf("%s",stack);
        printf("Case #%d: ", t);
        solve(stack);
    }

    return 0;
}
