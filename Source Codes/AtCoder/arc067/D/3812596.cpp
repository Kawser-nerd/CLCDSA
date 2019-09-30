#include <iostream>
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <limits.h>
#include <math.h>
#include <functional>
#include <bitset>
#include <iomanip>
#include <cassert>

#define repeat(i,n) for (long long i = 0; (i) < (n); ++ (i))
#define debug(x) cerr << #x << ": " << x << '\n'
#define debugArray(x,n) for(long long i = 0; (i) < (n); ++ (i)) cerr << #x << "[" << i << "]: " << x[i] << '\n'
#define debugArrayP(x,n) for(long long i = 0; (i) < (n); ++ (i)) cerr << #x << "[" << i << "]: " << x[i].first<< " " << x[i].second << '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> Pii;
typedef vector<int> vint;
typedef vector<ll> vll;
const ll INF = INT_MAX;
const ll MOD = 1e9+7;

ll A[5*1010];
ll B[5*1010][210];
int N,M;
ll mB[210];
int main(){
  cin>>N>>M;
  repeat(i,N-1){
    scanf("%lld",&A[i+1]);
    A[i+1]+=A[i];
  }
  repeat(i,N){
    repeat(j,M){
      scanf("%lld",&B[i][j]);
    }
  }
  ll ans = 0;
  repeat(l,N){
    repeat(j,M)mB[j]=0;
    ll sum=0;
    for(ll r=l;r<N;r++){
      repeat(j,M){
        if(mB[j]<B[r][j]){
          sum += -mB[j]+B[r][j];
          mB[j]=B[r][j];
        }
      }
      ans = max(ans,sum-(A[r]-A[l]));
    }
  }
  cout << ans << endl;
  return 0;
}