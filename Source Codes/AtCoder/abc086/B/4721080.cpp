#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    string a_s;
    string b_s;
    while (cin >> a_s >> b_s)
    {
        string c_s = a_s + b_s;
        double c = stoi(c_s);
        double c_root = sqrt(c);
        if (pow(floor(c_root), 2) == c)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }

        return 0;
    }
}