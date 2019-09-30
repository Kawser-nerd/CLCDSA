#include <algorithm>
#include <iostream>
using namespace std;

int doit(int miss, int R, int C, int ncent, int ncorn) {
  int nedge = (R*C+1)/2 - ncent - ncorn;
  if (miss <= ncent) return 4*miss;
  if (miss <= ncent + nedge) return 4*ncent + 3*(miss-ncent);
  return 4*ncent + 3*nedge + 2*(miss-ncent-nedge);
}

main() {
  int T, N, R, C, prob=1;
  for (cin >> T; T--;) {
    cin >> R >> C >> N;
    if (R > C) swap(R, C);
    if (N <= R*C/2) {
      cout << "Case #" << prob++ << ": 0" << endl;
      continue;
    }
    int tot = (R-1)*C + (C-1)*R;
    int miss = R*C-N;
    if (R == 1) {
      cout << "Case #" << prob++ << ": " << tot-2*miss << endl;
      continue;
    }
    int ncent = ((R-2)*(C-2)+1)/2;
    int ncorn = 1 + (C%2) + (R%2) + ((C%2)==(R%2));
    int ret = tot - max(doit(miss, R, C, ncent, ncorn),
                        doit(miss, R, C, (R-2)*(C-2)-ncent, 4-ncorn));
    cout << "Case #" << prob++ << ": " << ret << endl;
  }
}
