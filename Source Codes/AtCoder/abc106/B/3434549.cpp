#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    int result = 0;
    for (int n = 9; n <= N; n+=2) {
        int cnt = 2;
        for (int i = 2; i < n/2; i++) {
            if(n % i == 0) {
                cnt++;
            }
        }
        if (cnt == 8) {
            result++;
        }
    }
    cout << result << endl;
}