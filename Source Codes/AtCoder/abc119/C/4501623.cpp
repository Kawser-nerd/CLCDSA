#include <iostream>
#include <climits>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <deque>
#define INF_INT (INT_MAX / 2)
#define INF_LONG (LONG_MAX / 2)
//#define DEBUG true
#define DEBUG false
#define MAX_N 8
using namespace std;

const int MAX = 100001;
const int MOD = 1000000007;

typedef long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;
typedef pair< ll, int > pli;
typedef pair< int, ll > pil;

int ceil(int x, int y){
  return (x % y == 0) ? x / y : x / y + 1;
}

int gcd(int x, int y){
  return y ? gcd(y, x % y) : x;
}

int lcm(int x, int y){
  return x / gcd(x, y) * y;
}

int best = INF_INT;
int t[MAX_N];

void search(int i, int l[], int a, int b, int c, int n){
  if(i == n){
    bool found_a = false, found_b = false, found_c = false;
    int sum_a = 0, sum_b = 0, sum_c = 0;
    int count_a = 0, count_b = 0, count_c = 0;
    for(int j = 0; j < n; j++){
      switch(t[j]){
        case 1:
          found_a = true;
          ++count_a;
          sum_a += l[j];
          break;
        case 2:
          found_b = true;
          ++count_b;
          sum_b += l[j];
          break;
        case 3:
          found_c = true;
          ++count_c;
          sum_c += l[j];
          break;
      }
    }
    if(found_a && found_b && found_c){
      int cost = 10 * (count_a - 1) + abs(a - sum_a);
      cost += 10 * (count_b - 1) + abs(b - sum_b);
      cost += 10 * (count_c - 1) + abs(c - sum_c);
      best = min(best, cost);
    }
    return;
  }
  for(int j = 0; j < 4; j++){
    t[i] = j;
    search(i + 1, l, a, b, c, n);
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, a, b, c;
  cin >> n >> a >> b >> c;
  int l[n];
  for(int i = 0; i < n; i++){
    cin >> l[i];
  }

  search(0, l, a, b, c, n);

  cout << best << endl;

  return 0;
}