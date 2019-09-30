#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <string>

using namespace std;

int N;

int main()
{
    cin >> N;
    long long sum = 0;
    long long ans = 0;
    long long A;
    for (int i = 0; i < N; i++)
    {
        cin >> A;
        if(A != 0)
        {
            sum += A;
        }
        else
        {
            ans += sum / 2;
            sum = 0;
        }
    }

    ans += sum / 2;

    cout << ans << endl;

    return 0;
}