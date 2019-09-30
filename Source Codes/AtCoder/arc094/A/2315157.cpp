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

int main() {
  int A[3];
  cin >> A[0] >> A[1] >> A[2];
  sort(A,A+3);

  int d1 = A[2]-A[1], d2 = A[2]-A[0];
  if (d1%2 == 0 && d2%2 == 0) {
    cout << d1/2 + d2/2 << endl;
  } else if (d1%2 == 1 && d2%2 == 1) {
    cout << (d1-1)/2 + (d2-1)/2 + 1 << endl;
  } else {
    if (d1%2 == 0) {
      cout << d1/2 + (d2+1)/2 + 1 << endl;
    } else {
      cout << (d1+1)/2 + d2/2 + 1 << endl;
    }
  }
}