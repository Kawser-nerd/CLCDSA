#include <stdio.h>
#include<string.h>
int main(void)
{
    char s[100000]={};
    scanf("%s",s);
    int a[100000]={};
    int count=0;
    int p=0;
    int po=0;
    char c=s[0];
    int len=strlen(s);
    //printf("%d",len);
    while(po<len)
    {
        if(c==s[po])
        {
            count++;
            po++;
        }
        else
        {
            a[p]=count;
            p++;
            count=1;
            c=s[po];
            po++;
        }
    }
    a[p]=count;
    int leng=0;
    while(a[leng]!=NULL)leng++;
    //printf("%d\n",leng);
    int minki=111111;
    int mingu=111111;
    int rightsum=0;
    int leftsum=0;
    for(int pp=0;pp<leng;pp+=2)
    {
        rightsum=0;
        leftsum=0;
        for(int q=pp+1;q<leng;q++)rightsum+=a[q];
        for(int r=pp-1;r>=0;r--)leftsum+=a[r];
        if(minki>rightsum && rightsum>=leftsum)minki=rightsum;
        if(minki>leftsum&&rightsum<=leftsum)minki=leftsum;
    }
    for(int ss=1;ss<leng;ss+=2)
    {
        rightsum=0;
        leftsum=0;
        for(int t=ss+1;t<leng;t++)rightsum+=a[t];
        for(int u=ss-1;u>=0;u--)leftsum+=a[u];
        if(mingu>rightsum&& rightsum>=leftsum)mingu=rightsum;
        if(mingu>leftsum&&rightsum<=leftsum)mingu=leftsum;
    }
    //printf("%d%d",minki,mingu);
    if(a[1]==0)printf("%d",len);
    else if(mingu>minki)printf("%d",mingu);
    else printf("%d",minki);
} ./Main.c: In function ‘main’:
./Main.c:32:18: warning: comparison between pointer and integer
     while(a[leng]!=NULL)leng++;
                  ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^