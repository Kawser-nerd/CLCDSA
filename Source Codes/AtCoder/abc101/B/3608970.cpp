#include <iostream>

using namespace std;

int main(void)
{
    int N; cin >> N;

    int Sn = 0;
    int n = N;
    while(n / 10)
    {
        Sn += (n % 10);
        n /= 10;
    }
    Sn += n;

    cout << (N % Sn ? "No" : "Yes") << endl;

    return 0;
}