#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;

    int v = 0, h = 0;
    int len = s.length();

    int E = std::count(s.begin(), s.end(), 'E');
    int W = std::count(s.begin(), s.end(), 'W');
    int S= std::count(s.begin(), s.end(), 'S');
    int N = std::count(s.begin(), s.end(), 'N');

    E = min(E, 1);
    W = min(W, 1);
    S = min(S, 1);
    N = min(N, 1);

    if (!(E ^ W) && !(S ^ N))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}