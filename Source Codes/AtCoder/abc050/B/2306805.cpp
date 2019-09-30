#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n,m,sum=0,x,y,sum1;;
    cin>>n;
    int a[n];
    for(int i=0 ; i<n ; i++)
    {
        cin>>a[i];
        sum+=a[i];
    }

    cin>>m;
    int b[m];

    for(int i=0 ; i<m ; i++)
    {
        sum1=sum;
        cin>>x;
        cin>>y;
        sum1=sum-a[x-1]+y;
        b[i]=sum1;

    }
     for(int i=0 ; i<m ; i++)
    {
         cout <<b[i]<<endl;
    }
    return 0;
}