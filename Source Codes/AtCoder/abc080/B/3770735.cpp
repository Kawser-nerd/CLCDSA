#include <iostream>

using namespace std;

int main(void)
{
    int N;
    cin >> N;

    int fx = 0;
    int n = N;
    while(n / 10)
    {
        fx += (n % 10);
        n /= 10;
    }
    fx += n;

    cout << (N % fx ? "No" : "Yes") << endl;
    return 0;
}