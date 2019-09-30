#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
char exist[100000][100+10],wait[100+10];

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("a1.out","w",stdout);

    int t,n,m,ans;
    int i,j,k,ii;
    int len,flag;
    char temp[100+10];
    scanf("%d",&t);
    for (i=1;i<=t;i++)
    {
        scanf("%d%d",&n,&m); getchar();
        for (j=1;j<=n;j++) fgets(exist[j],sizeof(exist[j]),stdin);
        for (j=1;j<=n;j++) exist[j][strlen(exist[j])-1]='\0';
        ans=0;
        for (j=1;j<=m;j++) 
        {
            fgets(wait,sizeof(wait),stdin);
            len=strlen(wait)-1;
            k=1;
            temp[0]=wait[0];
            while (k<=len-1)
            {
                temp[k]=wait[k];
                if (wait[k+1]=='/')
                {
                    flag=0;
                    temp[k+1]='\0';
                    for (ii=1;ii<=n;ii++) if (strcmp(exist[ii],temp)==0) { flag=1; break; }
                    if (!flag) 
                    {
                        n++;
                        strcpy(exist[n],temp);
                        ans++;
                    }
                }
                k++;
            }
            flag=0;
            temp[k]='\0';
            for (ii=1;ii<=n;ii++) if (strcmp(exist[ii],temp)==0) { flag=1; break; }
            if (!flag) 
            {
                n++;
                strcpy(exist[n],temp);
                ans++;
            }
        }
        printf("Case #%d: %d\n",i,ans);
    }
    return 0;
}
