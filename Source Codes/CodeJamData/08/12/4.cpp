/*
TASK: B-milkshake
LANG: C++
*/

#include<stdio.h>
#include<stdlib.h>
#include<vector>

using namespace std;

vector<int> nodoka[3000];
FILE *fin,*fout;
int n,m;
int t[3000],ma[3000];
int now[3000];
int CantDo;

void fixi(int x)
{
    printf("%d ",x);
    int i;
    if(ma[x]==-1) {CantDo = 1; return;}
    if(CantDo) return;
    if(now[ma[x]]==1) return;
    now[ma[x]] = 1;
    i = ma[x];
    vector<int>::iterator itr;
    for(itr = nodoka[i].begin(); itr!=nodoka[i].end(); itr++)
    {
        t[*itr]--;
        if(t[*itr]==0) fixi(*itr);
        if(CantDo) return;
    }
}

int main()
{
    int ss,sss;
    int i,j,a,b;
    fin = fopen("B-large.in","r");
    fout = fopen("B-large.out","w");
    fscanf(fin,"%d",&sss);
    for(ss=1;ss<=sss;ss++)
    {
        printf("--%d--\n",ss);
        for(i=0;i<3000;i++) {nodoka[i].clear(); now[i] = 0; CantDo = 0;}
        fscanf(fin,"%d",&n);
        fscanf(fin,"%d",&m);
        for(i=0;i<m;i++)
        {
            fscanf(fin,"%d",&t[i]);
            ma[i] = -1;
            for(j=0;j<t[i];j++)
            {
                fscanf(fin,"%d %d",&a,&b);
                if(b==1) ma[i] = a; else nodoka[a].push_back(i);
            }
            if(ma[i]!=-1) t[i]--;
        }
        int ping = 0;
        do
        {
            ping = 0;
            for(i=0;i<m;i++)
            {
                if(CantDo) break;
                if(t[i]==0 && ma[i]!=-1 && now[ma[i]]!=1)
                {
                    fixi(i);
                    ping = 1;
                }
            }
            if(CantDo) break;
            //printf("F");
        } while(ping);
        if(CantDo) fprintf(fout,"Case #%d: IMPOSSIBLE\n",ss);
        else
        {
            fprintf(fout,"Case #%d:",ss);
            for(i=1;i<=n;i++) fprintf(fout," %d",now[i]);
            fprintf(fout,"\n");
        }
    }
    system("PAUSE");
    return 0;
}
