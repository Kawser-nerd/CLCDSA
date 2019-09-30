#include <iostream>
using namespace std;
int main()
{
    int n; cin >> n;
    int sum = 1;
    while(n > 1)
    {
        n >>=1;
        sum <<=1;
    }
    cout << sum << endl;
}