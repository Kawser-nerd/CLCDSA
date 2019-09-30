#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

long long N, A, B;

long long ans = 0;

int main()
{
    cin >> N >> A >> B;

    if((N == 1 && A != B) || A > B)
    {
        ans = 0;
    }
    else if(A == B)
    {
        ans = 1;
    }
    else
    {
        ans = 1 + (B - A) * (N - 2);
    }

    cout << ans << endl;    
    
    return 0;
}