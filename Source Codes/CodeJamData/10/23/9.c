#include <stdio.h>
int n,r[26],s,pos[26];
void search(int k),check(void);

int main(void)
{
    freopen("C.in","r",stdin);
    freopen("C.out","w",stdout);

    int t0,t_case;scanf("%d",&t_case);
    for (n=2;n<=25;++n)
        search(2);
    for (t0=1;t0<=t_case;++t0)
    {
        scanf("%d",&n);
        printf("Case #%d: %d\n",t0,r[n]%100003);
    }

    fclose(stdin);fclose(stdout);
    return 0;
}

void search(int k)
{
    if (k==n)
        check();
    else
    {
        pos[k]=-1;search(k+1);
        pos[k]=++s;search(k+1);--s;
    }
}

void check(void)
{
    int p=s+1;
    while (p)
    {
        p=pos[p];
        if (p<0)
            return;
    }
    ++r[n];
}
