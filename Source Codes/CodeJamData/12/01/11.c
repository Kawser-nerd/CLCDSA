#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char to[26]={'y','h','e','s','o','c','v','x','d','u','i',
'g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
int main()
{
    freopen("out.txt","w",stdout);
    freopen("A-small-attempt0.in","r",stdin);
    int n,i,j;
    char ins[120],outs[120];
    scanf("%d%*c", &n);
    for(i = 1; i <= n; i++)
    {
        gets(ins);
        j = strlen(ins);
        outs[j] = 0;
        while(j--)
        {
            if(isalpha(ins[j]))
            outs[j] = to[ins[j]-'a'];
            else outs[j] = ' ';
        }
        printf("Case #%d: %s\n",i,outs);
    }
    return 0;
}
