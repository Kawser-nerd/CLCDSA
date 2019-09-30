#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    int x,y;
    cin>>x>>y;
    int a,b,c;
    a=x+y;
    b=x*y;
    c=x-y;
    int maxx;
    maxx=max(a,max(b,c));
    cout<<maxx<<endl;
    return 0;
}