#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

const int oo=1000000;
struct node
{
    int nxt[26];
    bool flag;
} trie[3500000];
int num=521196;
int tot=1;
char s[10000];
int opt[10000][5];
int best[5];

void dfs(int dep,int t,int d,int cost,int flag)
{
    if (!d) return;
    if (dep==t)
    {
        if (trie[d].flag)
        {
            flag=max(flag,0);
            best[flag]=min(best[flag],cost);
        }
        return;
    }
    dfs(dep+1,t,trie[d].nxt[s[dep]-'a'],cost,flag-1);
    if (flag<=0)
    {
        for (int i=0;i<26;i++)
        if (trie[d].nxt[i])
        {
            dfs(dep+1,t,trie[d].nxt[i],cost+1,4);
        }
    }
}

void check(int pos,int l,int d)
{
    for (int i=0;i<5;i++) best[i]=oo;
    if (d>=l)
    {
        bool flag=1;
        int r=1;
        for (int i=0;i<l;i++)
        if (trie[r].nxt[s[pos+i]-'a']==0) flag=0;
        else r=trie[r].nxt[s[pos+i]-'a'];
        if (flag) flag=trie[r].flag;
        if (!flag) return;
        best[d-l]=0;
        return;
    }
    dfs(pos,pos+l,1,0,d);
}

int main()
{
    FILE *fin=fopen("garbled_email_dictionary.txt","r");
    char buf[1000];
    for (int i=0;i<num;i++)
    {
        fscanf(fin,"%s",buf);
        int d=1;
        for (int i=0;buf[i];i++)
        {
            if (!trie[d].nxt[buf[i]-'a'])
                trie[d].nxt[buf[i]-'a']=++tot;
            d=trie[d].nxt[buf[i]-'a'];
        }
        trie[d].flag=1;
    }

    int t,id;
    scanf("%d",&t);
    for (int id=1;id<=t;id++)
    {
        scanf("%s",s+1);
        int n=strlen(s+1);

        for (int i=0;i<=n;i++)
        for (int j=0;j<5;j++)
            opt[i][j]=oo;
        opt[0][0]=0;
        for (int i=0;i<n;i++)
        for (int k=0;k<5;k++)
        if (opt[i][k]<oo)
        for (int j=i+1;j<=n && j-i<=10;j++)
        {
            check(i+1,j-i,k);
            for (int d=0;d<5;d++)
                opt[j][d]=min(opt[j][d],opt[i][k]+best[d]);
        }

        int res=oo;
        for (int i=0;i<5;i++) res=min(res,opt[n][i]);
        printf("Case #%d: %d\n",id,res);
    }
}
