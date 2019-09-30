#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <functional>
using namespace std;

#define Rep(b, e, i) for(int i = b; i <= e; i++)
#define rep(n, i) Rep(0, n-1, i)
#define INF (long)1e10
#define MAX 50
typedef long long ll;
typedef pair<ll, ll> P;
typedef std::priority_queue<int> IntPrioQueue; //Z->A
typedef std::priority_queue<int, std::vector<int>, std::greater<int> > IntReversePrioQueue; //A->Z


int dx4[4]={1,0,-1,0};
int dy4[4]={0,1,0,-1};
int dx8[8]={1,0,-1,1,-1,1,0,-1};
int dy8[8]={1,1,1,0,0,-1,-1,-1};

void solve(void){
    int n, m;
    cin >> n >> m;
    P students[MAX];
    P checkpoints[MAX];
    rep(n, i) scanf("%lld%lld\n", &students[i].first, &students[i].second);
    rep(m, i) scanf("%lld%lld\n", &checkpoints[i].first, &checkpoints[i].second);
    rep(n, i){
        ll man_len_min = INF;
        int index = 0;
        rep(m, j) {
            ll man_len = abs(checkpoints[j].first - students[i].first) + abs(checkpoints[j].second - students[i].second);
            if (man_len_min > man_len) {
                man_len_min = man_len;
                index = j;
            }
        }
        cout << index+1 << '\n';
    }
}

int main(void){
  solve();
  return 0;
}