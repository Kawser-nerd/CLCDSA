#include<stdio.h>
#include<string.h>
int main()
{
    int t,n,i,j,cnt,start,end;
    char s[1005],ans[2005];
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%s",s);
        n=strlen(s);
        start=end=1002;
        ans[1002]=s[0];
        for(j=1;j<n;j++){
            if(s[j]>=ans[start]){
                ans[start-1]=s[j];
                start--;
            }
            else{
                ans[end+1]=s[j];
                end++;
            }
        }
        printf("Case #%d: ",i);
        for(j=start;j<=end;j++){
            printf("%c",ans[j]);
        }
        printf("\n");
    }
    return 0;
}


