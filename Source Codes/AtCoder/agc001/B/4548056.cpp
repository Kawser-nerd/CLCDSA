#include <iostream>
#include <algorithm>

using namespace std;

long long N, X;

long long f(long long a, long long b)
{
    if(a >= b)
    {
        swap(a, b);
    }

    if(b % a != 0)
    {
        return 2 * (b / a) * a + f(a, b % a);
    }
    else
    {
        return 2 * b - a;
    }
}

int main()
{
    cin >> N >> X;
    cout << N + f(N - X, X) << endl;

    return 0;
}