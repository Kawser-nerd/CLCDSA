#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 604;
int K, N;
int oinit[MAXN];
int init[MAXN], backt[MAXN], out[MAXN];
int par[MAXN];
bool used[MAXN];
vector<int> redge[MAXN], ledge[MAXN], oredge[MAXN], oledge[MAXN];

int sim[MAXN];

void dfs(int v)
{
    if(v<0)
    {
        int i = -v;
        while(!redge[i].empty())
        {
            int ch = redge[i].back();
            redge[i].pop_back();
            dfs(ch);
        }
    }
    else
    {
        while(!ledge[v].empty())
        {
            int ch = ledge[v].back();
            ledge[v].pop_back();
            backt[ch]++;
            dfs(-ch);
        }
    }
}

bool test()
{
    for(int i=0; i<=200; i++)
    {
        out[i] = 0;
        redge[i].clear();
        backt[i] = 0;
    }

    for(int i=0; i<N; i++)
    {
        if(!used[i])
        {
            redge[par[i]].push_back(i);
            out[par[i]]++;
            ledge[i] = oledge[i];
        }
    }
    
    for(int i=1; i<=200; i++)
    {
        if(init[i]>0)dfs(-i);
    }

    for(int i=1; i<=200; i++)
    {
        if(out[i] || init[i])
        {
            int tot = init[i]+backt[i]-out[i];
            if(tot<0)return false;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);

    int T;
    cin>>T;
    for(int t=1; t<=T; t++)
    {
        cout<<"Case #"<<t<<": ";
        cin>>K>>N;

        for(int i=0; i<=200; i++)
        {
            oledge[i].clear();
            init[i] = 0;
            oinit[i] = 0;
            used[i] = false;
        }

        for(int i=0; i<K; i++)
        {
            int x;
            cin>>x;
            oinit[x]++;
            init[x]++;
        }
        for(int i=0; i<N; i++)
        {
            int q;
            cin>>q;
            par[i] = q;
            int n;
            cin>>n;
            for(int j=0; j<n; j++)
            {
                int x;
                cin>>x;
                oledge[i].push_back(x);
            }
        }
        if(!test())
        {
            cout<<"IMPOSSIBLE"<<endl;
            continue;
        }

        vector<int> nowuse;
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                if(used[j])continue;
                if(init[par[j]]<=0)continue;

                used[j] = true;
                init[par[j]]--;
                for(int k=0; k<(int)oledge[j].size(); k++)init[oledge[j][k]]++;
                
                if(test())
                {
                    nowuse.push_back(j);
                    break;
                }

                used[j] = false;
                init[par[j]]++;
                for(int k=0; k<(int)oledge[j].size(); k++)init[oledge[j][k]]--;

                if(j==N-1)cout<<"QQQQQQQQQQ "<<i+1<<endl;
            }
        }
        if((int)nowuse.size() != N)cout<<"RRRRRRRRRRRRRRRRRR"<<endl;

        for(int i=0; i<(int)nowuse.size(); i++)
        {
            cout<<nowuse[i]+1<<(i==(int)nowuse.size()-1 ? "\n" : " ");
        }

        for(int i=0; i<N; i++)
        {
            int ch = nowuse[i];
            int p = par[ch];
            if(oinit[p]<=0)cout<<"TTTTTTTTTTTTTTTTTTTTT"<<endl;
            oinit[p]--;
            for(int j=0; j<(int)oledge[ch].size(); j++)
            {
                oinit[oledge[ch][j]]++;
            }
        }
        
    }

    return 0;
}
