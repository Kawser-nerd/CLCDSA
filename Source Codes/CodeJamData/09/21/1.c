#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 10000
int l[MAX],r[MAX],flag[MAX],n,m;char f[MAX][15];double p[MAX];
void build(int k);double cal(int k);int check(int k);char f0[100][15];

int main(void)
{
    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);

    int t_case,i,j,t0,root=0,l0;char t;scanf("%d",&t_case);
    for (t0=1;t0<=t_case;++t0)
    {
        scanf("%d ",&l0);n=0;
        while ((t=getchar())!='(');
        build(0);scanf("%d",&n);
        printf("Case #%d:\n",t0);
        for (i=0;i<n;++i)
        {
            scanf("%*s %d",&m);
            for (j=0;j<m;++j)
                scanf("%s",f0[j]);
            printf("%.7f\n",cal(root));
        }
    }

    fclose(stdin);fclose(stdout);
    return 0;
}

void build(int k)
{
    char t;int i=0;scanf(" %lf ",&p[k]);
    if ((f[k][i]=getchar())==')')
    {
        flag[k]=0;return;
    }
    ++i;
    while (isalpha(f[k][i]=getchar()))
        ++i;
    f[k][i]='\0';
    flag[k]=1;
    ++n;while ((t=getchar())!='(');l[k]=n;build(n);
    ++n;while ((t=getchar())!='(');r[k]=n;build(n);
    scanf(" ) ");
}

double cal(int k)
{
    if (!flag[k]) return p[k];
    if (check(k))
        return p[k]*cal(l[k]);
    else
        return p[k]*cal(r[k]);
}

int check(int k)
{
    int i;
    for (i=0;i<m;++i)
        if (strcmp(f[k],f0[i])==0)
            return 1;
    return 0;
}
