#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int64_t s, c;
    cin >> s >> c;

    int64_t k = min<int64_t>(s, c / 2LL);
    c -= k * 2LL;
    k += c / 4LL;
    cout << k << endl;
    return 0;
}