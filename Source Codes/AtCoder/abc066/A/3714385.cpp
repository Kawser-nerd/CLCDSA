#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a, b, c; cin >> a >> b >> c;
    int min_price = 20000;
    min_price = min(min_price, a+b);
    min_price = min(min_price, a+c);
    min_price = min(min_price, b+c);
    cout << min_price << endl;

}