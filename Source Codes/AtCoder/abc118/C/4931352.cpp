#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define REP(i, n)  FOR(i, 0, n)
#define ASC(c) sort((c).begin(), (c).end())
#define DESC(c) sort((c).begin(), (c).end(), greater<int>())

#define DUMP(x)  cerr << #x << " = " << (x) << endl;
#define DEBUG(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

typedef long long ll;
typedef unsigned long long ull;
struct edge { int u, v; ll w; };
 
ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;


int gcd(int a, int b) {
  if (b == 0) return a;
  else return gcd(b, a % b);
}

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i, n) cin >> a[i];
  int g = gcd(a[0], a[1]);
  FOR(i, 2, n) {
    if (g > a[i]) g = gcd(g, a[i]);
    else g = gcd(a[i], g);
  }
  cout << g << endl;
}