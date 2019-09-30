#include <iostream>

using namespace std;

int main() {
    int n;  scanf("%d", &n);
    int k;  scanf("%d", &k);
    int x;  scanf("%d", &x);
    int y;  scanf("%d", &y);
    cout << (n * x) - (n - k < 0 ? 0 : n - k) * (x - y) << endl;
    return 0;
}