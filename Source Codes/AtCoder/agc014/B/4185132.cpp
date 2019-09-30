#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <queue>
#include <set>

using namespace std;

int N, M;
map<pair<int, int>, int> m;
vector<vector<int> > v;

int main()
{
    cin >> N >> M;
    v.resize(N);

    int s = N;

    for (int i = 0; i < M;i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        s = min(s, a);
        if (a > b)
        {
            swap(a, b);
        }
        v[a].push_back(b);
        v[b].push_back(a);
        m[make_pair(a, b)]++;
        
    }

    int cnt = 0;
    int start = s;
    int end;

    while(cnt < M)
    {
        bool flag = false;
        for (int i = 0;i <  v[s].size(); i++)
        {
            int t = v[s][i];
            int t1, t2;
            if(s > t)
            {
                t1 = t;
                t2 = s;
            }
            else
            {
                t1 = s;
                t2 = t;
            }
            auto e = make_pair(t1, t2);
            //cout << "t1:" << t1 << " t2:" << t2 << endl;
            if (m.find(e) == m.end())
            {
                continue;
            }
            if(m[e] == 0)
            {
                continue;
            }
            flag = true;
            //cout << s << "->" << t << endl;

            s = t;
            m[e]--;
            cnt++;
            break;
        }
        if(flag == false)
        {
            if(s == start)
            {
                s++;
                start = s;
            }
            else
            {
                break;
            }
        }
    }
    end = s;

    if(cnt == M && start == end)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}