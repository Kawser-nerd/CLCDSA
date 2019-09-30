#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int tst()
{
    int s;
    cin >> s;
    vector<vector<int> > t(2*s-1,vector<int>(2*s-1,-1));
    for(int i=0;i<s;i++)
        for(int j=0;j<=i;j++)
        {
//            cout << i << ' ' << s-1-i+2*j << endl;
            cin >> t[i][s-1-i+2*j];
        }
    for(int i=1;i<s;i++)
        for(int j=0;j<s-i;j++)
            cin >> t[i+s-1][i+2*j];

/*    for(int i=0;i<t.size();i++,cout<<endl)
        for(int j=0;j<t[i].size();j++)
            if(t[i][j]>=0)
                cout << t[i][j];
            else
                cout << '#';
*/
    int a1 = 1000000000;
    int a2 = 1000000000;

    for(int l=0;l<2*s-1;l++)
    {
        bool issym = true;
        for(int i=0;i<2*s-1;i++)
            for(int j=0;j<2*s-1;j++)
            {
                int ni = 2*l-i;
                int nj = j;
                if(ni<0 || nj<0 || ni>=2*s-1 || nj>=2*s-1)
                    continue;
                if(t[i][j]==-1 || t[ni][nj]==-1)
                    continue;
                if(t[i][j]!=t[ni][nj])
                    issym = false;
            }
        if(issym)
            a1 = min(a1,abs(s-1-l));
    }
    for(int l=0;l<2*s-1;l++)
    {
        bool issym = true;
        for(int i=0;i<2*s-1;i++)
            for(int j=0;j<2*s-1;j++)
            {
                int ni = i;
                int nj = 2*l-j;
                if(ni<0 || nj<0 || ni>=2*s-1 || nj>=2*s-1)
                    continue;
                if(t[i][j]==-1 || t[ni][nj]==-1)
                    continue;
                if(t[i][j]!=t[ni][nj])
                    issym = false;
            }
        if(issym)
            a2 = min(a2,abs(s-1-l));
    }

//    cout << a1 << endl;
//    cout << a2 << endl;

    int a = a1+a2;
    return (s+a)*(s+a)-s*s;
}
int main()
{
    int t;
    cin >> t;
    for(int tt=1;tt<=t;tt++)
        cout << "Case #" << tt << ": " << tst() << endl;
}
