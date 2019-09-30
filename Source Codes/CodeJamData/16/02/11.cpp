#include <iostream>
#include <cstdio>
#include <bitset>
using namespace std;
typedef long long ll;

int main()
{
    int nt;
    cin >> nt;
    for (int t=1; t<=nt; t++) {
        string s;
        cin >> s;
        char last = '/';
        int ngroup = 0;
        for (int i=0; i<(int)s.size(); i++) {
            if (s[i] != last)
                ngroup++;
            last = s[i];
        }
        int answer;
        if (last == '+')
            answer = ngroup-1;
        else
            answer = ngroup;
        printf("Case #%d: %d\n", t, answer);
    }
}
