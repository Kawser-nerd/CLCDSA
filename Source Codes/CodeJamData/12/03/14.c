#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char temp[10];
char min[10];
char max[10];
char cur[10];
int factor(int m)
{
    int len,i,j,k,flag;
    sprintf(temp,"%d",m);
    len = strlen(temp);
    for(i = 1; i <= len; i++)
    {
        if(len % i)continue;
        flag = 0;
        for(j = 0; j < i; j++)
        {
            k = j;
            while(k+i < len)
            {
                if(temp[k] != temp[k+i])flag = 1;
                k = k+i;
            }
        }
        if(flag == 0)return i;
    }
}
int main()
{
    freopen("out.txt","w",stdout);
    freopen("C-large.in","r",stdin);
    int i,j,k,l,m,t,a,b;
    int curnum;
    int cons,nlen ,len;
    scanf("%d", &t);
    for(i = 1; i <= t; i++)
    {
        cons = 0;
        scanf("%d%d",&a, &b);
        sprintf(min,"%d",a);
        sprintf(max,"%d",b);
        nlen = strlen(min);
        for(j = a;j <= b; j++)
        {
            len = factor(j);
            sprintf(cur,"%d",j);
            for(k = 1; k < len; k++)
            {
                curnum = 0;
                for(l = 0; l < nlen; l++)
                {
                    m = (k+l)%nlen;
                    curnum = curnum*10 + cur[m] - '0';
                }
                if(curnum <= b && curnum >= a && j < curnum)
                {
                        cons++;
                }
            }
        }
        printf("Case #%d: %d\n",i,cons);
    }
    return 0;
}
