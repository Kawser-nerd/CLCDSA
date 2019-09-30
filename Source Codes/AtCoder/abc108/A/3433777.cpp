#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int K;
    cin >> K;
    cout << (K / 2) * (K % 2 == 1 ? K / 2 + 1 : K / 2) << endl;
}