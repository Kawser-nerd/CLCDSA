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
int N;
ll A[100010];
vector<int> pv;
vector<int> nv;

map<int, int> md;

/*==================================================*/
/*function*/

/*==================================================*/

int main(){
    cin>>N;
    ll sum = 0;
    REP(i,0,N){
        cin>>A[i];
        if(i == 0) sum += abs(A[i] - 0);
        if(i > 0 && i < N-1) sum += abs(A[i] - A[i-1]);
        if(i == N-1) sum += abs(A[i] - A[i-1]) + abs(A[i] - 0);
    }


    REP(i,0,N){
        ll ans;
        if(i == 0){
            ans = sum - abs(A[i] - 0) - abs(A[i] - A[i+1]) + abs(0 - A[i+1]);
        }
        if(i > 0 && i < N-1){
            ans = sum - abs(A[i] - A[i-1]) - abs(A[i] - A[i+1]) + abs(A[i-1] - A[i+1]);
        }
        if(i == N-1){
            ans = sum - abs(A[i] - A[i-1]) - abs(A[i] - 0) + abs(A[i-1] - 0);
        }

        cout<<ans<<endl;
    }
}