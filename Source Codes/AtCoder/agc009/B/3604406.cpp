#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>

using namespace std;

class Node
{  
public:
    int p;
    vector<int> vec;
};

int dp[100005];
Node node[100005];

int rec(int v)
{
    if(node[v].vec.size() == 0)
    {
        return 0;
    }

    if(dp[v] != -1)
    {
        return dp[v];
    }

    vector<int> vec;
    for (int i = 0; i < node[v].vec.size();i++)
    {
        vec.push_back(rec(node[v].vec[i]));
    }
    sort(vec.begin(), vec.end(), greater<int>());
    int ret = -1;
    for (int i = 1; i <= node[v].vec.size(); i++)
    {
        ret = max(ret, i + vec[i - 1]);
    }
    return dp[v] = ret;
}

int main()
{
    long long N;
    long long a[100005];

    cin >> N;

    for (int i = 1; i <= N;i++)
    {
        dp[i] = -1;
    }

    node[1].p = 1;
    for (int i = 2; i <= N; i++)
    {
        int a;
        cin >> a;
        node[i].p = a;
        node[a].vec.push_back(i);
    }

    cout << rec(1) << endl;
    return 0;
}