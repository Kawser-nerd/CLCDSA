#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<string> s(N);
    int p[N];
    int total {0};
    string ans;
    
    for (int i = 0; i < N; i++) {
        cin >> s[i] >> p[i];
        total += p[i];
    }
    
    for (int j = 0; j < N; j++) {
        if (p[j] > (total / 2)) {
            ans = s[j];
            break;
        } else {
            ans = "atcoder";
        }
    }
    
    cout << ans << endl;
    return 0;
}