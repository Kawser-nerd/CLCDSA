#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for(int i=0;i<n;i++)
#define foreach(v,c) for(typeof(c.begin()) v=c.begin();v!=c.end();++v)
#define printA(a,l,r) for(int zzz49=l; zzz49!=r; zzz49++) cout << a[zzz49] << ((zzz49==r-1)?"\n":" ")

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pi;

int T,zz;

int main() {
  cin >> T;
  for (int zz=1;zz<=T;zz++) {
    int R,C,W;
    cin >> R >> C >> W;
    int res = R * (C / W) + W - 1;
    if (C % W) ++res;
    if (W==C) res = R + W - 1;
    cout << "Case #" << zz << ": " << res << endl;
  }
  return 0;
}
