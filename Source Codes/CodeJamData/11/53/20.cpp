#include<algorithm>
#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
using namespace std;

int n , m , N;
vector <int> to[10001];
vector <int> from[10001];
int deg[10001]; // arrive
bool bad;
int queue[1000001] , now , z;
bool inQ[10001];
bool v[10001];
long long MOD = 1000003LL;

int trans(int x , int y)
{
    return (x - 1) * m + (y - 1);
}

void addedge(int x1 , int y1 , int x2 , int y2)
{
    if(x2 > n)
        x2 = 1;
    if(x2 < 1)
        x2 = n;
    if(y2 > m)
        y2 = 1;
    if(y2 < 1)
        y2 = m;
    int A = trans(x1 , y1);
    int B = trans(x2 , y2);
    to[A].push_back(B);
    from[B].push_back(A);
    deg[B]++;
}

void dfs(int C)
{
    int cur = to[C][0];
    for(int i = 0 ; i < from[cur].size(); i ++)
    {
        int t = from[cur][i];
        if(t > -1)
            if(!v[t])
            {
                v[t] = true;
                dfs(t);
            }
    }
    cur = to[C][1];
    for(int i = 0 ; i < from[cur].size(); i ++)
    {
        int t = from[cur][i];
        if(t > -1)
            if(!v[t])
            {
                v[t] = true;
                dfs(t);
            }
    }
}

void solve()
{
    memset(v , 0 , sizeof(v));
    bad = false;
    cin >> n >> m;
    N = n * m;
    for(int i = 0 ; i < N ; i++)
        to[i].clear() , from[i].clear() , deg[i] = 0;
    for(int i = 1 ; i <= n ; i++)
    {
        string s;
        cin >> s;
        s = "x" + s;
        for(int j = 1 ; j <= m ; j++)
        {
            if(s[j] == '-')
            {
                addedge(i , j , i , j + 1);
                addedge(i , j , i , j - 1);
            }
            else if(s[j] == '|')
            {
                addedge(i , j , i + 1 , j);
                addedge(i , j , i - 1 , j);
            }
            else if(s[j] == '\\')
            {
                addedge(i , j , i + 1 , j + 1);
                addedge(i , j , i - 1 , j - 1);
            }
            else if(s[j] == '/')
            {
                addedge(i , j , i - 1 , j + 1);
                addedge(i , j , i + 1 , j - 1);
            }
        }
        
    }
    now = 1;
    z = 0;
    memset(inQ , 0 , sizeof(inQ));
    
    for(int i = 0 ; i < N ; i++)
    {
        if(deg[i] == 0)
        {
            bad = true;
            break;
        }
        if(deg[i] == 1)
        {
            queue[++z] = i;
            inQ[i] = true;
        }
    }
    if(!bad)
    {
        while(now <= z && bad == false)
        {
            int s = queue[now];
            int lef = -1;
            for(int i = 0 ; i < from[s].size() ; i++)
                lef = max(lef , from[s][i]);
           

            if(lef >= 0)
            {
                //cout << lef << " -> " << s << endl;
            deg[s] --;
            v[lef] = true;
            for(int i = 0 ; i < 2 ; i++)
                if(to[lef][i] != s)
                {
                    int u = to[lef][i];
                    deg[u] --;
                    //cout <<"--"<< u << endl;
                    for(int j = 0 ; j < from[u].size() ; j++)
                        if(from[u][j] == lef)
                            from[u][j] = -1;
                    if(deg[u] == 0)
                        bad = true;
                    else if(deg[u] == 1)
                    {
                        if(!inQ[u])
                        {
                            inQ[u] = true;
                            queue[++z] = u;
                            //cout << "inQ " << u << endl;
                        }
                    }
                }
            }
            inQ[s] = false;
            ++now;
        }
    }
    if(!bad)
    {
        long long ans = 1;

        for(int i = 0 ; i < N ; i++)
            if(!v[i])
            {
                v[i] = true;
                dfs(i);
                ans *= 2;
                ans %= MOD;
            }
        cout << ans << endl;
    }
    if(bad)
        cout << 0 << endl;
}

int main()
{
    freopen("in.txt" , "r" , stdin);
    freopen("out.txt" , "w" , stdout);
    int TestCase;
    cin >> TestCase;
    for(int CaseID = 1 ; CaseID <= TestCase ; CaseID ++)
    {
        cout << "Case #" << CaseID << ": ";
        solve();
    }
    //system("pause");
    return 0;
}
