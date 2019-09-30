#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int a, b, x;

    cin >> a >> b >> x;
    if(a > x){
        cout << "NO" << endl;
        return 0;
    }

    a + b >= x ? cout << "YES" << endl : cout << "NO" << endl;
}