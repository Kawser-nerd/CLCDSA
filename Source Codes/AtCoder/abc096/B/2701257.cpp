#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);

    vector<int> num;
    num.resize(3, 0);
    int K;
    for(int i = 0; i < 3; i++){
        cin >> num[i];
    }
    cin >> K;

    sort(num.begin(), num.end());

    for(int i = 0; i < K; i++){
        num[2] *= 2;
    }

    int ans = num[0] + num[1] + num[2];
    cout << ans << "\n";

    return 0;
}