#include <stdio.h>
#include <string.h>

int tcase;
char s[30],ans[30];

int main()
{
    int i,cas;
    short flag;
    
    scanf("%d",&tcase);
    for(cas=1;cas<=tcase;cas++)
    {
        scanf("%s",s+1);
        memset(ans,0,sizeof(ans));
        
        for(i=1;s[i];i++)
            if(s[i] >= s[i-1]) ans[i] = s[i];
            else break;
        if(s[i])
        {
            for(i--;i;i--)
            {
                ans[i]--;
                if(ans[i] >= ans[i-1]) break;
            }
            for(i++;s[i];i++) ans[i] = '9';
        }
        
        printf("Case #%d: ",cas);
        flag = 0;
        for(i=1;s[i];i++)
        {
            if(ans[i] != '0') flag = 1;
            if(flag) printf("%c",ans[i]);
        }
        printf("\n");
    }
    
    return 0;
}