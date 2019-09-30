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
#define rrep(X,Y) for (int (X) = (Y)-1;(X) >=0;--(X))
#define all(X) (X).begin(),(X).end()
#define pb push_back
#define mp make_pair
#define fi first
#define sc second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

ll N;
int ans[20000];

int main() {
  cin >> N;

  if (N == 3) {
    cout << "2 5 63" << endl;
    return 0;
  }
  
  if (N == 4) {
    cout << "2 5 20 63" << endl;
    return 0;
  }

  if (N == 5) {
    cout << "2 4 6 3 9" << endl;
    return 0;
  }

  int sum = 0;
  int d_sum = 0;
  for (int i = 0; i < N; ++i) {
    if (i%4 == 0) ans[i] = 6*(i/4)+2;
    else if (i%4 == 1) ans[i] = 6*(i/4)+3;
    else if (i%4 == 2) ans[i] = 6*(i/4)+4;
    else if (i%4 == 3) ans[i] = 6*(i/4)+6;
    sum = (sum + ans[i]) % 6;
  }

  if (sum == 0) {

  } else if (sum == 2) {
    ans[4] = 6*(N/4)+6;
  } else if (sum == 3) {
    ans[5] = 6*(N/4)+6;
  } else if (sum == 5) {
    ans[5] = 6*(N/4)+4;
  }

  for (int i = 0; i < N; ++i) printf("%d%c", ans[i], i+1 != N ? ' ' : '\n');

  return 0;
}