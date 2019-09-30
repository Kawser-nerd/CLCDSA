#include <iostream>
#include <vector>

using namespace std;
using P = pair<int, int>;

int main() {
    int N;
    cin >> N;

    vector<P> A;

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        A.emplace_back(make_pair(a, i + 1));
    }

    sort(A.begin(), A.end(), greater<P>());

    for (auto a:A) {
        cout << a.second << endl;
    }
}