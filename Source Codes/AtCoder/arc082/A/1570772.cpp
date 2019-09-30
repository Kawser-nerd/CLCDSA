#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    int b[100000] {0};
    for(int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        b[x]++;
    }

    int cmax = 0;
    for(int i = 0; i < 100000-2; i++) {
        cmax = max(cmax, b[i] + b[i+1] + b[i+2]);
    }
    cout << cmax << endl;

    return 0;
}