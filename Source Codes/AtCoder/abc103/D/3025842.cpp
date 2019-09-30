#include<iostream>
#include<string>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<functional>
#include<utility>

#define REP(i,n) for(int i=0;i<n;i++)
#define ll long long int

using namespace std;

int to_int(string s) {
  return atoi(s.c_str());
}

pair<int, int> a[100000];


int main() {
  int m,n;
  cin >> n >> m;
  REP(i,m) {
    cin >> a[i].second >> a[i].first;
    if(a[i].second > a[i].first) {
      int tmp = a[i].second;
      a[i].second = a[i].first;
      a[i].first = tmp;
    }
  }

  sort(a, a+m);

  int ans = 1;
  int tmp = a[0].first;
  REP(i,m) {
    if(tmp <= a[i].second) {
      tmp = a[i].first;
      ans++;
    }
  }

  cout << ans << endl;
}