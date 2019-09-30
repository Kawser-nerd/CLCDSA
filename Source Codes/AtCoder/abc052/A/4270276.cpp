#include <iostream>
using namespace std;
#include <string>
#include <algorithm>
#define ll long long
int main()
{
    ll a,b,c,d;
    ll area1,area2,area;
    cin>>a>>b>>c>>d;
    area1=a*b;
    area2=c*d;
    area=max(area1,area2);
    cout<<area;


    return 0;
}