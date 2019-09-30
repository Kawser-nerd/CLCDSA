#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;
using ull = unsigned long long;

int main() {
    int N;
    cin >> N;

    vector<int> a;
    for (int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    sort(a.rbegin(), a.rend());
    int Alice = 0, Bob = 0;
    for (int i = 0; i < N; ++i) {
        if (i % 2 == 0) {
            Alice += a[i];
        } else {
            Bob += a[i];
        }
    }
    cout << Alice - Bob << endl;
}