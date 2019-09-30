//
// C - ?????
//

#include <iostream>
#include <vector>

using namespace std;

int main() {

    int sum = 0;
    vector<pair<int, int >> QQ[82];

    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            QQ[i * j].emplace_back(make_pair(i, j));
            sum += i * j;
        }
    }

    int N;
    cin >> N;

    for (auto qq : QQ[sum - N]) {
        cout << qq.first << " x " << qq.second << endl;
    }

}