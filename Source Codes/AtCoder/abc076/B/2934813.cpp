#include <iostream>
#include <cmath>

using namespace std;

int n, k;

int check(int x, int cnt) {

    if (cnt >= n) {
        return x;
    } else {
        cnt++;
        return min(check(x + k, cnt), check(x * 2, cnt));
    }
    return x;
}

int main()
{
    cin >> n >> k;
    cout << check(1, 0) << endl;
    return 0;
}