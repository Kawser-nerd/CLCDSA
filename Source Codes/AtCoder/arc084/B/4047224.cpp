#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <deque>
#include <iomanip>
#include <cstdio>
#include <stack>
#include <numeric>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)

ll dp[100010];

int main(){
    int k;
    cin >> k;
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
    pq.push(MP(1,1));
    while(!pq.empty()){
        auto xxx = pq.top();
        pq.pop();
        int x = xxx.first;
        int y = xxx.second;
        if(dp[y]==0){
            dp[y] = x;
            if(dp[10*y%k]==0){
                pq.push(MP(x,10*y%k));
            }
            if(dp[(y+1)%k]==0){
                pq.push(MP(x+1,(y+1)%k));
            }
        }
    }
    cout <<dp[0] << endl;
    return 0;
}