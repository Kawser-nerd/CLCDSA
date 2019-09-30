#include<bits/stdc++.h>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define FZ(n) memset((n),0,sizeof(n))
#define FMO(n) memset((n),-1,sizeof(n))
#define MC(n,m) memcpy((n),(m),sizeof(n))
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define FOR(x,y) for(__typeof(y.begin())x=y.begin();x!=y.end();x++)
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
// Let's Fight!

const int MAXN = 1000101;
const int MAXC = 200;

int N;
string s;
int arr[MAXN];

int dp[MAXN][MAXC];
int f[MAXN][10];

void input()
{
  cin>>s;
}

void calc_f()
{
  for(int i=1; i<=9; i++)
    f[0][i] = -1;
  for(int i=1; i<=N; i++)
  {
    for(int j=1; j<=9; j++)
    {
      if(arr[i-1] == j)
        f[i][j] = i-1;
      else
        f[i][j] = f[i-1][j];
    }
  }
}

void calc_dp()
{
  for(int i=0; i<=N; i++)
    dp[i][0] = i;
  for(int j=1; j<MAXC; j++)
  {
    for(int i=0; i<=N; i++)
    {
      dp[i][j] = i;
      for(int k=1; k<=9; k++)
      {
        if(j<k) continue;
        int r = dp[i][j-k];
        int r2 = min(r+1, N);
        int l = f[r2][k];
        if(l < i) continue;
        dp[i][j] = max(dp[i][j], dp[l+1][j-k]);
      }
    }
  }
}

int main(int argc, char** argv)
{
  IOS;
  int T;
  cin>>T;
  int nT = atoi(argv[1]);
  for(int i=1; i<=nT; i++)
    input();
  N = s.size();
  for(int i=0; i<N; i++)
    arr[i] = (s[i] - '0');

  calc_f();
  calc_dp();

  int ans = 0;
  for(int i=1; i<MAXC; i++)
  {
    if(dp[0][i] == N)
    {
      ans = i;
      break;
    }
  }

  cout<<"Case #"<<nT<<": "<<ans<<endl;

	return 0;
}
