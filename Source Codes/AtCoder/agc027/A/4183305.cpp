#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int N, x;
    cin >> N >> x;
    vector<int>a(N);
    for (int &i:a) cin >> i;
    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (x >=a.at(i)) {
            ans++;
            x-=a.at(i);
        }
    }
    if (ans ==N&& x >0) ans--;
    cout << ans << endl;
    
    return 0;
}