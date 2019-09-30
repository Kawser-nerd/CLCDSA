#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <utility>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <cmath>

#define rep(i,j,k) for(int i=(int)j;i<(int)k;i++)
#define itrep(i,x) for(auto i=(x).begin(); i!=(x).end();i++)
#define Sort(x) sort((x).begin(),(x).end())
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define vec vector
#define INF (int)1e9
#define INFL 1e18
#define MOD 1000000007
#define pb push_back
#define MP make_pair
#define PI 3.1415926535
typedef long long int ll;
typedef std::pair<int,int> P;
int D=1;
int dx[4]={0,1,0,-1},dy[4]={-1,0,1,0};

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> v(n),dp(1+n);
    rep(i,0,n){
        cin>>v[i];
    }
    dp[0]=0;
    dp[1]=abs(v[1]-v[0]);
    rep(i,2,n){
        dp[i]=min(dp[i-2]+abs(v[i]-v[i-2]),dp[i-1]+abs(v[i]-v[i-1]));

    }
    cout<<dp[n-1]<<endl;


    return 0;
}