#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    long long a, b;

    cin >> a >> b;

    string s;

    if(a <= 0 && 0 <= b)
    {
        s = "Zero";
    }
    else if(a >= 0 && b >= 0)
    {
        s = "Positive";
    }
    else
    {
        s = (b - a) % 2 == 0 ? "Negative" : "Positive";
    }

    cout << s << endl;

    return 0;
}