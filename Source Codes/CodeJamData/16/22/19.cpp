#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iomanip>
#include<cstdlib>
using namespace std;
int hash[10];
int len;
char s1[110],s2[110];
char s3[110],s4[110],s5[110],s6[110];
void fit1(int pos)
{
    for (int l=pos;l<=len;l++)
    {
        if (s3[l]=='?') s3[l]='9';
        if (s4[l]=='?') s4[l]='0';
    }
}

void fit2(int pos)
{
    for (int l=pos;l<=len;l++)
    {
        if (s3[l]=='?') s3[l]='0';
        if (s4[l]=='?') s4[l]='9';
    }
}
long long calc(char *s)
{
    long long res=0;
    int len=strlen(s+1);
    for (int i=1;i<=len;i++)
    {
        res=res*10+(s[i]-'0');
    }
    return res;
}
int cmp(char *s1, char *s2)
{
    int len=strlen(s1+1);
    for (int i=1;i<=len;i++)
    if (s1[i]<s2[i]) return -1;
    else if (s1[i]>s2[i]) return 1;
    return 0;
}
void work(int idx)
{
    printf("Case #%d: ",idx);
    scanf("%s %s",s1+1,s2+1);
    len=strlen(s1+1);
    s1[0]=s2[0]=0;
    long long minn=999999999999999999LL;
    for (int k=0;k<=1;k++)
    for (int i=0;i<=len;i++)
    if (s1[i]==s2[i]||s1[i]=='?'||s2[i]=='?')
    {
        memcpy(s3,s1,sizeof(s1));
        memcpy(s4,s2,sizeof(s2));
        for (int j=1;j<=i;j++)
        {
            if (s3[j]=='?'&&s4[j]=='?')
            {
                s3[j]=s4[j]='0';
            }
            else if (s3[j]=='?')
            {
                s3[j]=s4[j];
            }
            else if (s4[j]=='?')
            {
                s4[j]=s3[j];
            }
        }
        if (i<len)
        {
            if (s3[i+1]=='?'&&s4[i+1]=='?')
            {
                if (k==0)
                {
                    s3[i+1]='0';
                    s4[i+1]='1';
                    fit1(i+2);
                }
                else
                {
                    s3[i+1]='1';
                    s4[i+1]='0';
                    fit2(i+2);
                }
            }
            else if (s3[i+1]=='?')
            {
                if (k==0)
                {
                    if (s4[i+1]!='0')
                    {
                        s3[i+1]=s4[i+1]-1;
                        fit1(i+2);
                    }
                }
                else
                {
                    if (s4[i+1]!='9')
                    {
                        s3[i+1]=s4[i+1]+1;
                        fit2(i+2);
                    }
                }
            }
            else if (s4[i+1]=='?')
            {
                if (k==0)
                {
                    if (s3[i+1]!='9')
                    {
                        s4[i+1]=s3[i+1]+1;
                        fit1(i+2);
                    }
                }
                else
                {
                    if (s3[i+1]!='0')
                    {
                        s4[i+1]=s3[i+1]-1;
                        fit2(i+2);
                    }
                }

            }
            else
            {
                if (k==0) fit1(i+2);
                else fit2(i+2);
            }
        }
        long long x=calc(s3);
        long long y=calc(s4);
        if (abs(x-y)<minn)
        {
            minn=abs(x-y);
            memcpy(s5,s3,sizeof(s3));
            memcpy(s6,s4,sizeof(s4));
        }
        else if (abs(x-y)==minn)
        {
            if (cmp(s3,s5)<0)
            {
                memcpy(s5,s3,sizeof(s3));
                memcpy(s6,s4,sizeof(s4));
            }
            else if (cmp(s3,s5)==0&&cmp(s4,s6)<0)
            {
                memcpy(s5,s3,sizeof(s3));
                memcpy(s6,s4,sizeof(s4));
            }
        }
    }
    else
    {
        break;
    }
    printf("%s %s\n",s5+1,s6+1);
}
int main()
{
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    int t;
    scanf("%d",&t);
    for (int i=1;i<=t;i++)
    work(i);
    return 0;
}
