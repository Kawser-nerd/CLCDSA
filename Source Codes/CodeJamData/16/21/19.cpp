#include <iostream>
#include <string>
#include <map>
using namespace std;
int main()
{
    int t, ct;
    for (cin >> t, ct = 1; ct <= t; ct++)
    {
        map<char, int> M;
        string S;
        cin >> S;
        for (const auto c : S)
        {
            M[c] ++;
        }

        map<int, int> R;
        while (M['Z'] > 0)
        {
            M['Z'] --;
            M['E'] --;
            M['R'] --;
            M['O'] --;
            R[0] ++;
        }
        while (M['W'] > 0)
        {
            M['T'] --;
            M['W'] --;
            M['O'] --;
            R[2] ++;
        }
        while (M['U'] > 0)
        {
            M['F'] --;
            M['O'] --;
            M['U'] --;
            M['R'] --;
            R[4] ++;
        }
        while (M['X'] > 0)
        {
            M['S'] --;
            M['I'] --;
            M['X'] --;
            R[6] ++;
        }
        while (M['O'] > 0)
        {
            M['O'] --;
            M['N'] --;
            M['E'] --;
            R[1] ++;
        }
        while (M['G'] > 0)
        {
            M['E'] --;
            M['I'] --;
            M['G'] --;
            M['H'] --;
            M['T'] --;
            R[8] ++;
        }
        while (M['S'] > 0)
        {
            M['S'] --;
            M['E'] --;
            M['V'] --;
            M['E'] --;
            M['N'] --;
            R[7] ++;
        }
        while (M['F'] > 0)
        {
            M['F'] --;
            M['I'] --;
            M['V'] --;
            M['E'] --;
            R[5] ++;
        }
        while (M['T'] > 0)
        {
            M['T'] --;
            M['H'] --;
            M['R'] --;
            M['E'] --;
            M['E'] --;
            R[3] ++;
        }
        while (M['I'] > 0)
        {
            M['N'] --;
            M['I'] --;
            M['N'] --;
            M['E'] --;
            R[9] ++;
        }

        cout << "Case #" << ct << ": ";
        for (const auto x : R)
            for (int i = 0; i < x.second; i ++)
                cout << x.first;
        cout << endl;
    }
    return 0;
}
