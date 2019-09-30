//
// B - Template Matching
//

#include <iostream>
#include <vector>

using namespace std;

int main() {

    int N, M;
    vector<string> A;
    vector<string> B;

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        A.push_back(s);
    }

    for (int i = 0; i < M; i++) {
        string s;
        cin >> s;
        B.push_back(s);
    }

    //
    bool ans;

    for (int i = 0; i <= N - M; i++) {
        for (int j = 0; j <= N - M; j++) {
            ans = true;
            for (int k = 0; k < M; k++) {
                if (A[i + k].substr(j, M) == B[k]) {
                    ans &= true;
                } else {
                    ans = false;
                }
            }
            if (ans) goto outer;
        }
    }
    outer:

    cout << (ans ? "Yes" : "No") << endl;
}