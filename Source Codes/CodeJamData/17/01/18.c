#include <stdio.h>
#include <string.h>

int tcase,n,K,ans;
char s[1010];

int main()
{
    int i,j,cas;
    
    scanf("%d",&tcase);
    for(cas=1;cas<=tcase;cas++)
    {
        scanf("%s%d",s+1,&K);
        n = strlen(s+1); ans = 0;
        
        for(i=1;i+K-1<=n;i++) if(s[i] == '-')
        {
            ans++;
            for(j=i;j<i+K;j++) s[j] = (s[j] == '+' ? '-' : '+');
        }
        
        for(i=1;i<=n;i++) if(s[i] == '-') break;
        printf("Case #%d: ",cas);
        if(i <= n) printf("IMPOSSIBLE\n");
        else printf("%d\n",ans);
    }
    
    return 0;
}