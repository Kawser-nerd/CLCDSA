#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int tst()
{

    int p;
    cin >> p;
    int P = (1<<p);
    vector<vector<long long> > c;
    for(int i=0;i<P;i++)
    {
        int x;
        cin >> x;
        vector<long long> s(x+1,0);
        while(s.size()<=p)
            s.push_back(1000000000);
        c.push_back(s);
    }
    for(;;)
    {
        if(c.size()==1)
            return c[0][0];
        reverse(c.begin(),c.end());
        vector<vector<long long> > c2;
        while(!c.empty())
        {
            int C;
            cin >> C;
            vector<long long> v1 = c.back();
            c.pop_back();
            vector<long long> v2 = c.back();
            c.pop_back();

            vector<long long> v(p+1,1000000000);
            for(int i=0;i<=p;i++)
                v[i] = min(v[i],v1[i]+v2[i]+C);
            for(int i=0;i<p;i++)
                v[i] = min(v[i],v1[i+1]+v2[i+1]);
            c2.push_back(v);
        }
        c = c2;
    }

}

int main()
{
    int t;
    cin >> t;
    for(int tt=1;tt<=t;tt++)
        cout << "Case #" << tt << ": " << tst() << endl;
}
