#include <iostream>
#include <sstream>
#include <fstream>

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>

#include <algorithm>
#include <numeric>
#include <functional>
#include <string>
#include <vector>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <map>
// #include <unordered_map>
#include <set>
#include <utility>
#include <bitset>
#include <limits>
#include <climits>
using namespace std;

#ifdef DEBUG
#define NDEBUG
#include "cout11.h"
#endif
#undef NDEBUG
#include <cassert>

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef pair<ll,ll> llll;
typedef pair<double,double> dd;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;
typedef vector<vector<ii>> vvii;
typedef vector<ll> vll;

#define sz(a)  int((a).size())
#define pb  push_back
#define FOR(var,from,to) for(int var=(from);var<=(to);++var)
#define rep(var,n)  for(int var=0;var<(n);++var)
#define rep1(var,n)  for(int var=1;var<=(n);++var)
#define repC2(vari,varj,n)  for(int vari=0;vari<(n)-1;++vari)for(int varj=vari+1;varj<(n);++varj)
#define ALL(c)  (c).begin(),(c).end()
#define tr(i,c)  for(auto i=(c).begin(); i!=(c).end(); ++i)
#define found(s,e)  ((s).find(e)!=(s).end())
#define mset(arr,val)  memset(arr,val,sizeof(arr))
#define mid(x,y) ((x)+((y)-(x))/2)
#define IN(x,a,b) ((a)<=(x)&&(x)<=(b))

int solve(int K) {
    priority_queue<ii> pq;

    vector<int> vis(K, 0);

    pq.push(ii(-1, 1));
    while (!pq.empty()) {
        ii p = pq.top(); pq.pop();
        int cnt = -p.first, curr = p.second;
        if (curr == 0) return cnt;

        vis[curr] = 1;
        int next = (curr + 1)% K;
        if (vis[next] == 0)
            pq.push(ii(-(cnt+1), next));

        next = (curr * 10) % K;
        if (vis[next] == 0)
            pq.push(ii(-cnt, next));
    }
}

int main() {

    int K; cin >> K;

    cout << solve(K) << endl;
    return 0;
} ./Main.cpp:81:1: warning: control may reach end of non-void function [-Wreturn-type]
}
^
1 warning generated.