#include<stdio.h>
#include<string.h>
#define min(a,b) ((a)<(b))?(a):(b)
#define INF 100000009
char s[150][150][41],a[150][41],b[150][41],*str;
char mark[150];
int main()
{
    int i,j,k,r,x,t,n,l,in,len,c;
    char flag;
    scanf("%d",&t);
    for(x=1;x<=t;x++)
    {
        scanf("%d%d",&n,&l);
        for(i=0;i<n;i++)
            scanf("%s",a[i]);
        for(i=0;i<n;i++)
            scanf("%s",b[i]);
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                in=0;
                for(k=0;k<l;k++)
                if(a[i][k]!=b[j][k])
                    s[i][j][in++]=k+1;
                s[i][j][in]='\0';
                //for(r=0;r<in;r++)
                //printf("%d",s[i][j][r]);
                //printf("\n");
            }
        }
        len=INF;
        for(i=0;i<n;i++)
        {
            str=s[0][i];

            memset(mark,0,n);
            c=0;
            for(j=0;j<n;j++)
            {
                flag=0;

                for(k=0;k<n;k++)
                {
                    if(!strcmp(s[j][k],str) && !mark[k])
                    {
                        flag=1;
                        mark[k]=1;
                        c++;
                        break;
                    }
                }
                //printf("%d\n",c);
                if(!flag)
                    break;
            }
            if(c==n)
            {
                r=strlen(str);
                //printf("m%d\n",min(len,r));
                len=min(len,r);
            }
        }
        printf("Case #%d: ",x);
        if(len==INF)
            printf("NOT POSSIBLE\n");
        else
            printf("%d\n",len);
    }
    return 0;
}
