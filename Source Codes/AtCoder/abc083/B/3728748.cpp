#include <iostream>

using namespace std;

int main(void)
{
    int N, A, B;
    cin >> N >> A >> B;

    int ans = 0;
    for(int i = 1; i <= N; ++i)
    {
        int sum = 0;
        int j = i;
        while(j / 10)
        {
            sum += j % 10;
            j /= 10;
        }
        sum += j;
        if((A <= sum) && (sum <= B))
        {
            ans += i;
        }
    }

    cout << ans << endl;

    return 0;
}