#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int main() {
    int n;
    cin >> n;
    vector<vector<pair<int, long long int>>> graph(n);
    for(int i = 0; i < n - 1; i++)
    {
        int a, b;
        long long int c;
        cin >> a >> b >> c;
        graph[a - 1].push_back({b - 1, c});
        graph[b - 1].push_back({a - 1, c});
    }
    int q, k;
    cin >> q >> k;
    vector<pair<int, int>> query(q);
    for(int i = 0; i < q; i++)
    {
        int x, y;
        cin >> x >> y;
        query[i] = {x - 1, y - 1};
    }
    //?????????k????????????
    queue<int> queue1;
    queue1.push(k - 1);
    vector<bool> flags(n, false);
    vector<long long int> dists(n, 0);   //??
    flags[k - 1] = true;
    while(!queue1.empty())
    {
        int current = queue1.front();
        queue1.pop();
        for(int i = 0; i < graph[current].size(); i++)
        {
            pair<int, long long int> next = graph[current][i];
            if(!flags[next.first])
            {
                queue1.push(next.first);
                flags[next.first] = true;
                dists[next.first] = dists[current] + next.second;
            }
        }
    }
    for(auto e : query)
    {
        cout << dists[e.first] + dists[e.second] << endl;
    }
    return 0;
}