#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#define CK(N, A, B) (A <= N && N < B)
#define REP(i, a, b) for (int i = a; i < b; i++)
#define RREP(i, a, b) for (int i = (b - 1); a <= i; i--)
#define F first
#define S second
#define ll long long

const int INF = 1e9;
const long long LLINF = 1e18;

using namespace std;

int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};
int dy8[] = {0,1,1,1,0,-1,-1,-1};
int dx8[] = {1,1,0,-1,-1,-1,0,1};

/*==================================================*/
/*variable*/
ll N, M;
/*==================================================*/
/*function*/

/*==================================================*/

int main() {
    cin>>N>>M;

    if(N == 1 && M == 1){
        cout<<1<<endl;
        return 0;
    }

    ll ans = 0;

    ans += max(0LL, N - 2LL) * max(0LL, M - 2LL);

    if(N == 1){
        ans += max(0LL, M - 2LL);
    }
    if(M == 1){
        ans += max(0LL, N - 2LL);
    }


    cout<<ans<<endl;

    return 0;
}