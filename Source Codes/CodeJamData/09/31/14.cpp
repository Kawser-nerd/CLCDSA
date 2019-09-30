#pragma comment(linker, "/STACK:16777216")
#include <algorithm> 
#include <cctype> 
#include <cmath> 
#include <cstdio> 
#include <cstdlib> 
#include <cstring> 
#include <deque> 
#include <iostream> 
#include <list> 
#include <map> 
#include <numeric> 
#include <queue> 
#include <set> 
#include <sstream> 
#include <stack> 
#include <string> 
#include <vector> 

using namespace std; 

template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }

#define bublic public
#define TynKogep TOPCODER 
#define clr(a); memset(a,0,sizeof(a));
#define pb push_back
#define sz size()  
#define ld long double
#define ll long long
#define istr istringstream

int t,u[300],z[300];
string s;

int main()
{
    freopen("q.in", "rt", stdin);
    freopen("q.out", "wt", stdout);
    cout.flags(ios::fixed);
    cout.precision(2);
    cin>>t;
        getline(cin,s);        
    for(int T=0;T<t;T++)
    {
        getline(cin,s);
        for(int i=0;i<300;i++)
        u[i]=-1;
        int lst=1;
        for(int i=0;i<s.sz;i++)
        {
            if (u[s[i]]==-1)
            {
                u[s[i]]=lst;
                if (lst==1) lst=0; else
                if (lst==0) lst=2; else lst++;
            }
            z[i]=u[s[i]];
        }
        if (lst<2) lst=2;
        ll ans=0,now=1;
        for(int i=s.sz-1;i>=0;i--)
        {
            ans+=z[i]*now;
            now*=lst;
        }
        cout<<"Case #"<<T+1<<": ";
        cout<<ans;
        cout<<endl;
    }
    return 0;
}
