#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    if (N % 10 >= 7) {
        N = (N / 10) * 10 + 10;
    }
    cout << N * 15 - (N / 10) * 50 << endl;
}