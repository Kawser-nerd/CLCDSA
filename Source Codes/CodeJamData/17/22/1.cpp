#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>

using namespace std;
typedef long long ll;

ifstream fin ("B.in");
ofstream fout ("B.out");

string rval = "RBYGOV";
string imp = "IMPOSSIBLE";
int N;
int nx[6];
int px[3];

char ch[1100];

string get_sol()
{
    int tot = 0;
    for (int i = 0; i < 3; i++)
        tot += px[i];

    for (int i = 0; i < 3; i++)
        if (px[i] * 2 > tot)
            return "-";

    pair <int, char> v[3];
    for (int i = 0; i < 3; i++)
    {
        v[i].first = px[i];
        v[i].second = rval[i];
    }

    sort (v, v + 3);

    int cloc = 0;
    for (int i = 0; i < tot; i += 2)
    {
        while (!v[cloc].first)
            cloc++;
        ch[i] = v[cloc].second;
        v[cloc].first--;
    }

    for (int i = 1; i < tot; i += 2)
    {
        while (!v[cloc].first)
            cloc++;
        ch[i] = v[cloc].second;
        v[cloc].first--;
    }

    string res = "";
    for (int i = 0; i < tot; i++)
        res += ch[i];
    return res;
}

string run()
{
    fin >> N >> nx[0] >> nx[4] >> nx[2] >> nx[3] >> nx[1] >> nx[5]; // ROYGBV

    for (int i = 0; i < 3; i++)
    {
        if (nx[i] < nx[i+3])
            return imp;
        if (nx[i] > 0 && nx[i] == nx[i+3])
        {
            if (nx[i] + nx[i+3] != N)
                return imp;
            else
            {
                string res = "";
                for (int j = 0; j < nx[i]; j++)
                {
                    res += rval[i];
                    res += rval[i+3];
                }
                return res;
            }
        }
        else
        {
            px[i] = nx[i] - nx[i+3];
        }
    }

    string s = get_sol();
    if (s[0] == '-')
        return imp;

    bool bseen[3];
    for (int i = 0; i < 3; i++)
        bseen[i] = false;

    for (int i = 0; i < s.length(); i++)
    {
        fout << s[i];
        for (int j = 0; j < 3; j++)
        {
            if (!bseen[j] && s[i] == rval[j])
            {
                bseen[j] = true;
                for (int k = 0; k < nx[j+3]; k++)
                {
                    fout << rval[j+3];
                    fout << rval[j];
                }
            }
        }
    }
    return "";
}

int main()
{
    fout << fixed << setprecision(7);
    int T; fin >> T;
    for (int i = 1; i <= T; i++)
    {
        fout << "Case #" << i << ": ";
        fout << run();
        fout << "\n";
    }
}