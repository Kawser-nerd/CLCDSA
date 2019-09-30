#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;  cin >> n;
    vector<int> vc;

    bool evenState = true;
    int ret = 0;
    for (int i = 0; i < n; i++) {
        int a;  cin >> a;
        if (a % 2 == 1) {
            evenState = false;
            break;
        }
        vc.push_back(a);
    }

    while(evenState) {
        ret++;
        for (auto &e: vc) {
            e /= 2;
            if (e % 2 == 1) evenState = false;
       }
    }

    cout << ret << endl;

    return 0;
}