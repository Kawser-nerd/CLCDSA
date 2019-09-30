#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

#define pb push_back
#define all(v) begin(v), end(v)
#define debug(x) cerr<< #x <<": "<<x<<endl
#define debug2(x,y) cerr<< #x <<": "<< x <<", "<< #y <<": "<< y <<endl

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<i_i, int> p_i;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
template<class T> using vv=vector<vector< T > >;

int main() {
  double p;
  cin >> p;

  double a = 0.6299605249474366;
  double loga = 0.46209812037329684;
  if (p * loga < 1.0) {
    printf("%f\n", p);
    return 0;
  }

  double b = 1.0 / p / loga;
  double x = log2(b) * (-1.5);
  printf("%.8f\n", (x + 1 / loga));

  return 0;
}