#include<stdio.h>
#include<string.h>
int main()
{
    char s[51],s1[51],t[51],ans[51];
    scanf("%s",s1);
    scanf("%s",t);
    int L1=strlen(s1),L2=strlen(t),i,j,flag=1,k,count=0;
    strcpy(ans,s1);
//    for(i=0; i<L1; i++)
//        if(ans[i]=='?')
//            ans[i]='z';
    for(i=0; i<L1; i++)
    {
        strcpy(s,s1);
        int count1=0;
        for(j=0; j<L2; j++)
            if((s1[i+j]=='?')||(s1[i+j]==t[j]))
                count1++;
        if(count1==L2)
        {
            for(k=0; k<L1; k++)
            {
                if((k<i)||(k>=i+L2))
                {
                    if(s[k]=='?')
                        s[k]='a';
                }
                else
                    s[k]=t[k-i];
            }
            strcpy(ans,s);
        }
        else
            count++;
    }
    if(count==L1)
        printf("UNRESTORABLE");
    else
        printf("%s",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s1);
     ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",t);
     ^