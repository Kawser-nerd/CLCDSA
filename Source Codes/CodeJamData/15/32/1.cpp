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
  cout << setprecision(12);
  cin >> T;
  for (int zz=1;zz<=T;zz++) {
    int K,L,S;
    cin >> K >> L >> S;
    string keys;
    cin >> keys;
    string word;
    cin >> word;
    int good = 1;
    for (char c : word) {
      int found = 0;
      for (char d : keys)
        if (c==d) found=1;
      if (found==0) good=0;
    }
    int index = 1;
    for (; index<=L; index++) {
      int good2 = 1;
      for (int i=index; i<L;i++)
        if (word[i]!=word[i-index])
          good2=0;
      if (good2==1)
        break;
    }
    int best = (S-L)/index+1;
    ld prob = 1;
    REP(i,L) {
      int cnt = 0;
      REP(j,K)
        if (word[i]==keys[j]) cnt++;
      prob *= cnt;
      prob /= K;
    }
    ld res = 0;
    if (good==1)
      res = best - prob*(S-L+1);

    cout << "Case #" << zz << ": " << res << endl;
  }
  return 0;
}
