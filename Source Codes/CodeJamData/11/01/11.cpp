#include <iostream>
#include <algorithm>
using namespace std;

int tst()
{
    int n;
    cin >> n;
    int p[2] = {1,1};
    int t[2] = {0,0};

    for(int i=0;i<n;i++)
    {
        char c;
        int tar;
        cin >> c >> tar;
        bool who = c=='O';
        t[who] += abs(p[who]-tar)+1;
        p[who] = tar;
        t[who]= max(t[who],1+t[!who]);
    }
    return max(t[0],t[1]);

}
int main()
{
    int t;
    cin >> t;
    for(int i=1;i<=t;i++)
        cout << "Case #" << i << ": " << tst() << endl;

}
