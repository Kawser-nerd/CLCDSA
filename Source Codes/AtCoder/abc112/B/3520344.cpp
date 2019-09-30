#include<iostream>
#include<string>
using namespace std;

int main() {
    int min = 1001;
    int n, t; cin >> n >> t;
    while (n--) {
        int ci, ti; cin >> ci >> ti;
        if (ti > t) continue;
        if (ci < min) min = ci;
    }
    cout << (min != 1001 ? to_string(min) : "TLE") << endl;

    return 0;
}