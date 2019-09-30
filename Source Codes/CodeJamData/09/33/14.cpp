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

int t,d[600][600],a[600],p,n;

int rec(int f,int l)
{
    if (d[f][l]>-1) return d[f][l];
    int ans=1000000000;
    for(int i=f+1;i<l;i++)
    {
        rec(f,i);
        rec(i,l);
        ans<?=a[l]-a[f]-2+d[f][i]+d[i][l];
//        cout<<f<<" "<<l<<":"<<endl;        
//        cout<<a[l]-a[f]-2<<" "<<d[f][i]<<" "<<d[i][l]<<endl;
    }
    if (ans==1000000000) ans=0;
    d[f][l]=ans;
    return ans;
}

int main()
{
    freopen("q.in", "rt", stdin);
    freopen("q.out", "wt", stdout);
    cout.flags(ios::fixed);
    cout.precision(2);
    cin>>t;
    for(int T=0;T<t;T++)
    {
        cin>>p>>n;
        a[0]=0;
        a[n+1]=p+1;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        n+=2;
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            d[i][j]=-1;
        }
        for(int i=0;i<n-1;i++)
        {
            d[i][i+1]=0;
        }
        cout<<"Case #"<<T+1<<": ";
        cout<<        rec(0,n-1);
        cout<<endl;
    }
    return 0;
}
