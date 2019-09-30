#include <algorithm>
#include <cassert>
#include <cfloat>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
 
#define FOR(i,k,n) for (int (i)=(k); (i)<(n); ++(i))
#define rep(i,n) FOR(i,0,n)
#define all(v) begin(v), end(v)
#define debug(x) cerr<< #x <<": "<<x<<endl
#define debug2(x,y) cerr<< #x <<": "<< x <<", "<< #y <<": "<< y <<endl
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;
typedef vector<vector<ll> > vvll;
typedef deque<bool> db;
template<class T> using vv=vector<vector< T > >;

int n, k;
string s;
int cnt;

deque<int> ar;
bool top_is_a;
void print_ans() {
  int ab = (top_is_a) ? 0 : 1;
  int m = (int)ar.size();
  rep (i, m) {
    char c = 'A' + ((i + ab) % 2);
    rep (j, ar[i]) {
      printf("%c", c);
    }
  }
  printf("\n");
  exit(0);
}

void manipulate() {
  if (top_is_a) {
    if (ar[0] > 1) {
      ar[0] -= 1;
      ar.push_front(1);
    } else {
      ar.pop_front();
      ar[0] += 1;
    }
    top_is_a = false;
  } else {
    if ((int)ar.size() % 2 == 1) { // tail is 'B'
      if (ar[0] > 1) {
        ar[0] -= 1;
        ar.back() += 1;
        top_is_a = true;
      } else {
        ar.pop_front();
        ar.back() += 1;
      }
      return;
    }
    if (ar[0] > 1) {
      ar[0] -= 1;
      ar.push_back(1);
      top_is_a = true;
    } else {
      ar.pop_front();
      ar.push_back(1);
    }
  }
}

int main() {
  cin >> n >> k;
  cin >> s;
  {
    int ind = 0;
    rep (i, n) {
      if (s[i] != s[ind]) {
        ar.push_back(i - ind);
        ind = i;
      }
    }
    ar.push_back(n - ind);
  }
  top_is_a = (s[0] == 'A');
  cnt = 0;
  while (cnt < k) {
    if (n % 2 == 0) {
      if ((!top_is_a) && (int)ar.size() == n) {
        print_ans();
      }
    } else {
      if (top_is_a && (int)ar.size() == n) {
        if ((k - cnt) % 2 == 1) {
          manipulate();
        }
        print_ans();
      }
    }

    cnt += 1;
    manipulate();
  }
  print_ans();

  return 0;
}