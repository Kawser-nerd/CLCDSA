#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int tt=1; tt<=t; tt++)
    {
        int n, k;
        cin >> n >> k;
        int x = (1<<n) - 1;
        cout << "Case #" << tt << ": " << ((k & x) == x ? "ON" : "OFF") << endl;
    }
    return 0;
}
