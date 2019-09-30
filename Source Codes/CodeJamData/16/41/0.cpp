#include <iostream>
#include <string>

using namespace std;

string concat(string a, string b)
{
    return a < b? a + b : b + a;
}

int count(string a, char b)
{
    int re = 0;
    for (int i = 0; i < a.size(); i++)
        re += (a[i] == b);
    return re;
}

int main()
{
    int t, ct;

    cin >> ct;
    for (t = 1; t <= ct; t ++)
    {
        int n, r1, p1, s1;
        cin >> n >> r1 >> p1 >> s1;

        string p, r, s;
        p = "P";
        r = "R";
        s = "S";
        for (int i = 1; i <= n; i ++)
        {
            string p2 = concat(p, r);
            string r2 = concat(r, s);
            string s2 = concat(p, s);
            p = p2;
            r = r2;
            s = s2;
        }

        cout << "Case #" << t << ": ";
        if (r1 == count(p, 'R') && p1 == count(p, 'P') && s1 == count(p, 'S'))
            cout << p;
        else if (r1 == count(r, 'R') && p1 == count(r, 'P') && s1 == count(r, 'S'))
            cout << r;
        else if (r1 == count(s, 'R') && p1 == count(s, 'P') && s1 == count(s, 'S'))
            cout << s;
        else
            cout << "IMPOSSIBLE";
        cout << endl;
    }

    return 0;
}
