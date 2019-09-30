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

int t,n;
ld x,y,z,vx,vy,vz,wX,wY,wZ,X,Y,Z;

ld dist(ld x,ld y,ld z)
{
    return sqrt(x*x+y*y+z*z);
}

int main()
{
    freopen("q.in", "rt", stdin);
    freopen("q.out", "wt", stdout);
    cout.flags(ios::fixed);
    cout.precision(10);
    cin>>t;
    for(int T=0;T<t;T++)
    {
        cin>>n;
        x=0;
        y=0;
        z=0;
        vx=0;
        vy=0;
        vz=0;
        for(int i=0;i<n;i++)
        {
            cin>>X>>Y>>Z>>wX>>wY>>wZ;
            x+=X;
            y+=Y;
            z+=Z;
            vx+=wX;
            vy+=wY;
            vz+=wZ;
        }
        x/=n;
        y/=n;
        z/=n;
        vx/=n;
        vy/=n;
        vz/=n;
//        cout<<x<<" "<<y<<" "<<z<<"  "<<vx<<" "<<vy<<" "<<vz<<endl;        
        ld f=0,l=1e12;
        while(l-f>1e-10)
        {
            ld a=(2*f+l)/3;
            ld b=(f+2*l)/3;
            if (dist(x+a*vx,y+a*vy,z+a*vz)>dist(x+b*vx,y+b*vy,z+b*vz)) f=a; else l=b;
        }
        cout<<"Case #"<<T+1<<": ";
        cout<<dist(x+f*vx,y+f*vy,z+f*vz)<<" "<<f;
        cout<<endl;
    }
    return 0;
}
