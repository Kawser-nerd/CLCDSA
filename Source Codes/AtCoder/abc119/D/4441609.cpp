// Last Change: 03/03/2019 20:02:18.
#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

namespace NS {
void LoopUntilZeroInpput() {
  int hogegegege = 0;
  while (cin >> hogegegege && hogegegege != 0) {
  }
}
} // namespace NS

class Cal {
private:
  ll A, B, Q;
  vector<ll> s;
  vector<ll> t;

private:
  ll Know(const vector<ll>& first, const vector<ll>& second, const ll x) {
    ll ans, tmpAns;
    ans = tmpAns = INT64_MAX;

    auto fItr = lower_bound(first.begin(), first.end(), x);
    // cout << *fItr << " " << flush;

    // x??????????
    // x????????????
    if (fItr != first.end()) {
      tmpAns = *fItr - x;
      auto sItr = lower_bound(second.begin(), second.end(), *fItr);
      // cout << *sItr << " " << flush;
      //*fItr?second??????
      if (sItr == second.end()) {
        --sItr;
        tmpAns += *fItr - *sItr;
      }
      //*fItr?second???????(*fItr????second???)
      else if (sItr == second.begin()) {
        tmpAns += *sItr - *fItr;
      }
      //*fItr??????second?????
      else {
        auto prevItr = sItr;
        --prevItr;
        tmpAns += min(*sItr - *fItr, *fItr - *prevItr);
      }
      ans = tmpAns;
    }

    // x??????????
    // x????????????
    if (fItr != first.begin()) {
      --fItr;
      tmpAns = x - *fItr;
      //??????????????????????
      //???????????????????OK?
      if (tmpAns <= ans) {
        auto sItr = lower_bound(second.begin(), second.end(), *fItr);
        // cout << *sItr << " " << endl;
        if (sItr == second.end()) {
          --sItr;
          tmpAns += *fItr - *sItr;
        } else if (sItr == second.begin()) {
          tmpAns += *sItr - *fItr;
        } else {
          auto prevItr = sItr;
          --prevItr;
          tmpAns += min(*sItr - *fItr, *fItr - *prevItr);
        }
      }
      ans = min(ans, tmpAns);
    }
    return ans;
  }

  ll Solve(const ll x) {
    ll ans = INT64_MAX;

    //????????
    ans = Know(s, t, x);
    // cout << "  " << ans << endl;

    //???????
    ll tmpAns = Know(t, s, x);
    // cout << "  " << tmpAns << endl;
    ans = min(ans, tmpAns);

    // cout << "  " << tmpAns << endl;
    return ans;
  }

  void Output(ll ans) {
    cout << ans << '\n';
  }

public:
  Cal() {
    cin >> A >> B >> Q;
    s.resize(A);
    t.resize(B);
    for (int i = 0; i < A; ++i) {
      cin >> s[i];
    }
    for (int i = 0; i < B; ++i) {
      cin >> t[i];
    }
  }

  ll GetQ() {
    return Q;
  }

  void Main(ll x) {
    ll ans = Solve(x);
    Output(ans);
  }
};

int main() {
  unique_ptr<Cal> cal(new Cal());
  ll Q = cal->GetQ();
  ll x;
  for (int i = 0; i < Q; ++i) {
    cin >> x;
    cal->Main(x);
  }
  cout << flush;
  //NS::LoopUntilZeroInpput();
}