#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    vector<int> v = {a, b, c};
    sort(v.begin(), v.end());
    cout << v.at(2) * 10 + v.at(1) + v.at(0) << endl;
}