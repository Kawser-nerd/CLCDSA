#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    for (size_t i = 0; i <= N/4; i++) {
        for (size_t j = 0; j <= N/7; j++) {
            int p = 4*i + 7*j;
            if( N == p ) {
                cout << "Yes";
                return 0;
            }
        }
    }
    cout << "No";
}