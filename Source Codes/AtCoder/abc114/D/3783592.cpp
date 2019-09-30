#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

vector<int> p;
int N;
map<int, int> comp;

void get_prime()
{
    for (int i = 2; i <= 100;i++)
    {
        bool f = true;
        for (int j = 2; j <= i / 2; j++)
        {
            if(i % j == 0)
            {
                f = false;
                break;
            }
        }
        if(f == true)
        {
            p.push_back(i);
        }
    }
}

void factoring()
{
    for (int i = 2; i <= N;i++)
    {
        int n = i;
        for (auto d = p.begin(); d != p.end();)
        {
            if(n % *d == 0)
            {
                if(comp.find(*d) == comp.end())
                {
                    comp.insert(make_pair(*d, 1));
                }
                else
                {
                    comp[*d]++;
                }
                n /= *d;
            }
            else
            {
                d++;
            }
        }
    }
}

int cnt(int n)
{
    int c = 0;
    for (auto i = comp.begin(); i != comp.end();i++)
    {
        if(i->second >= n)
        {
            c++;
        }
    }
    return c;
}

int main()
{
    cin >> N;
    get_prime();
    factoring();

    int ans = cnt(74) + cnt(24) * ( cnt(2) - 1) + cnt(14) * (cnt(4) - 1) + (cnt(4) * (cnt(4) - 1) * (cnt(2) - 2) / 2);

    cout << ans << endl;

    return 0;
}