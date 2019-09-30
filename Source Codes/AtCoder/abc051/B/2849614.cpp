#include <iostream>

using namespace std;

int main() {
    int k, s;
    cin >> k >> s;
    
    int ret = 0;
    for (int i = 0; i <= k; i++) {
        if (i > s)  break;

        for (int j = 0; j <= k; j++) {
            if (i + j > s)  break;
            if (s - (i + j) <= k)   ret++;
        }
    }

    cout << ret << endl;

    return 0;
}