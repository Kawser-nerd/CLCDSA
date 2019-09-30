#include<iostream>
#include<string>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<functional>
#include<cmath>
#include<unordered_map>

#define REP(i,n) for(int i=0;i<n;i++)
#define ll long long int

using namespace std;

int to_int(string s) {
  return atoi(s.c_str());
}

int a[100000];
ll sum[100001];

int main() {
  int m,n;
  cin >> n >> m;
  REP(i,n) cin >> a[i];
  unordered_map<int,int> mp;
  sum[0] = 0;
  mp[0] = 1;

  REP(i,n) {
    sum[i+1] = sum[i] + a[i];
    mp[sum[i+1]%m] += 1;
  }

  ll r = 0;
  REP(i,n+1) {
    ll tmp = mp[sum[i]%m];
    r += tmp*(tmp -1)/2;
    mp[sum[i]%m] = 0;
  }

  cout << r << endl;




}