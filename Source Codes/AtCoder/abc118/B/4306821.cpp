//
// Created by Suganami Shuya on 2019-02-18.
//

#include <iostream>

using namespace std;

int main() {
    int n, m, tmp, token, cnt = 0;
    cin >> n >> m;
    int like[m];
    for (int i = 0; i < m; i++) {
        like[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        for (int j = 0; j < tmp; j++) {
            cin >> token;
            like[token - 1]++;
        }
    }
    for (int i = 0; i < m; i++) {
        if (like[i] == n) {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}