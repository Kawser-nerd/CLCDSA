#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <cmath>
#include <cassert>
#include <queue>
#include <bitset>
#include <map>
#include <set>
#include <unordered_map>

#define pb push_back
#define mp make_pair
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef long long int64;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef __int128 int128;

const int L = 20;
const int mod = 998244353;

int d[1 << (L + 1)];
map<int128, int> D;

int d0[1 << (L + 1)];
map<int128, int> D0;

int128 encode(const string& s) {
  int128 res = 0;
  for (int i = 0; i < sz(s); ++i)
    if (s[i] == '1') res |= (((int128) 1) << (int128) i);
  res |= (((int128) 1) << (int128) sz(s));
  return res;
}

int encode_short(const string& s) {
  int res = 0;
  for (int i = 0; i < sz(s); ++i)
    if (s[i] == '1') res |= (1 << i);
  res |= (1 << sz(s));
  return res;
}

int calc(string s);
int calc0(string s);

int calc(string s) {
  if (sz(s) == 1) return s[0] == '1' ? 2 : 1;
  int ikey;
  int128 lkey;
  if (sz(s) < L) {
    ikey = encode_short(s);
    if (d[ikey] != -1) return d[ikey];
  } else {
    lkey = encode(s);
    auto it = D.find(lkey);
    if (it != D.end())
      return it->second;
  }

  int res = calc0(s);
//  if (s == "0000") cerr << "step 0: " << res << "\n";
  for (int i = 1; i < sz(s); ++i) {
    int64 cur = (int64) calc0(s.substr(0, i)) * (int64) calc(s.substr(i));
//    if (s == "0000") cerr << "step " << i << ": " << cur << "\n";
//    if (s == "0000" && i == 2) cerr << calc0(s.substr(0, i)) << " " << calc(s.substr(i)) << "\n";
    res += (int) (cur % mod);
    res %= mod;
  }
//  cerr << s << " " << res << "\n";
  if (sz(s) < L) {
    d[ikey] = res;
  } else {
    D[lkey] = res;
  }
  return res;
}

int calc0(string s) {
  if (sz(s) == 1) return s[0] == '1' ? 2 : 1;
  int ikey;
  int128 lkey;
  if (sz(s) < L) {
    ikey = encode_short(s);
    if (d0[ikey] != -1) return d0[ikey];
  } else {
    lkey = encode(s);
    auto it = D0.find(lkey);
    if (it != D0.end())
      return it->second;
  }

  int res = 0;
  for (int i = 1; i < sz(s); ++i) if (sz(s) % i == 0) {
    string ns(i, '1');
    for (int j = 0; j < sz(s); ++j)
      if (s[j] == '0') ns[j % i] = '0';
    res += calc(ns);
    res %= mod;
  }

//  cerr << "0: " << s << " " << res << "\n";

  if (sz(s) < L) {
    d0[ikey] = res;
  } else {
    D0[lkey] = res;
  }
  return res;
}

int main() {
  memset(d, -1, sizeof(d));
  memset(d0, -1, sizeof(d0));
  string s;
  cin >> s;
  cout << calc(s) << "\n";
  return 0;
}