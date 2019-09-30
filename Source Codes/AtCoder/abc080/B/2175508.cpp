#include <iostream>
#include<cmath>
using namespace std;
int main()
{
    int n,N,f=0;
    cin>>n;
    N=n;
    for(int i=0;i<=10;i++)
    {
        f+=n%10;
        n=n/10;
    }
    if(N%f==0)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}