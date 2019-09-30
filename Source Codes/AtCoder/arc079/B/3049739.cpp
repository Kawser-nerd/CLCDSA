#include<cstring>
#include<string>
#include<vector>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<list>
#include<set>
#include<map>
#include<complex>
#include<sstream>
#include<climits>

#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define fi first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll K;

int main() {
  cin >> K;
  
  int N = 50;
  cout << N << endl;
  for (int i = 0; i < N; ++i) {
    ll a = i;
    a += K/N;
    a -= K%N;
    if (i < K%N) a += N+1;
    printf("%lld%c", a, i+1 == N ? '\n' : ' ');
  }

  return 0;
}