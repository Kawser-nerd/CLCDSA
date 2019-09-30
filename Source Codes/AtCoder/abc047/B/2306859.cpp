#include<iostream>
#include<cmath>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
    int w,h,n;
    cin>>w>>h>>n;
    int x,y,a;
    int lx=0,ly=0,bx=w,by=h;
    while(n--)
    {
        cin>>x>>y>>a;
        if(a==1)
            lx=max(lx,x);
        if(a==3)
            ly=max(ly,y);

        if(a==2)
            bx=min(bx,x);
        if(a==4)
            by=min(by,y);
    }
    cout<<max(0,bx-lx)*max(0,by-ly)<<endl;
    return 0;
}