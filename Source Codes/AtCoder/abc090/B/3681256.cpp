#include <iostream>

using namespace std;

int main(void)
{
    int A, B;
    cin >> A >> B;

    int ans = 0;
    for(int i = A; i <= B; ++i)
    {
        int a = i / 100;
        int b = i % 1000;
        int c = ((a % 10) * 100) + ((a / 10) % 10 * 10) + (a / 100);
        if(b == c)
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}