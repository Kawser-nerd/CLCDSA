#include <iostream>
#include <string>
#include <vector>


using namespace std;

int main() {

    int N;
    cin >> N;
    vector<int> d(N);
    for (int i = 0; i < N; ++i) {
        cin >> d[i];
    }

    // ?????
    std::sort(d.begin(), d.end());
    d.erase(unique(d.begin(), d.end()), d.end());

    cout << d.size() << endl;
}