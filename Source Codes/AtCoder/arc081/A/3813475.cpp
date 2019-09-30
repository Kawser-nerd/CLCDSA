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

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;cin>>N;
  vll A(N);
  repeat(i,N){
    cin>>A[i];
  }
  sort(A.begin(),A.end(),greater<ll>());
  ll ans = 0;
  repeat(i,N-1){
    if(A[i]==A[i+1]){
      for(int j=i+2;j<N-1;j++){
        if(A[j]==A[j+1]){
          ans = A[i]*A[j];
          break;
        }
      }
      break;
    }
  }
  cout << ans << endl;
  return 0;
}