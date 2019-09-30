#include <iostream>

using namespace std;

int main() {

    int N, M;
    string name, kit;
    cin >> N >> M >> name >> kit;

    int cn['Z' + 1] = {0};
    int ck['Z' + 1] = {0};

    for (int i = 0; i < N; i++) cn[name[i]]++;
    for (int i = 0; i < M; i++) ck[kit[i]]++;

    int ans = 0;

    for (int i = 'A'; i <= 'Z'; i++) {
        if (cn[i] && ck[i]) {
            if (cn[i] % ck[i]) {
                ans = max(ans, cn[i] / ck[i] + 1);
            } else {
                ans = max(ans, cn[i] / ck[i]);
            }
        } else if (cn[i] && !ck[i]) {
            ans = 0;
            break;
        }
    }

    cout << (ans ? ans : -1) << endl;
}