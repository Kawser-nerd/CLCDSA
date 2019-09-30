#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

typedef long long ll;

class TestCase {
    ll E, R;
    int N;
    vector<ll> v;
public:
    ll SubSolve(int left, int right, ll startingEnergy, ll endingEnergy) {
        if (right == left) {
            assert(startingEnergy >= endingEnergy);
            return 0;
        }
        int mid = max_element(v.begin() + left, v.begin() + right) - v.begin();
        ll en1 = min(startingEnergy + (mid - left) * R, E);
        ll en2 = max(endingEnergy - (right - mid) * R, 0LL);
        ll canUse = en1 - en2;
        return SubSolve(left, mid, startingEnergy, en1)
            + canUse * v[mid] + SubSolve(mid + 1, right, en2 + R, endingEnergy);
    }
    ll SolveTest() {
        cin >> E >> R >> N;
        v.resize(N);
        for (int i = 0; i < N; ++i) {
            cin >> v[i];
        }
        return SubSolve(0, N, E, 0);
    }
};

int main(void) {
    int T;
    cin >> T;
    for (int testNo = 1; testNo <= T; ++testNo) {
        TestCase testCase;
        cout << "Case #" << testNo << ": " << testCase.SolveTest() << endl;
    }
    return 0;
}