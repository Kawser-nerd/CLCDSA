#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(void)
{
    string a, b;
    cin >> a >> b;
    int n = stoi(a + b);
    bool is_sq = false;
    for(int i = 0; i < 1000; ++i)
    {
        int p = pow(i, 2);
        if(n == p)
        {
            is_sq = true;
            break;
        }
        else if(n < p)
        {
            break;
        }
    }
    cout << (is_sq ? "Yes" : "No") << endl;
    return 0;
}