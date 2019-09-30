#include<stdio.h>
#include<string.h>
typedef long long ll;
char s[2000000];
ll n;
int fn(char c)
{
    if((c=='a')||(c=='u')||(c=='o')||(c=='i')||(c=='e'))
    return 1;
    return 0;
}
int ln(int i)
{
    int k;
    for(k=0;s[k]!='\0';k++)
    {
        if(fn(s[i+k]))
        return k;
    }
    return k;
}
int main()
{
    freopen("C:\\TC\\BIN\\codejam2013\\A-large.in.txt","r",stdin);
    freopen("C:\\TC\\BIN\\codejam2013\\out.txt","w",stdout);


    int t,cs;
    ll i,j,k,r,l;
    ll con,lf;

    scanf("%d",&t);
    for(cs=1;cs<=t;cs++)
    {
        printf("Case #%d: ",cs);
        scanf("%s %d",s,&n);
        r=0;
        l=strlen(s);
        con=0;
        lf=-1;
        for(i=0;i<l;i++)
        {
            if(!fn(s[i]))
            {
                con++;
                if(con>=n)
                {
                    lf=i-n+1;
                }
            }
            else
            con=0;
            if(lf!=-1)
            r+=lf+1;
        }
        printf("%lld\n",r);
    }
    return 0;
}
