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
ll N, K;

/*==================================================*/
/*function*/

/*==================================================*/

int main() {
    cin>>N>>K;

    ll sum = 0LL;
    //REP(b, K+1, N+1){
    for(ll b = K+1; b <= N; b++){
        ll tsum = 0LL;

        ll tmp = 1LL;
        if(K == 0) tmp = 0LL;

        tsum += ( N / ( max(0LL,(K-1)) +(b-K)+ /*((K-1 + 1) / 2)*/tmp ) ) * (b - K);

        ll t = N % ( max(0LL,(K-1)) +(b-K)+ /*((K-1 + 1) / 2)*/tmp );

        if(t <= max(0LL,(K-1))){

        }else if(max(0LL,(K-1)) < t && t <= max(0LL,(K-1)) +(b-K)){
            tsum += t - max(0LL,(K-1));
        }else{
            tsum += t;
        }

        sum += tsum;
    }

    cout<<sum<<endl;

    return 0;
}