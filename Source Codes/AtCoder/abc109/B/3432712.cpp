#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int N;
    vector<string> W;
    cin >> N;
    for (size_t i = 0; i < N; i++) {
        string w;
        cin >> w;
        W.push_back(w);
    }

    for (size_t i = 0; i < W.size()-1; i++) {
        if(*(W[i].end()-1) != *W[i+1].begin()) {
            cout << "No" << endl;
            return 0;
        }
    }

    set<string> Wset(W.begin(), W.end());

    if(Wset.size() != N) {
        cout << "No";
    } else {
        cout << "Yes";
    }

}