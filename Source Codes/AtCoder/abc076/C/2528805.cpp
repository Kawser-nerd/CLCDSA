#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

string s, t;
bool flag = false;


void Work()
{
    int lens = s.size();
    int lent = t.size();
    string ans(lens, 'z');

    for(int i = 0; i < lens; i++)
    {
        if(s[i] == '?' || s[i] == t[0])
        {
            string tmp = s;
            for(int j = 0; j < i; j++)
                if(tmp[j] == '?')
                    tmp[j] ='a';
            bool can = false;
            for(int j = 0; j < lent; j++)
            {

                if(tmp[i+j]!= '?' && tmp[i+j] != t[j])
                    break;
                tmp[i+j] = t[j];
                if(j == lent - 1) can = true;
            }
            if(can)
            {
                for(int j = i + lent; j < lens; j++) if(tmp[j] == '?') tmp[j] = 'a';
                if(tmp<ans)
                {
                    ans = tmp;
                    flag = true;
                }
            }
        }
    }
    if(!flag) cout << "UNRESTORABLE" << endl;
    else cout << ans << endl;
}
int main()
{
    cin >> s >> t;
    Work();
}