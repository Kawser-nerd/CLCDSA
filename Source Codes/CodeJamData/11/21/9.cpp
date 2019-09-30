#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <queue>
#include <string>
#include <iostream>
using namespace std;
#define pb push_back
#define all(x) (x).begin,(x).end()
#define mp make_pair
#define tr(i,x) for(typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)

void tst()
{
    int n;
    cin >> n;
    vector<string> in(n);
    for(int i=0;i<n;i++)
        cin >> in[i];
    vector<int> wins(n);
    vector<int> loses(n);

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(in[i][j]=='1')
                wins[i]++;
            else if(in[i][j]=='0')
                loses[i]++;
    vector<long double> owp(n);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            if(in[i][j]=='1')
                owp[i] += ((long double)wins[j])/(wins[j]+loses[j]-1);
            else if(in[i][j]=='0')
                owp[i] += ((long double)wins[j]-1)/(wins[j]+loses[j]-1);
        owp[i] /= (wins[i]+loses[i]);
    }

    vector<long double> oowp(n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            if(in[i][j] != '.')
                oowp[i] += owp[j];
        oowp[i] /= (wins[i]+loses[i]);
    }
    for(int i=0;i<n;i++)
    {
        cout << (0.25 * (long double)wins[i]/(wins[i]+loses[i]) + 0.5 * owp[i] + 0.25 * oowp[i]) << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    for(int i=1;i<=t;i++)
    {
        cout << "Case #" << i << ":\n";
        tst();
    }

}
