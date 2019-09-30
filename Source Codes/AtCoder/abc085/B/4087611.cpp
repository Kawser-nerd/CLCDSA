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
    set<int> d;
    for (int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;
        d.insert(tmp);
    }
    cout << d.size() << endl;
}