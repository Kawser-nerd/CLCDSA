#include <iostream>
#include <vector>
#include <map>

using namespace std;

int N, K;

map<int, int> a;

int main(){
    cin >> N >> K;

    for (int i = 0; i < N; ++i) {
        int ai;
        cin >> ai;
        if (a.find(ai) != a.end()) {
            a[ai]++;
        } else {
            a[ai] = 1;
        }
    }

    vector<int> v;

    for (auto itr = a.begin(); itr != a.end(); ++itr) {
        v.push_back((*itr).second);
    }

    sort(v.begin(), v.end());

    int ans = 0;
    for (int i = 0; i < (int)v.size() - K; ++i) {
        ans += v[i];
    }
    cout << ans << endl;
}