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
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define tr(i,x) for(typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)

int n,m;
vector<int> colors;
vector<vector<int> > vert;

int ans;

void parse(int low,int high,vector<pair<int,int> > E)
{
    vector<int> myV;
    int ind = low;
//    cout << "entr " << low << ' ' << high << endl;
    for(int i=0;i<E.size();)
    {
        vector<pair<int,int> > EE;
        int j = i+1;
        for(;j<E.size();j++)
            if(E[j].second<=E[i].second)
                EE.pb(E[j]);
            else
                break;
//        cout << "desc\n";
        for(;ind<=E[i].first;ind++)
            myV.pb(ind);
        parse(E[i].first,E[i].second,EE);
        ind = E[i].second;
//        cout << "ret\n";
        i = j;
    }
    for(;ind<=high;ind++)
        myV.pb(ind);
    vert.pb(myV);
    ans = min(ans,(int)myV.size());
}


void tst()
{
    vert.clear();
    cin >> n >> m;
    colors.clear();
    colors.resize(n,-1);
    vector<pair<int,int> > edges(m);
    for(int i=0;i<m;i++)
    {
        cin >> edges[i].first;
        edges[i].first--;
    }
    for(int i=0;i<m;i++)
    {
        cin >> edges[i].second;
        edges[i].second--;
    }

    for(int i=0;i<m;i++) edges[i].second *= -1;
    sort(all(edges));
    for(int i=0;i<m;i++) edges[i].second *= -1;

    ans = 1000000;
    parse(0,n-1,edges);

   colors[0] = 0;
   colors[n-1] = 1;

   for(int ind = vert.size()-1;ind>=0;ind--)
   {
       vector<int>& local = vert[ind];
       int a = colors[local[0]];
       int b = colors[local.back()];
       vector<int> cc;
       cc.pb(a);
       for(int k=0;k<ans;k++)
           if(k!=a && k!=b)
               cc.pb(k);
       int i;
       for(i=0;i<local.size();i++)
           if(i<cc.size())
           {
                colors[local[i]] = cc[i];
           }
           else
           {
               if((local.size()-i)%2)
                   colors[local[i]] = b;
               else
                   colors[local[i]] = a;
           }

//       cout << "listing\n";
//       for(int i=0;i<local.size();i++)
//           cout << local[i] << ' ' << colors[local[i]] << endl;
   }
   cout << ans << endl;
   for(int i=0;i<colors.size();i++)
       cout << colors[i]+1 << ' ';
   cout << endl;
}

int main()
{
    int t;
    cin >> t;
    for(int i=1;i<=t;i++)
    {
        cout << "Case #" << i << ": ";
        tst();
    }

}
