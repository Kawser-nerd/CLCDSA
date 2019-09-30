#include <iostream>

using namespace std;

int main(void)
{
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    int ans = 0;
    for(int i = 0; i < 101; ++i)
    {
        if(((A <= i) && (i <= B)) && ((C <= i) && (i <= D)))
        {
            ans++;
        }
    }
    cout << max(ans-1, 0) << endl;
    return 0;
}