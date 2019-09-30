#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> a;
    a.resize(N, 0);
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int ans = abs(a[0] - a[a.size() - 1]);

    cout << ans << "\n";

    return 0;
}