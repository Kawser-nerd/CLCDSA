#include <iostream>

using namespace std;

int main()
{
    int n; cin >> n;
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (a % 2 != 0) cnt++;
    }
    if (cnt % 2 == 0) cout << "YES" << endl;
    else              cout << "NO" << endl;
    
    return 0;
}