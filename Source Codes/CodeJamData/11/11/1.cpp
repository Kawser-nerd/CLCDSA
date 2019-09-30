#include <iostream>
using namespace std;

int t1, PD, PG;
long long N;

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

bool check()
{
    if (PG == 100 && PD != 100) return false;
    if (PG == 0 && PD != 0) return false;
    int x = gcd(PD, 100);
    if (N < 100 / x) return false;
    return true;
}

int main()
{
    freopen("a2.in", "r", stdin);
    freopen("a2.out", "w", stdout);
    
    cin >> t1;
    for (int t2 = 1; t2 <= t1; ++t2) {
        cin >> N >> PD >> PG;
        cout << "Case #" << t2 << ": " << (check() ? "Possible" : "Broken") << endl;
    }
    
    return 0;
}
