#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;

    cout << min(n - x, x - 1) << endl;

    return 0;
}