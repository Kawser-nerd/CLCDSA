#include <string>
#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

vector<vector<pair<int, pair<int, int> > > > v;
vector<int> vstep;
vector<int> eused;
set<pair<int, int> > s;
int n, m;
int ecnt;

bool dfs(int cur, int cnt)
{
    if(ecnt == m)
    {
        return true;
    }
    bool flag = false;
    vstep[cur] = cnt;
    for (int i = 0; i < v[cur].size();i++)
    {
        int to = v[cur][i].first;
        int col = v[cur][i].second.first;
        int num = v[cur][i].second.second;

        if (eused[num] != -1)
        {
            continue;
        }
        if(cnt % 2 != col)
        {
            if (vstep[to] != -1 && (cnt - vstep[to]) % 2 == 0)
            {
                return true;
            }
            eused[num] = 1;
            ecnt++;
            if(dfs(to, cnt + 1) == true)
            {
                return true;
            }
        }
    }
    return false;
}

int main(){
    cin >> n >> m;
    v.resize(n);
    vstep.resize(n);
    eused.resize(m);
    for (int i = 0; i < m;i++)
    {
        int a, b, c;
        string ct;
        cin >> a >> b >> ct;
        a--;
        b--;
        c = ct[0] == 'r' ? 1 : 0;
        v[a].push_back(make_pair(b, make_pair(c, i)));
        v[b].push_back(make_pair(a, make_pair(c, i)));
    }
    for (int i = 0; i < n; i++)
    {
        fill(vstep.begin(), vstep.end(), -1);
        fill(eused.begin(), eused.end(), -1);
        ecnt = 0;
        if(dfs(i, 0))
        {
            cout << "Yes" << endl;
            return 0;
        }
        fill(vstep.begin(), vstep.end(), -1);
        fill(eused.begin(), eused.end(), -1);
        ecnt = 0;
        if (dfs(i, 1))
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;

    return 0;
}