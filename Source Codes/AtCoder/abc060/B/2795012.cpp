#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int a,b,c,k=INT_MAX;
    bool tf=0;
    cin>>a>>b>>c;
    int sum=a;
    while(sum<147483647)
    {
        if(sum%b!=c%b)
        {sum+=a;tf=false;}
        else {tf=true;break;}
    }
    if(tf)
    cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}