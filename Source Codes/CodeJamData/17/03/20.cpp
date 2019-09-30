#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

typedef long long int lli;
typedef pair<lli, lli> ii;

int main() {
  int numCases;
  cin >> numCases;
  for (int testCase=1; testCase<=numCases; ++testCase) {
    cout << "Case #" << testCase << ": ";
    lli k, n;
    cin >> n >> k;
    queue<ii> segs;
    segs.push(ii(n, 1));
    lli fsz;
    while (true) {
      ii f = segs.front(); segs.pop();
      fsz = f.first;
      lli fnum = f.second;
      while (!segs.empty() && fsz == segs.front().first) {
        fnum += segs.front().second;
        segs.pop();
      }
      if (k <= fnum)
        break;
      k -= fnum;
      segs.push(ii(fsz/2, fnum));
      segs.push(ii((fsz-1)/2, fnum));
    }
    cout << fsz/2 << ' ' << (fsz-1)/2 << endl;
  }
}