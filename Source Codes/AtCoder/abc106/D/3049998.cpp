#include<iostream>
#include<string>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<functional>
#include<cmath>
#include<unordered_map>
#include<utility>

#define REP(i,n) for(int i=0;i<n;i++)
#define ll long long int

using namespace std;

int to_int(string s) {
  return atoi(s.c_str());
}

int map[500][500];
int p[100000];
int q[100000];

int main() {
  int m,n,Q;
  cin >> n >> m >> Q;
  REP(i,m) {
    int x,y;
    cin >> x >> y;
    for(int j = y-1; j < n; j++) {
      map[x-1][j]++;
    }
  }
  REP(i,Q) cin >> p[i] >> q[i];
  REP(i,Q) {
    int ans = 0;
    for(int j = p[i] - 1; j < q[i]; j++) {
      if(p[i] == 1) {
        ans += map[j][q[i] - 1];
      } else {
        ans += map[j][q[i] - 1] - map[j][p[i] - 2];
      }
    }
    cout << ans << endl;
  }
}