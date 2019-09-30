#include <iostream>

using namespace std;

int main()
{
    int x, a, b; cin >> x >> a >> b;
    if (b <= a) cout << "delicious" << endl;
    else if (b <= x + a)  cout << "safe" << endl;
    else             cout << "dangerous" << endl;
    return 0;
}