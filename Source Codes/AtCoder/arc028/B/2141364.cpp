#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <iomanip>

#define int long long int
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

signed main(){
    int n, k;
    cin >> n >> k;

    priority_queue<P> que;
    for(int i = 1; i <= n; i++){
        int h;
        cin >> h;
        que.push(make_pair(h, i));
        if(i < k){
            continue;
        }
        if((int)que.size() > k){
            que.pop();
        }
        cout << que.top().second << endl;
    }
    return 0;
}