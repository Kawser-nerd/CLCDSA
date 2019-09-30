#include<iostream>
#include <string>
using namespace std;

int main() {
    int a, b, c, k;
    cin >> a >> b >> c >> k;
    int s, t;
    cin >> s >> t;
    int sum;
    sum = a * s + b * t;
    if (s+t >= k)
        sum -= c * (s+t);
    cout << sum << endl;
}