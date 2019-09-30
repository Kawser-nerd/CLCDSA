#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>

using namespace std;

int main() {
    int a, b, k;
    cin >> a >> b >> k;
    
    for (int i = min(a, b); i >= 1; i--) {
        if (a % i == 0 && b % i == 0) {
            if (k == 1) {
                cout << i << endl;
                break;
            } else {
                k--;
            }
        }
    }
}