#include <iostream>
#include <climits>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#define INF_INT (INT_MAX / 2)
#define INF_LONG (LONG_MAX / 2)
//#define DEBUG true
#define DEBUG false
#define MAX_N 100000
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  int r[n], h[n];
  for(int i = 0; i < n; i++){
    cin >> r[i] >> h[i];
  }

  int hand[MAX_N + 1][4];
  for(int i = 0; i <= MAX_N; i++){
    fill(hand[i], hand[i] + 4, 0);
  }
  int rate[MAX_N];
  fill(rate, rate + MAX_N, 0);
  for(int i = 0; i < n; i++){
    hand[r[i]][h[i]]++;
    rate[r[i]]++;
  }

  pair< int, int > ps[MAX_N];
  for(int i = 0; i < n; i++){
    ps[i] = make_pair(r[i], h[i]);
  }
  sort(ps, ps + n);

  tuple< int, int, int > ans[MAX_N + 1][4];
  int sum = 0, count = 0;
  for(int i = 0; i < n; i++){
    int r = ps[i].first;
    int h = ps[i].second;
    int same = hand[r][h] - 1;
    if(i > 0 && ps[i - 1].first != r){
      sum += count;
      count = 0;
    }
    int win = sum;
    if(h == 1){
      win += hand[r][2];
    }
    else if(h == 2){
      win += hand[r][3];
    }
    else if(h == 3){
      win += hand[r][1];
    }
    int lose = (n - 1) - (same + win);
    ans[r][h] = make_tuple(win, lose, same);
    ++count;
  }

  string s;
  for(int i = 0; i < n; i++){
    s += to_string(get< 0 >(ans[r[i]][h[i]]));
    s += " " + to_string(get< 1 >(ans[r[i]][h[i]]));
    s += " " + to_string(get< 2 >(ans[r[i]][h[i]]));
    s += "\n";
  }

  cout << s;

  return 0;
}