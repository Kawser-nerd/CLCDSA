#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

bool cmp(pair< pii, int> p1, pair< pii, int> p2) {
    return (p1.first.first * p2.first.second < p1.first.second * p2.first.first);
}

int main(void) {
    int T;
    cin >> T;
    for (int testNo = 1; testNo <= T; ++testNo ) { 
        int N;
        cin >> N;
        vector< pair<pii, int> > pl(N);
        for (int i = 0; i < N; ++i) {
            cin >> pl[i].first.first;
        }
        for (int i = 0; i < N; ++i) {
            cin >> pl[i].first.second;
        }
        for (int i = 0; i < N; ++i) {
            pl[i].second = i;
        }
        stable_sort(pl.begin(), pl.end(), cmp);
        cout << "Case #" << testNo << ":";
        for (int i = 0; i < N; ++i) {
            cout << " " << pl[i].second;
        }
        cout << endl;
    }
    return 0;
}
