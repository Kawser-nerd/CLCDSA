#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <fstream>

using namespace std;

#define REPEAT(i,a,b) for(int i=a;i<b;++i)
#define REP(i,n) REPEAT(i,0,n)
#define RREP(i,n) for(int i=n-1;i>=0;--i)
#define EACH(it,v) for(typeof(v.begin()) it=v.begin();it!=v.end();++it)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define CLEAR(x,with) memset(x,with,sizeof(x))
#define sz size()
#define mkp make_pair
typedef long long ll;
int main()
{
/*
        vector <long long int> ifair;

        ifair.pb(1);
        ifair.pb(4);
        ifair.pb(9);
        ifair.pb(121);
        ifair.pb(484);
        ifair.pb(10201);
        ifair.pb(12321);
        ifair.pb(14641);
        ifair.pb(40804);
        ifair.pb(44944);
        ifair.pb(1002001);
        ifair.pb(1234321);
        ifair.pb(4008004);
        ifair.pb(100020001);
        ifair.pb(102030201);
        ifair.pb(104060401);
        ifair.pb(121242121);
        ifair.pb(123454321);
        ifair.pb(125686521);
        ifair.pb(400080004);
        ifair.pb(404090404);
        ifair.pb(10000200001ll);
        ifair.pb(10221412201ll);
        ifair.pb(12102420121ll);
        ifair.pb(12345654321ll);
        ifair.pb(40000800004ll);
        ifair.pb(1000002000001ll);
        ifair.pb(1002003002001ll);
        ifair.pb(1004006004001ll);
        ifair.pb(1020304030201ll);
        ifair.pb(1022325232201ll);
        ifair.pb(1024348434201ll);
        ifair.pb(1210024200121ll);
        ifair.pb(1212225222121ll);
        ifair.pb(1214428244121ll);
        ifair.pb(1232346432321ll);
        ifair.pb(1234567654321ll);
        ifair.pb(4000008000004ll);
        ifair.pb(4004009004004ll);
        ifair.pb(100000020000001ll);
*/
        vector <string> ifair;
        string rp;
        ifstream infile("fair");
        //ifstream infile("fair")
        while(infile >> rp)
        {
                string append(100-rp.sz,'0');
                ifair.pb(append+rp);
        }

        int N;
        cin>>N;

        REPEAT(Case,1,N+1){
                cout<<"Case #"<<Case<<": ";
                //Code Starts Here
                string a,b;
                cin>>a>>b;
                if(a.sz<100){
                        string appA(100-a.sz,'0');
                        a=appA+a;
                }
                if(b.sz<100){
                        string appB(100-b.sz,'0');
                        b=appB+b;
                }
                int ans=0;
                REP(i,ifair.sz)
                {
                        if(ifair[i] >= a && ifair[i] <=b)
                                ans++;
                }
                cout<<ans;
                //Code ends Here
                cout<<endl;
        }
        return 0;
}
